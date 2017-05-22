#ifndef QUADTREE
#define QUADTREE

#include "QuadTreeADT.h"
#include "Node.h"
#include "Point.h"
class QuadTree:public QuadTreeADT{
public:
	QuadTree(int,int);
	~QuadTree();
	void insert(int,int);
	void remove(int,int);
	bool search(int,int);
	Point closest(int,int);
private:
	Node *root;
	int f,c;
};

#endif