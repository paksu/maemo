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

    /**
     * Allowed types of pieces [0,1]
     */
    public static final int PIECE_X = 0;
    public static final int PIECE_O = 1;


    /**
     * Allowed states of the game [0,3] 
     */
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
    /**
     * Handles commands from the user and reacts to them accordingly. Always calls repaint() method inherited from the Canvas-class. If new piece is set inserts it to the Board-object and sends a Turn packet.
     *
     * @param keyCode the keycode of the button pressed
     */

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
    /**
     * Called from NetHandler
     *
     * @param arg The packet from NetHandler
     */
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

    /**
     * Calls the paint method from board to redraw the whole board
     *
     * @param g Handle to graphics object
     */
    protected void paint(Graphics g) {
         // Paint a square board
         board.paint(g, center, getWidth(), getWidth());

    }

    /**
     * Handles the logic of inserting piece according to the current game state and board state. May be called from keyPressed when user tries to insert a new piece or from update when a turn packet is recieved.
     *
     * @param p Cordinates where the piece is supposed to be insterted
     * @param type Type of the piece.
     *
     * @return returns True if insert is successful, else false
     */
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

    /**
     * Unused
     */
    public void commandAction(Command c, Displayable d) { }

    /**
     * Initializes a new game to be ready for an Init packet
     */
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
