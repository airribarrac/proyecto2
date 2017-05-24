#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

/*
	constructor para nodo con punto
*/

Node::Node(int x, int y,int x0,int x1,int y0,int y1){
	_p = new Point(x,y);
	NW=SW=SE=NE=NULL;
	_x0=x0;
	_y0=y0;
	_x1=x1;
	_y1=y1;
}

/*
	constructor para root
*/
Node::Node(int x0,int x1,int y0,int y1){
	_p = NULL;
	NW=SW=SE=NE=NULL;
	_x0=x0;
	_y0=y0;
	_x1=x1;
	_y1=y1;	
}
/*
	funcion recursiva que retorna el punto mas cercano utilizando dfs
*/
Point* Node::closest(Point *p){
	if(!hasChildren()){
		return _p;
	}
	Point* c=NULL;	//punto mas cercano encontrado en el subarbol
	if(SE!=NULL){
		Point *cc=SE->closest(p);
		if(c==NULL){
			c=cc;
		}else if(p->dist(c)>p->dist(cc)){
			c=cc;
		}
	}
	if(SW!=NULL){
		Point *cc=SW->closest(p);
		if(c==NULL){
			c=cc;
		}else if(p->dist(c)>p->dist(cc)){
			c=cc;
		}
	}
	if(NE!=NULL){
		Point *cc=NE->closest(p);
		if(c==NULL){
			c=cc;
		}else if(p->dist(c)>p->dist(cc)){
			c=cc;
		}
	}
	if(NW!=NULL){
		Point *cc=NW->closest(p);
		if(c==NULL){
			c=cc;
		}else if(p->dist(c)>p->dist(cc)){
			c=cc;
		}
	}
	return c;
}
// retorna true si hay al menos un nodo hijo
bool Node::hasChildren(){
	return NW!=NULL||SW!=NULL||NE!=NULL||SE!=NULL;
}
/*
	elimina punto del arbol, si no existe lanza una excepcion
	además elimina las ramas que ya no se utilizan
*/
void Node::remove(int x,int y){
	int xm=(_x0+_x1)/2;
	int ym=(_y0	+_y1)/2;
	//busca cuadrante
	if(x>xm&&y>ym){		//SE
		if(SE==NULL){
			throw NonExistentPoint();
		}else{
			if(getSE()->hasChildren()){
				getSE()->remove(x,y);
				//elimina ramas ya no se utilizando
				if(!getSE()->hasChildren()){
					delete SE;
					SE=NULL;
				}
			}else{
				Point *p=getSE()->getPoint();
				//elimina el punto si es el correcto
				if(p->getX()==x && p->getY()==y){
					delete SE;
					SE=NULL;
				}else{
					throw NonExistentPoint();
				}

			}

		}
		// lo mismo para cada cuadrante
	}else if(x>xm&&y<=ym){	//NE
		if(getNE()==NULL){
			throw NonExistentPoint();
		}else{
			if(getNE()->hasChildren()){
				getNE()->remove(x,y);
				if(!getNE()->hasChildren()){
					delete NE;
					NE=NULL;
				}
			}else{
				Point *p=getNE()->getPoint();
				if(p->getX()==x && p->getY()==y){
					delete NE;
					NE=NULL;
				}else{
					throw NonExistentPoint();
				}
			}
		}
		
	}else if(x<=xm&&y>ym){	//SW
		if(getSW()==NULL){
			throw NonExistentPoint();
		}else{
			if(getSW()->hasChildren()){
				getSW()->remove(x,y);
				if(!getSW()->hasChildren()){
					delete SW;
					SW=NULL;
				}
			}else{
				Point *p=getSW()->getPoint();
				if(p->getX()==x && p->getY()==y){
					delete SW;
					SW=NULL;
				}else{
					throw NonExistentPoint();
				}
			}
		}
	}else if(x<=xm&&y<=ym){	//NW
		if(getNW()==NULL){
			throw NonExistentPoint();
		}else{
			if(getNW()->hasChildren()){
				getNW()->remove(x,y);
				if(!getNW()->hasChildren()){
					delete NW;
					NW=NULL;
				}
			}else{
				Point *p=getNW()->getPoint();
				if(p->getX()==x && p->getY()==y){
					delete NW;
					NW=NULL;
				}else{
					throw NonExistentPoint();
				}
			}
		}
	}	
}
//busca dentro del arbol recorriendo por altura
bool Node::search(int x,int y){
	if(hasChildren()){
		int xm=(_x0+_x1)/2;
		int ym=(_y0+_y1)/2;
		if(x>xm&&y>ym){		//SE
			if(SE==NULL){
				return false;
			}else{
				return SE->search(x,y);
			}
		}else if(x>xm&&y<=ym){	//NE
			if(NE==NULL){
				return false;
			}else{
				return NE->search(x,y);
			}
		}else if(x<=xm&&y>ym){	//SW
			if(SW==NULL){
				return false;
			}else{
				return SW->search(x,y);
			}
		}else if(x<=xm&&y<=ym){	//NW
			if(NW==NULL){
				return false;
			}else{
				return NW->search(x,y);
			}
		}
	}else{
		Point *p=getPoint();
		return p->getX()==x && p->getY()==y;
	}
}
/*
	busca donde debe insertarse el nodo, considerando conflictos en cuadrantes, luego crea el nodo
*/
void Node::insert(int x,int y){
	if(hasChildren()){
		int xm=(_x0+_x1)/2;
		int ym=(_y0+_y1)/2;
		if(x>xm&&y>ym){		//SE
			if(SE==NULL){
				SE= new Node(x,y,xm,_x1,ym,_y1);
			}else{
				SE->insert(x,y);
			}
		}else if(x>xm&&y<=ym){	//NE
			if(NE==NULL){
				NE = new Node(x,y,xm,_x1,_y0,ym);
			}else{
				NE->insert(x,y);
			}
		}else if(x<=xm&&y>ym){	//SW
			if(SW==NULL){
				SW = new Node(x,y,_x0,xm,ym,_y1);
			}else{
				SW->insert(x,y);
			}
		}else if(x<=xm&&y<=ym){	//NW
			if(NW==NULL){
				NW = new Node(x,y,_x0,xm,_y0,ym);
			}else{
				NW->insert(x,y);
			}
		}
	}else{
		//convertirlo a nodo interno
		Point *p=getPoint();
		int xx=p->getX();
		int yy=p->getY();
		if(xx==x && yy==y){
			throw PointAlreadyInserted();
		}
		int xm=(_x0+_x1)/2;
		int ym=(_y0+_y1)/2;
		delete _p;
		_p=NULL;
		if(xx>xm&&yy>ym){		//SE
			SE= new Node(xx,yy,xm,_x1,ym,_y1);
		}else if(xx>xm&&yy<=ym){	//NE
			NE = new Node(xx,yy,xm,_x1,_y0,ym);
			
		}else if(xx<=xm&&yy>ym){	//SW
			SW = new Node(xx,yy,_x0,xm,ym,_y1);
			
		}else if(xx<=xm&&yy<=ym){	//NW
			NW = new Node(xx,yy,_x0,xm,_y0,ym);
		}
		insert(x,y);
	}
}

Node::~Node(){
	if(NW != NULL){
		delete NW;
	}
	if(NE != NULL){
		delete NE;
	}
	if(SW != NULL){
		delete SW;
	}
	if(SE != NULL){
		delete SE;
	}
	if(_p != NULL){
		delete _p;
	}
}

/*
	getters y settersq varios
*/

Node *Node::getNW(){
	return NW;
}

Node *Node::getNE(){
	return NE;
}

Node *Node::getSW(){
	return SW;
}

Node *Node::getSE(){
	return SE;
}

void Node::setNW(Node *n){
	NW = n;
}

void Node::setNE(Node *n){
	NE = n;
}

void Node::setSW(Node *n){
	SW = n;
}

void Node::setSE(Node *n){
	SE = n;
}

void Node::setPoint(Point *p){
	if(_p == NULL){
		_p = p;
	}else{
		delete _p;
		_p = p;
	}
}

Point* Node::getPoint(){
	return _p;
}