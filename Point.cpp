#ifndef POINTc
#define POINTc
#include "Point.h"
#include <bits/stdc++.h>
Point::Point(int X,int Y){
	x=X;
	y=Y;
}

double Point::dist(Point *p){
	return sqrt((x-p->getX())*(x-p->getX())+(y-p->getY())*(y-p->getY()));
}

int Point::getX(){
	return x;
}

int Point::getY(){
	return y;
}

#endif