package RN.net.packet;

abstract public class Packet {
    public static final int BUFFER_LENGTH = 9;
    public static Packet fromBuffer(byte[] buffer) throws Exception {
        int type = 0xff & buffer[0];
        Packet result = null;
        switch (type) {
            case 0:
                result = InitPacket.fromBufer(buffer);
                break;
            case 1:
                result = TurnPacket.fromBuffer(buffer);
                break;
        }
        return result;
    }

    abstract public byte[] toBuffer();
}
