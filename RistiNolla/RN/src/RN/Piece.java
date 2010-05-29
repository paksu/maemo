
package RN;

import javax.microedition.lcdui.Graphics;
class Piece {
    public static final String[] types = { "o","x" };
    int type;
    Point pos;
    /**
     * Create a new piece with the given type
     *
     * @param newType Type of the piece [0,1]
     * @return new Piece with the given type
     */
    public Piece(int newType) {
        type = newType;
    }

    /**
     * Set piece position
     *
     * @param p New cordinates on the grid
     */
    public void setPos(Point p) {
        pos = p;
    }
    /**
     * Get piece position
     *
     * @return returns Point object with piece locations
     */
    public Point getPos() {
        return pos;
    }
    /**
     * Get piece type
     *
     * @return Returns type of the Piece
     */
    public int getType() {
        return type;
    }

    /**
     * Draw piece with its mark [o,x] to the given cordinates on screen
     *
     * @param g Handle to the graphics object
     * @param i X cordinate on the screen
     * @param j Y cordinate on the screen
     */

    void paint(Graphics g, int i, int j) {
        // Stupid adjustments to get the piece to the center of the box
        g.drawString(types[type], (i + 10)*10 +2, (j + 10)*10-3, 0);
    }
}
