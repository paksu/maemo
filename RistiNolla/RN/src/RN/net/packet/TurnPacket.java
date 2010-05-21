/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package RN.net.packet;

import RN.Point;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

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

    public TurnPacket(Point center) {
        x = center.x.intValue();
        y = center.y.intValue();
    }
    public String toString() {
        return "RNTurnPacket: [x: " + x + ", y: " + y + "]";
    }

    public byte[] toBuffer() {
        byte[] buffer = new byte[9];
        buffer[0] = 1;
        ByteArrayOutputStream bos = new ByteArrayOutputStream(9);
        DataOutputStream      dos = new DataOutputStream(bos);
        try {
            dos.writeByte(1);
            dos.writeInt(x);
            dos.writeInt(y);
        } catch (IOException ex) {
            ex.printStackTrace();
        }
        return bos.toByteArray();
    }

}
