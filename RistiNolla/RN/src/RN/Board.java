package RN;

import java.util.Enumeration;
import java.util.Hashtable;
import javax.microedition.lcdui.Graphics;

public class Board {
    private Hashtable table = new Hashtable();
    private RNGame parent;
    private Point cursor;
    private String text;
    /**
     * Constructor for Board
     *
     * @param game Parent RNGame needed for this class so it can some data needed for drawing
     */
    public Board(RNGame game) {
        parent = game;
        cursor = new Point(0,0);
        text = "";
    }
    /**
     * Insert a new piece on the board
     *
     * @param p Cordinates of the pice
     * @param piece Piece to insert to the given cordinates
     * @return Returns true if insert is successful, else false
     */
    public boolean set(Point p, Piece piece) {
        piece.setPos(new Point(p));
        if(table.containsKey(p.x)) {
            Hashtable row = (Hashtable) table.get(p.x);
            if(row.containsKey(p.y)) {
                System.out.println("There is already a piece in " + p.x + "," + p.y +"\n");
                return false;
            } else {
                System.out.println("Inserting piece " + piece.toString() + " to "  + p.x + "," + p.y +"\n");
                row.put(p.y, piece);
            }
        } else {
            table.put(p.x, new Hashtable());
            Hashtable row = (Hashtable) table.get(p.x);
            System.out.println("Inserting piece " + piece.toString() + " to "  + p.x + "," + p.y +"\n");
            row.put(p.y, piece);
        }
        return true;
    }
    /**
     * Method to determine if someone has won the game
     * 
     * @return Return -1 if a winner is not found, otherwise return winner
     */
    public int getWinner() {
        for (Enumeration en1 = table.elements(); en1.hasMoreElements();) {
            Hashtable h = (Hashtable) en1.nextElement();
            for (Enumeration en2 = h.elements(); en2.hasMoreElements();) {
                Piece piece = (Piece)en2.nextElement();

                Point pos   = piece.getPos();
                int type    = piece.getType();
                for (int dir = 0; dir < 4; dir++) {
                    for (int i = 1; i < 5; i++) {
                        Point matchPos = null;
                        switch (dir) {
                            case 0:
                                matchPos = new Point(pos.x.intValue() + i, pos.y.intValue());
                                break;
                            case 1:
                                matchPos = new Point(pos.x.intValue(), pos.y.intValue() + i);
                                break;
                            case 2:
                                matchPos = new Point(pos.x.intValue() + i, pos.y.intValue() + i);
                                break;
                            case 3:
                                matchPos = new Point(pos.x.intValue() + i, pos.y.intValue() - i);
                                break;
                        }

                        Piece matchPiece = get(matchPos);
                        if (matchPiece == null) {
                            break;
                        }
                        int matchType = matchPiece.getType();
                        if (matchType != type) {
                            break;
                        }
                        if (i == 4) {
                            return piece.getType();
                        }
                    }
                }
            }
        }
        return -1;
    }

    /**
     * Paints the board and calls each piece on the board to draw itself
     *
     * @param g Handle to the drawing object
     * @param center Cordinates to the point which the player has centered his view on i.e. the cordinates of the cursor
     * @param w Width of the grid
     * @param h Height of the grid
     */

    void paint(Graphics g, Point center, int w, int h) {
        // clear screen
        g.setColor(255,255,255);
        g.fillRect(0, 0, parent.getWidth(), parent.getHeight());


        // draw grid
        g.setColor(0,0,0);
        int i, j;
        
        for(i = 0;i <= w;i += 10) {
            g.drawLine(i, 0, i, h);
            g.drawLine(0, i, w, i);
        }

        //draw Pieces
        for(i = center.x.intValue() - 10;i < center.x.intValue() + 10;i++) {
            for(j = center.y.intValue() - 10;j < center.y.intValue() + 10;j++) {
                Piece p = get(i,j);
                if(p != null) {
                    p.paint(g, center.x.intValue() - i, center.y.intValue() - j);
                }
            }
           
        }
        //draw cursor at the center of the screen
        g.drawRect( (cursor.x.intValue() + 10)*10 +1, (cursor.y.intValue() + 10)*10 + 1, 8, 8);

        //draw text
        g.drawString(text, 10, h + 10, 0);
    }

    /**
     *
     * Get a piece on a specific location
     * @param x X-cordinate of the grid
     * @param y Y-cordinate of the gid
     *
     * @return Returns the Piece at the given location if there is one, else returns null
     */
    public Piece get(int x, int y) {
        if(table.containsKey(new Integer(x))) {
            Hashtable row = (Hashtable) table.get(new Integer(x));
            if(row.containsKey(new Integer(y))) {
                return (Piece) row.get(new Integer(y));
            }

        }
        return null;
    }

    /**
     * Set a string on the bottom of the screen
     * 
     * @param s String to show
     */
    public void setText(String s){
        text = s;
    }
    /**
     * Clear the text from the bottom of the screen
     */
    public void clearText(){
        text = "";
    }

    /**
     *
     * Get a piece on a specific location
     * @param p The cordinates on the grid. 
     *
     * @return Returns the Piece at the given location if there is one, else returns null
     */
    public Piece get(Point p) {
        return get(p.x.intValue(), p.y.intValue());
    }
}
