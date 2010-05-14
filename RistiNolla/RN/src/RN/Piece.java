
package RN;

import javax.microedition.lcdui.Graphics;

class Piece {
    int type;
    Point pos;
    public Piece(int newType) {
        type = newType;
    }

    void setPos(Point p) {
        pos = p;
    }
    Point getPos() {
        return pos;
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
