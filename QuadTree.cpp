#include "QuadTree.h"
#include <bits/stdc++.h>
QuadTree::QuadTree(int F,int C){
	f=F;
	c=C;
	root=new Node(0,c,0,f);
}

QuadTree::~QuadTree(){
	delete root;
}
//punto mas cercano dentro del quadtree
Point QuadTree::closest(int x,int y){
	if(!root->hasChildren()){
		throw EmptyQuadtree();
	}
	Point *p=new Point(x,y);
	Point *aux=root->closest(p);
	Point res(aux->getX(),aux->getY());
	return res;
}
//insertar un punto
void QuadTree::insert(int x,int y){
	if(root->hasChildren()){
		root->insert(x,y);
	}else{
		int xm=c/2;
		int ym=f/2;
		if(x>xm&&y>ym){		//SE
			root->setSE(new Node(x,y,xm,c,ym,f));	
		}else if(x>xm&&y<=ym){	//NE
			root->setNE(new Node(x,y,xm,c,0,ym));
		}else if(x<=xm&&y>ym){	//SW
			root->setSW(new Node(x,y,0,xm,ym,f));
		}else if(x<=xm&&y<=ym){	//NW
			root->setNW(new Node(x,y,0,xm,0,ym));
		}
	}
}
//remover un punto, quitando ramas ya no usadas
void QuadTree::remove(int x,int y){
	if(root->hasChildren()){	
		int xm=c/2;
		int ym=f/2;
		if(x>xm&&y>ym){		//SE
			if(root->getSE()==NULL){
				throw NonExistentPoint();
			}else{
				if(root->getSE()->hasChildren()){
					root->getSE()->remove(x,y);
				}else{
					Point *p=root->getSE()->getPoint();
					if(p->getX()==x && p->getY()==y){
						delete root->getSE();
						root->setSE(NULL);
					}else{
						throw NonExistentPoint();
					}
				}
			}
			
		}else if(x>xm&&y<=ym){	//NE
			if(root->getNE()==NULL){
				throw NonExistentPoint();
			}else{
				if(root->getNE()->hasChildren()){
					root->getNE()->remove(x,y);
				}else{
					Point *p=root->getNE()->getPoint();
					if(p->getX()==x && p->getY()==y){
						delete root->getNE();
						root->setNE(NULL);
					}else{
						throw NonExistentPoint();
					}
				}
			}
			
		}else if(x<=xm&&y>ym){	//SW
			if(root->getSW()==NULL){
				throw NonExistentPoint();
			}else{
				if(root->getSW()->hasChildren()){
					root->getSW()->remove(x,y);
				}else{
					Point *p=root->getSW()->getPoint();
					if(p->getX()==x && p->getY()==y){
						delete root->getSW();
						root->setSW(NULL);
					}else{
						throw NonExistentPoint();
					}
				}
			}
		}else if(x<=xm&&y<=ym){	//NW
			if(root->getNW()==NULL){
				throw NonExistentPoint();
			}else{
				if(root->getNW()->hasChildren()){
					root->getNW()->remove(x,y);
				}else{
					Point *p=root->getNW()->getPoint();
					if(p->getX()==x && p->getY()==y){
						delete root->getNW();
						root->setNW(NULL);
					}else{
						throw NonExistentPoint();
					}
				}
			}
		}	
	}else{
		throw NonExistentPoint();
	}
}
//true si es que el punto existe
bool QuadTree::search(int x,int y){
	if(root->hasChildren())
		return root->search(x,y);
	else
		return false;
}