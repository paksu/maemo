package RN;

import java.util.Enumeration;
import java.util.Hashtable;
import javax.microedition.lcdui.Command;
import javax.microedition.lcdui.Graphics;

public class Board {
    private Hashtable table = new Hashtable();
    private RNGame parent;
    private Point cursor;
    private String text;

    public Board(RNGame game) {
        parent = game;
        cursor = new Point(0,0);
        text = "";
    }

    public void set(Point p, Piece piece) {
        piece.setPos(new Point(p));
        if(table.containsKey(p.x)) {
            Hashtable row = (Hashtable) table.get(p.x);
            if(row.containsKey(p.y)) {
                System.out.println("There is already a piece in " + p.x + "," + p.y +"\n");
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
    }

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

    public boolean gameOver() {
        return false;
    }

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

    public Piece get(int x, int y) {
        if(table.containsKey(new Integer(x))) {
            Hashtable row = (Hashtable) table.get(new Integer(x));
            if(row.containsKey(new Integer(y))) {
                return (Piece) row.get(new Integer(y));
            }

        }
        return null;
    }

    public void moveCursor(Command c) {

    }
    
    public void setText(String s){
        text = s;
    }
    public void clearText(){
        text = "";
    }

    public Piece get(Point p) {
        return get(p.x.intValue(), p.y.intValue());
    }
}
