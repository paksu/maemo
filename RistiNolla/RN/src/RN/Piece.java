
package RN;

import javax.microedition.lcdui.Graphics;

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

    public Piece(int newType) {
        type = newType;
    }

    void paint(Graphics g, int i, int j) {
        g.drawRect(((i+10)*10)+1, ((j+10)*10)+1,8, 8);
        try {
            throw new Exception("Piece::paint");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
