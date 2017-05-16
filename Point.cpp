#ifndef POINTc
#define POINTc
#include "Point.h"

Point::Point(int X,int Y){
	x=X;
	y=Y;
}

int Point::getX(){
	return x;
}

int Point::getY(){
	return y;
}

#endif