#ifndef NODE 
#define NODE


#include <bits/stdc++.h>
#include "Point.h"
using namespace std;

class Node{

private:
	int _x0,_x1,_y0,_y1;
	Point *_p;
	Node *NW, *SW, *SE, *NE;

public:

	Node(int,int,int,int,int,int);
	Node(int,int,int,int);
	~Node();
	Node *getNW();
	Node *getNE();
	Node *getSW();
	Node *getSE();
	void remove(int,int);
	bool search(int,int);
	void setNW(Node *n);
	void setNE(Node *n);
	void setSW(Node *n);
	void setSE(Node *n);
	void insert(int,int);
	bool hasChildren();
	void setPoint(Point*);
	Point *getPoint();
};

#endif