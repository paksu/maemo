package RN.net.packet;

public class InitPacket extends Packet {
    public static final int TYPE_UNDEFINED = -1;
    public static final int TYPE_O = 0;
    public static final int TYPE_X = 1;
    private int type = TYPE_UNDEFINED;

    protected InitPacket(int type) throws Exception {
        switch(type) {
            case TYPE_X:
                this.type = TYPE_X;
                break;
            case TYPE_O:
                this.type = TYPE_O;
                break;
            default:
                throw new Exception("Wrong type");
        }
        System.out.println("new init " + this.type);
    }

    public int getType() {
        return type;
    }

    public String toString() {
        return "InitPacket: [type: " + type + " : " +
                (type == TYPE_X ? "TYPE_X" :
                 type == TYPE_O ? "TYPE_O" : "TYPE_UNDEFINED") +
                "]";
    }


    static Packet fromBufer(byte[] buffer) throws Exception {
        return new InitPacket(0xff & buffer[1]);
    }

    public byte[] toBuffer() {
        throw new UnsupportedOperationException("Not supported yet.");
    }
}
