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
import javax.microedition.lcdui.Item;


public class RNGame extends Canvas implements CommandListener {

    public static final int PIECE_X = 0;
    public static final int PIECE_O = 1;
    public static final int STATE_INITIALIZING = 0; // waiting other player etc
    public static final int STATE_TURN = 1;         // own turn
    public static final int STATE_WAITING = 2;      // waiting for next turn



    NetHandler net;

    int myRole = InitPacket.TYPE_UNDEFINED;
    Board board;
    Point center;
    int state;

    RNGame(String title) {
       // super(title);
        net = new NetHandler(this);
        net.start();
        setCommandListener(this);
        board = new Board(this);
        center = new Point(0,0);
        System.out.println("fooooo");
        myRole = InitPacket.TYPE_X;
        state = RNGame.STATE_INITIALIZING;
    }

    protected int getMinContentWidth() {
        return 221;
    }

    protected int getMinContentHeight() {
        return 221;
    }

    protected int getPrefContentWidth(int height) {
        return 221;
    }

    protected int getPrefContentHeight(int width) {
        return 221;
    }

    protected void keyPressed(int keyCode) {
        System.out.println(keyCode);
        switch(keyCode) {
            case -1: // UP
                center.y = new Integer(center.y.intValue() + 1);
                board.setText("up");
                break;
            case -2: // DOWN
                center.y = new Integer(center.y.intValue() - 1);
                board.setText("down");
                break;
            case -3: // LEFT
                center.x = new Integer(center.x.intValue() + 1);
                board.setText("left");
                break;
            case -4: // RIGHT
                center.x = new Integer(center.x.intValue() - 1);
                board.setText("right");
                break;
            case -5: // ENTER
                insertPiece(center);
                net.send(new TurnPacket(center));
                if(board.getWinner() != -1) {
                    System.out.println("WINNER IS " + board.getWinner());
                }
                break;
            default:
                break;
        }
        System.out.println(center.x + "," + center.y);

        repaint();
    }

    public void commandAction(Command c, Item item) {
        // move cursor in grid and send answer over net
    }

    public void setCenter(Point newCenter) {

    }

    public void update(Packet arg) {
        System.out.println("Received " + arg);

        if (arg instanceof InitPacket) {
            InitPacket packet = (InitPacket)arg;
            myRole = packet.getType();
        }

        if (arg instanceof TurnPacket) {
            if (myRole == InitPacket.TYPE_UNDEFINED) {
                // XXX alert error
                return;
            }
            TurnPacket packet = (TurnPacket)arg;
            Point point = new Point(packet.x, packet.y);
            insertPiece(point);
            // XXX do stuffz
        }
        
        //chat.setString(packet.toString());
    }

    protected void paint(Graphics g) {
         // Paint a square board
         board.paint(g, center, getWidth(), getWidth());

    }

    public void commandAction(Command c, Displayable d) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public boolean insertPiece(Point p) {
        if(myRole != InitPacket.TYPE_UNDEFINED || state != RNGame.STATE_TURN){
            Piece piece = new Piece(myRole);
            return board.set(p, piece);
        } else {
            System.out.println("Error in insertPiece myRole:" + myRole + "and state" + state);
            return false;
        }
    }
    
}
