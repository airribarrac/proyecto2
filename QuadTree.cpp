#include "QuadTree.h"

QuadTree::QuadTree(int F,int C){
	f=F;
	c=C;
	root=new Node(0,c,0,f);
}

QuadTree::~QuadTree(){
	delete root;
}

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

void QuadTree::remove(int x,int y){
	if(root->hasChildren()){
		int xm=c/2;
		int ym=f/2;
		if(x>xm&&y>ym){		//SE
			if(root->getSE()==NULL){
				cout<<"no esta"<<endl;
			}else{
				if(root->getSE()->hasChildren()){
					root->getSE()->remove(x,y);
				}else{
					Point *p=root->getSE()->getPoint();
					if(p->getX()==x && p->getY()==y){
						delete root->getSE();
						root->setSE(NULL);
					}else{
						cout<<"no esta"<<endl;
					}
				}
			}
			
		}else if(x>xm&&y<=ym){	//NE
			if(root->getNE()==NULL){
				cout<<"no esta"<<endl;
			}else{
				if(root->getNE()->hasChildren()){
					root->getNE()->remove(x,y);
				}else{
					Point *p=root->getNE()->getPoint();
					if(p->getX()==x && p->getY()==y){
						delete root->getNE();
						root->setNE(NULL);
					}else{
						cout<<"no esta"<<endl;
					}
				}
			}
			
		}else if(x<=xm&&y>ym){	//SW
			if(root->getSW()==NULL){
				cout<<"no esta"<<endl;
			}else{
				if(root->getSW()->hasChildren()){
					root->getSW()->remove(x,y);
				}else{
					Point *p=root->getSW()->getPoint();
					if(p->getX()==x && p->getY()==y){
						delete root->getSW();
						root->setSW(NULL);
					}else{
						cout<<"no esta"<<endl;
					}
				}
			}
		}else if(x<=xm&&y<=ym){	//NW
			if(root->getNW()==NULL){
				cout<<"no esta"<<endl;
			}else{
				if(root->getNW()->hasChildren()){
					root->getNW()->remove(x,y);
				}else{
					Point *p=root->getNW()->getPoint();
					if(p->getX()==x && p->getY()==y){
						delete root->getNW();
						root->setNW(NULL);
					}else{
						cout<<"no esta"<<endl;
					}
				}
			}
		}	
	}else{
		cout<<"no esta"<<endl;
	}
}

bool QuadTree::search(int x,int y){
	if(root->hasChildren())
		return root->search(x,y);
	else
		return false;
}