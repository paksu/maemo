/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package RN.net.packet;

import java.io.ByteArrayInputStream;
import java.io.DataInputStream;
import java.io.IOException;

/**
 *
 * @author keras
 */
public class TurnPacket extends Packet {
    public int x, y;

    public TurnPacket(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public static Packet fromBuffer(byte[] buffer) {
        int x = 0;
        int y = 0;
        ByteArrayInputStream bin = new ByteArrayInputStream(buffer, 1, 8);
        DataInputStream      din = new DataInputStream(bin);

        try {
            x = din.readInt();
            y = din.readInt();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
        return new TurnPacket(x, y);
    }
    public String toString() {
        return "RNTurnPacket: [x: " + x + ", y: " + y + "]";
    }

}
