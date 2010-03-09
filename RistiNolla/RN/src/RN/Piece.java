
package RN;

import javax.microedition.lcdui.Graphics;
class Piece {
    public static final String[] types = { "o","x" };
    int type;
    Point pos;

    public Piece(int newType) {
        type = newType;
    }

    public void setPos(Point p) {
        pos = p;
    }
    public Point getPos() {
        return pos;
    }
    public int getType() {
        return type;
    }

    void paint(Graphics g, int i, int j) {
        g.drawString(types[type] , (i+10)*10 +2, (j+10)*10-3, 0);
    }
}
