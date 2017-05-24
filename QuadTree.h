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
	class NonExistentPoint:public exception{
		const char* what()  { return "NonExistentPoint"; }	
	};
	class EmptyQuadtree:public exception{
		const char* what()  { return "EmptyQuadtree"; }	
	};
	Node *root;
	int f,c;
};

#endif