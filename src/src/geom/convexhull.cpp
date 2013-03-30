public class Convex_Hull
{
    static double cross(Point2D p1, Point2D p2, Point2D p3)
    {
        return (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) 
          - (p2.getY() - p1.getY()) * (p3.getX() - p1.getX());
    }

    static class Comp implements Comparator < Point2D >
    {
        public int compare(Point2D p1, Point2D p2)
        {
            if (p1.getY() < p2.getY()) return -1;
            if (p1.getY() > p2.getY()) return 1;
            if (p1.getX() < p2.getX()) return -1;
            return 1;
        }
    }

    static final double EPSILON = 1e-12;

    static void convexHull(List < Point2D > points,
    List < Point2D > result)
    {
        int n = points.size();
        Point2D[] p2 = new Point2D[points.size() + 1];
        Collections.sort(points, new Comp());
        int top = 0;
        p2[top++] = points.get(0);
        p2[top++] = points.get(1);
        for (int i = 2; i < n; i++)
        {
            while (top >= 2 && cross(p2[top - 2], p2[top - 1], 
            points.get(i)) <= -EPSILON)
            --top;
            p2[top++] = points.get(i);

        }
        int r = top;
        for (int i = n - 2; i >= 0; i--)
        {
            while (top > r && cross(p2[top - 2], p2[top - 1],
            points.get(i)) <= -EPSILON)
            --top;
            if (i != 0)
            p2[top++] = points.get(i);
        }
        for (int i = 0; i < top; i++)
        result.add(p2[i]);
    }
}

Otra implementacion

struct Point
{
    double x, y;
};

int n;

double dis(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) 
      + (p1.y - p2.y) * (p1.y - p2.y));
}

double cross(Point p1, Point p2, Point p3)
{
    return (p2.x - p1.x) * (p3.y - p1.y) 
      - (p2.y - p1.y) * (p3.x - p1.x);
}

bool comp(const Point & p1, const Point & p2)
{
    if (p1.y < p2.y) return true;
    if (p1.y > p2.y) return false;
    if (p1.x < p2.x) return true;
}

void getconvexhull(Point p1[], Point p2[], int & top)
{
    sort(p1, p1 + n, comp);
    int i;
    top = 0;
    p2[top++] = p1[0];
    p2[top++] = p1[1];
    for (i = 2; i < n; i++)
    {
        while (top >= 2 && cross(p2[top - 2],
        p2[top - 1], p1[i]) <= 0)
        --top;
        p2[top++] = p1[i];
    }
    int r = top;
    for (i = n - 2; i >= 0; i--)
    {
        while (top > r && cross(p2[top - 2], 
        p2[top - 1], p1[i]) <= 0)
        --top;
        if (i != 0)
        p2[top++] = p1[i];
    }
}

// Esta implementacion tiene en cuenta casos en los que todos
// los puntos son colineales y no hay en realidad un convex
// hull, en ese caso los retorna en orden.

public class Convex
{
    
    static int ccw(Point2D a, Point2D b, Point2D c) {
        double area2 = (b.x-a.x)*(c.y-a.y) - 
		(b.y-a.y)*(c.x-a.x);
        if      (area2 < 0) return -1;
        else if (area2 > 0) return +1;
        else                return  0;
    }
 
    static class Point2D implements Comparable<Point2D>
    {
        public final Comparator<Point2D> POLAR_ORDER = 
		new PolarOrder();

        private final double x;    // x coordinate
        private final double y;    // y coordinate

        public Point2D(double x, double y) {
            this.x = x;
            this.y = y;
        }

        public int compareTo(Point2D that) {
            if (this.y < that.y) return -1;
            if (this.y > that.y) return +1;
            if (this.x < that.x) return -1;
            if (this.x > that.x) return +1;
            return 0;
        }

        private class PolarOrder implements Comparator<Point2D> {
            public int compare(Point2D q1, Point2D q2) {
                double dx1 = q1.x - x;
                double dy1 = q1.y - y;
                double dx2 = q2.x - x;
                double dy2 = q2.y - y;

                if      (dy1 >= 0 && dy2 < 0) return -1;    
                else if (dy2 >= 0 && dy1 < 0) return +1; 
                else if (dy1 == 0 && dy2 == 0) {          
                    if      (dx1 >= 0 && dx2 < 0) return -1;
                    else if (dx2 >= 0 && dx1 < 0) return +1;
                    else                          return  0;
                }
                else return -ccw(Point2D.this, q1, q2);  
            }
        }
        
        public boolean equals(Object other) {
            if (other == this) return true;
            if (other == null) return false;
            if (other.getClass() != this.getClass())
				return false;
            Point2D that = (Point2D) other;
            return this.x == that.x && this.y == that.y;
        }
    }
   
    static class GrahamScan
    {
        private Stack<Point2D> hull = new Stack<Point2D>();

    public GrahamScan(ArrayList <Point2D> pts)
    {
        int N = pts.size();
        Point2D[] points = new Point2D[N];
        for (int i = 0; i < N; i++)
            points[i] = pts.get(i);
        Arrays.sort(points);
        Arrays.sort(points, 1, N, points[0].POLAR_ORDER);

        hull.push(points[0]);

        int k1;
        for (k1 = 1; k1 < N; k1++)
            if (!points[0].equals(points[k1])) 
				break;
        if (k1 == N) return;       
        int k2;
        for (k2 = k1 + 1; k2 < N; k2++)
            if (ccw(points[0], points[k1], points[k2]) != 0) 
				break;
        hull.push(points[k2-1]);   
        for (int i = k2; i < N; i++) {
            Point2D top = hull.pop();
            while (ccw(hull.peek(), 
			           top, points[i]) <= 0) {
                top = hull.pop();
            }
            hull.push(top);
            hull.push(points[i]);
        }
        assert isConvex();
    }

    public Iterable<Point2D> hull() {
        Stack<Point2D> s = new Stack<Point2D>();
        for (Point2D p : hull) s.push(p);
        return s;
    }

    private boolean isConvex()
    {
        int N = hull.size();
        if (N <= 2) return true;

        Point2D[] points = new Point2D[N];
        int n = 0;
        for (Point2D p : hull()) {
            points[n++] = p;
        }

        for (int i = 0; i < N; i++) {
            if (ccw(points[i], 
				points[(i+1) % N],
				points[(i+2) % N]) <= 0) {
                return false;
            }
        }
        return true;
    }
    }
}