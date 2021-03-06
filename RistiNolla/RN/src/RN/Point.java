package RN;

public class Point {
    public Integer x = new Integer(0);
    public Integer y = new Integer(0);
    public Point(int X, int Y) {
        x = new Integer(X);
        y = new Integer(Y);
    }

    Point(Point p) {
        x = p.x;
        y = p.y;
    }
    public String toString() {
        return "Point:["+x+","+y+"]";
    }
}
