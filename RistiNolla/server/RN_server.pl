#!/usr/bin/perl

use warnings;
use strict;

use lib "$ENV{HOME}/lib";

use POE;
use POE::Wheel::SocketFactory;
use POE::Wheel::ReadWrite;
use POE::Driver::SysRW;
use POE::Component::SSLify;

use Data::Dumper;


POE::Session->create(
    inline_states => {
        _start      => \&start,
        factory_success => \&factory_success,
        client_input  => \&client_input,
        client_error  => \&cleanup, 
        fatal_error   => \&cleanup,
        _stop       => sub {},
    },
);

exit POE::Kernel->run();





sub start {
    $_[HEAP]->{factory} =
        POE::Wheel::SocketFactory->new(
            BindAddress    => '0.0.0.0',
            BindPort       => '1234',
            SuccessEvent   => 'factory_success',
            FailureEvent   => 'fatal_error',
            SocketProtocol => 'tcp',
            Reuse          => 'on',
        );
}

sub factory_success {
    my $handle = $_[ARG0];

    my $wheel =
        POE::Wheel::ReadWrite->new(
            Handle     => $handle,
            Driver     => POE::Driver::SysRW->new(),
            InputEvent => 'client_input',
            ErrorEvent => 'client_error',
            Filter     => POE::Filter::RNFilter->new(),
        );
    $_[HEAP]->{clients}->{ $wheel->ID } = $wheel;
    $_[HEAP]->{free_clients} ||= [];


    my $fc = $_[HEAP]->{free_clients};
    push @$fc, $wheel;

    my $count = @$fc;

    if ($count > 1) {
        my @clients = splice(@$fc, 0, 2);

        my $new_game = RNGame->new(clients => \@clients);

        $_[HEAP]->{games}->{ $new_game->ID } = $new_game;
        
        for (@clients) {
            $_[HEAP]->{games_by_client}->{ $_->ID } = $new_game;
        }
    }
}

sub client_input {
    my ($input, $wheel_id) = @_[ARG0, ARG1];

    print( (map{sprintf "%x", ord($_)} split//, $input), "\n" );

    if (my $game = $_[HEAP]->{games_by_client}->{ $wheel_id }) {
	my @other_clients = (
	    grep { $_->ID != $wheel_id }
	    @{$game->{clients}}
        );

	for my $client (@other_clients) {
	    $_[HEAP]->{clients}->{ $client->ID }->put( $input );
	}
    }
}

sub cleanup {
    my $wheel_id = $_[ARG3];

    delete $_[HEAP]->{clients}->{ $wheel_id };
    my $game = $_[HEAP]->{games_by_client}->{ $wheel_id };
    my %deleted;
    if ($game) {
        for my $c (@{$game->{clients}}) {
            $deleted{ $c->ID } = 1;
            delete $_[HEAP]->{games_by_client}->{ $c->ID };
        }
        delete $_[HEAP]->{games}->{ $game->ID };
    }

    my $fc = $_[HEAP]->{free_clients};
    FC_LOOP: for my $n (0 .. @$fc) {
        if ( $fc->[$n] and $deleted{ $fc->[$n] } ) {
            splice(@{$fc->[$n]}, 1, 1);
            last FC_LOOP;
        }
    }
}


package RNGame;

use Data::Dumper;

sub new {
    my $class = shift;
    my $self = bless {@_}, $class;

    my @packet = (0) x 9;
    my $n = 0;
    for my $c (@{$self->{clients}}) {
        $packet[1] = $n++;
        $c->put(pack 'C*', @packet);
    }
    return $self;
}

sub ID {
    my ($self) = @_;
    return join ':', @{$self->{clients}};
}



package POE::Filter::RNFilter;
# slices incomming stuff into 9 byte chunks
# sends data out as is
sub new { 
    my $class = shift;
    my $self = bless {}, $class;
    $self->{queue} = '';
    return $self;
}

sub get {
    my ($self, $buffer) = @_;
    my @chunks;

    for my $record (@$buffer) {
        $self->{queue} .= $record;
        while (length $self->{queue} >= 9) {
            push @chunks, substr($self->{queue}, 0, 9);
            substr($self->{queue}, 0, 9) = '';
        }
    }
    return \@chunks;
}

sub put {
    my ($self, $records) = @_;

    return $records;
}
