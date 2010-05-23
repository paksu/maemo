package RN;

import RN.net.packet.TurnPacket;
import RN.net.packet.InitPacket;
import RN.net.NetHandler;
import RN.net.packet.Packet;
import javax.microedition.lcdui.Canvas;
import javax.microedition.lcdui.Command;
import javax.microedition.lcdui.CommandListener;
import javax.microedition.lcdui.Displayable;
import javax.microedition.lcdui.Graphics;


public class RNGame extends Canvas implements CommandListener {

    public static final int PIECE_X = 0;
    public static final int PIECE_O = 1;
    public static final int STATE_INITIALIZING = 0; // waiting other player etc
    public static final int STATE_TURN = 1;         // own turn
    public static final int STATE_WAITING = 2;      // waiting for next turn
    public static final int STATE_GAMEOVER = 3;     



    NetHandler net;

    int myRole = InitPacket.TYPE_UNDEFINED;
    Board board;

    public Board getBoard() {
        return board;
    }

    Point center;
    int state;

    RNGame(String title) { }

    protected void keyPressed(int keyCode) {
        System.out.println(keyCode);
        switch(keyCode) {
            case -1: // UP
                center.y = new Integer(center.y.intValue() + 1);
                break;
            case -2: // DOWN
                center.y = new Integer(center.y.intValue() - 1);
                break;
            case -3: // LEFT
                center.x = new Integer(center.x.intValue() + 1);
               break;
            case -4: // RIGHT
                center.x = new Integer(center.x.intValue() - 1);
                break;
            case -5: // ENTER
                if(insertPiece(center, myRole)) {
                    state = RNGame.STATE_WAITING;
                    net.send(new TurnPacket(center));
                    if(board.getWinner() != -1) {
                        System.out.println("WINNER IS " + board.getWinner());
                        board.setText("You win");
                        state = RNGame.STATE_GAMEOVER;
                    }
                }
                break;
            default:
                break;
        }
        System.out.println(center.x + "," + center.y);

        repaint();
    }

    public void update(Packet arg) {
        System.out.println("Received " + arg);

        if (arg instanceof InitPacket) {
            InitPacket packet = (InitPacket)arg;
            myRole = packet.getType();
            if(myRole == RNGame.PIECE_O) {
                // zero starts
                state = RNGame.STATE_TURN;
                board.setText("Your Turn");
                repaint();
            } else if(myRole == RNGame.PIECE_X) {
                state = RNGame.STATE_WAITING;
                board.setText("Waiting for other player to insert his piece");
                repaint();
            }
        }

        if (arg instanceof TurnPacket) {
            if (myRole == InitPacket.TYPE_UNDEFINED) {
                // XXX alert error
                return;
            }
            TurnPacket packet = (TurnPacket)arg;
            Point point = new Point(packet.x, packet.y);
            int otherRole = 1 - myRole;
            insertPiece(point, otherRole);
            if(board.getWinner() != -1) {
                board.setText("You loose");
                state = RNGame.STATE_GAMEOVER;
            } else {
                state = RNGame.STATE_TURN;
                board.setText("Your turn");
            }
            repaint();
        }
        
        //chat.setString(packet.toString());
    }

    protected void paint(Graphics g) {
         // Paint a square board
         board.paint(g, center, getWidth(), getWidth());

    }

    public boolean insertPiece(Point p, int type) {
        System.out.println("Type is " + type + " myRole is " + myRole);
        if(myRole != InitPacket.TYPE_UNDEFINED && state == RNGame.STATE_TURN && type == myRole){
            board.setText("Waiting for other player to insert his piece");
            return board.set(p, new Piece(type));
        } else if(state == RNGame.STATE_WAITING && type != myRole) {
            board.setText("Your turn");
            return board.set(p, new Piece(type));
        } else if(state == RNGame.STATE_INITIALIZING && type != myRole) {
            board.setText("Your turn");
            return board.set(p, new Piece(type));
        } else {
            System.out.println("Error in insertPiece type:" + type + " and myRole:" + myRole + "and state" + state);
            return false;
        }
    }

    public void commandAction(Command c, Displayable d) { }

    void init() {
        net = new NetHandler(this);
        net.start();
        board = new Board(this);
        center = new Point(0,0);
        myRole = InitPacket.TYPE_UNDEFINED;
        state = RNGame.STATE_INITIALIZING;
        board.setText("Waiting for other player");
    }

    
}
