
package RN;

import javax.microedition.lcdui.Graphics;
class Piece {
    public static final char[] types = { 'o','x' };
    char type;

    public Piece(int newType) {
        type = types[newType];
    }

    void paint(Graphics g, int i, int j) {
        //g.drawRect(((i+10)*10)+1, ((j+10)*10)+1,8, 8);
        g.drawString(String.valueOf(type), (i+10)*10 +2, (j+10)*10-3, 0);
        /*
        try {
            throw new Exception("Piece::paint");
        } catch (Exception e) {
            e.printStackTrace();
        }*/
    }
}
