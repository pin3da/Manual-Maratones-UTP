struct point{
	double x;
	double y;
	
	point(){}
	point(double x_,double y_): x(x_),y(y_){}
	
	bool operator < (const point &other) const {
		if(x == other.x) return y < other.y;
		return x < other.x;
	}
	
	double dist(const point &other){
		double a = x - other.x;
		double b = y - other.y;
		return sqrt(a*a + b*b);
	}
	
	double cross(const point &a, const point &b){
		return (a.x - x)*(b.y - y) - (b.x - x)*(a.y - y);
	}
	
}
