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
    NetHandler net;

    int myRole = InitPacket.TYPE_UNDEFINED;
    Board board;
    Point center;

    int w;

    RNGame(String title) {
       // super(title);
        net = new NetHandler(this);
        net.start();
       // setItemCommandListener(this);
        board = new Board(this);
        center = new Point(0,0);
        System.out.println("fooooo");
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
        System.out.println("foooooooooooooooo");
        //super.keyPressed(keyCode);
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
            // XXX do stuffz
        }
        
        //chat.setString(packet.toString());
    }

    protected void paint(Graphics g) {
         System.out.println(getWidth() + "," + getHeight());
         board.paint(g, new Point(0,0), getWidth(), getHeight());

    }

    public void commandAction(Command c, Displayable d) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
