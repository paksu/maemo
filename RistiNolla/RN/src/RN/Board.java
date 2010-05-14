package RN;

import java.util.Enumeration;
import java.util.Hashtable;
import javax.microedition.lcdui.Graphics;

public class Board {
    private Hashtable table = new Hashtable();
    private RNGame parent;

    public Board(RNGame game) {
        parent = game;
        set(new Point(0,0), new Piece(0));
    }

    public void set(Point p, Piece piece) {
        piece.setPos(p);
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
        for (Enumeration p = table.elements(); p.hasMoreElements();) {
            Piece piece = (Piece)p.nextElement();
            Point pos   = piece.getPos();
            int type    = piece.getType();
            for (int i = 1; i <= 5; i++) {
                Point matchPos   = new Point(pos.x.intValue() + i, pos.y.intValue());
                Piece matchPiece = get(matchPos);
                if (matchPiece == null) {
                    continue;
                }
                int matchType    = matchPiece.getType();
                if (matchType != type) {
                    break;
                }
                if (i == 5) {
                    return piece.getType();
                }
            }
            for (int i = 1; i <= 5; i++) {
                Point matchPos   = new Point(pos.x.intValue(), pos.y.intValue() + i);
                Piece matchPiece = get(matchPos);
                if (matchPiece == null) {
                    continue;
                }
                int matchType    = matchPiece.getType();
                if (matchType != type) {
                    break;
                }
                if (i == 5) {
                    return piece.getType();
                }
            }
            for (int i = 1; i <= 5; i++) {
                Point matchPos   = new Point(pos.x.intValue() + i, pos.y.intValue() + i);
                Piece matchPiece = get(matchPos);
                if (matchPiece == null) {
                    continue;
                }
                int matchType    = matchPiece.getType();
                if (matchType != type) {
                    break;
                }
                if (i == 5) {
                    return piece.getType();
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
        g.fillRect(0, 0, w, h);

        // draw grid
        g.setColor(0,0,0);
        int i, j;
        
        for(i = 0;i <= w;i += 10) {
            g.drawLine(i, 0, i, h);
            g.drawLine(0, i, w, i);
        }

        
        for(i = center.x.intValue() - 10;i < center.x.intValue() + 10;i++) {
            for(j = center.y.intValue() - 10;j < center.y.intValue() + 10;j++) {
                Piece p = get(i,j);
                if(p != null) {
                    p.paint(g, center.x.intValue() - i, center.y.intValue() - j);
                }
            }
           
        }
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
    public Piece get(Point p) {
        return get(p.x.intValue(), p.y.intValue());
    }
}
