package RN;

import java.util.Hashtable;
import javax.microedition.lcdui.Graphics;

public class Board {
    Hashtable table = new Hashtable();
    RNGame parent;

    public Board(RNGame game) {
        parent = game;
    }

    public void set(Point p, Piece piece) {
        if(table.contains(p.x)) {
            Hashtable row = (Hashtable) table.get(p.x);
            if(row.contains(p.y)) {
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


    public boolean gameOver() {
        return false;
    }

    void paint(Graphics g, Point p, int w, int h) {
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

        System.out.println("foo");
        
        for(i = p.x.intValue() - 5;i < p.x.intValue() + 5;i++) {
            for(j = p.y.intValue() - 5;j < p.y.intValue() + 5;j++) {
                System.out.println(i + "," + j);
            }
            System.out.println("\n");
        }
    }
}
