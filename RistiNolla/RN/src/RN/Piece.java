
package RN;

class Piece {
    byte type;
    Point pos;
    public Piece(byte newType) {
        type = newType;
    }

    void setPos(Point p) {
        pos = p;
    }
    Point getPos() {
        return pos;
    }
}
