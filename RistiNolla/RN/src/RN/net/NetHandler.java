package RN.net;

import RN.RNGame;
import RN.net.packet.Packet;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import javax.microedition.io.Connector;
import javax.microedition.io.SocketConnection;

public class NetHandler implements Runnable {
    public static final String serverAddr = "socket://potti.ath.cx:1234";
    
    private SocketConnection conn;
    private InputStream input;
    private OutputStream output;
    private RNGame parent;
    private Thread thread;
    private long startTime;
    private boolean running;

    public NetHandler(RNGame parent) {
        this.parent = parent;
    }

    public void start() {
        thread = new Thread(this);
        thread.start();
        startTime = System.currentTimeMillis();
        running = true;
    }

    public void stop() {
        running = false;
        thread = null;
    }

    public boolean send(Packet p) {
        try {
            output.write(p.toBuffer());
        } catch (IOException ex) {
            ex.printStackTrace();
            parent.getBoard().setText("ERROR: can't send packet");
            return false;
        }
        return true;
    }

    public void run() {
        try {
            conn = (SocketConnection) Connector.open(serverAddr);
            input = conn.openDataInputStream();
            output = conn.openDataOutputStream();
        } catch (IOException ex) {
            ex.printStackTrace();
            parent.getBoard().setText("ERROR: " + ex.getMessage());
            return;
        }

        final int BUFFER_LENGTH = 32;
        byte[] buffer = new byte[BUFFER_LENGTH];
        int offset = 0;
        while (running) {
           
            if (offset < Packet.BUFFER_LENGTH) {
                try {
                    int len = input.read(buffer, offset, BUFFER_LENGTH - offset);
                    if (len == -1) {
                        throw new IOException("Connection closed");
                    }
                    offset += len;
                } catch (IOException ex) {
                    ex.printStackTrace();
                    parent.getBoard().setText("ERROR: " + ex.getMessage());
                    return;
                }
            }
            else {
                Packet p;
                try {
                    p = Packet.fromBuffer(buffer);
                } catch (Exception ex) {
                    ex.printStackTrace();
                    parent.getBoard().setText("ERROR: " + ex.getMessage());
                    return;
                }
                System.arraycopy(buffer, Packet.BUFFER_LENGTH,
                                 buffer, 0, Packet.BUFFER_LENGTH);
                offset -= Packet.BUFFER_LENGTH;

                parent.update(p);
            }

        }

        try {
            System.out.println("close()");
            conn.close();
        } catch (IOException ex) { }
    }

}
