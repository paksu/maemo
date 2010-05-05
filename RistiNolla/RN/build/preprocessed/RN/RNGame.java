package RN;

import RN.net.packet.TurnPacket;
import RN.net.packet.InitPacket;
import RN.net.NetHandler;
import RN.net.packet.Packet;
import javax.microedition.lcdui.Command;
import javax.microedition.lcdui.CustomItem;
import javax.microedition.lcdui.Graphics;
import javax.microedition.lcdui.Item;
import javax.microedition.lcdui.ItemCommandListener;
import javax.microedition.lcdui.TextField;

public class RNGame extends CustomItem implements ItemCommandListener {
    TextField chat;
    NetHandler net;

    int myRole = InitPacket.TYPE_UNDEFINED;

    int w;

    RNGame(String title, TextField debugField) {
        super(title);
        chat = debugField;
        net = new NetHandler(this);
        net.start();
        setItemCommandListener(this);
    }

    protected int getMinContentWidth() {
        return 50;
    }

    protected int getMinContentHeight() {
        return 50;
    }

    protected int getPrefContentWidth(int height) {
        return 80;
    }

    protected int getPrefContentHeight(int width) {
        return 80;
    }

    protected void paint(Graphics g, int w, int h) {
        // paint grid
    }

    public void commandAction(Command c, Item item) {
        // move cursor in grid and send answer over net
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
    
}
