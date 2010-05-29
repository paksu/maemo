package RN.net.packet;

abstract public class Packet {
    public static final int BUFFER_LENGTH = 9;

    /**
     * Generoi paketti-olion.
     * Packet-luokan toteuttavien luokkien tulee ylikirjoittaa tämä metodi.
     * @param buffer
     * @return packet
     * @throws Exception
     */
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

    /**
     * Serialisoija joka serialisoi Paketin tavujonoksi
     * @return
     */
    abstract public byte[] toBuffer();
}
