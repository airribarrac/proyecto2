#ifndef QUADTREEADT
#define QUADTREEADT

class QuadTreeADT{
public:
	virtual void insert(int,int)=0;
	virtual void remove(int,int)=0;
	virtual bool search(int,int)=0;
};

#endif