#ifndef POINT
#define POINT

class Point{
private:
	int x,y;
public:
	Point(int,int);
	int getX();
	int getY();
	double dist(Point*);
};

#endif