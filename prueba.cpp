//quitar comentario en define para utilizar
#define prueba
#ifdef prueba

#include <bits/stdc++.h>
#include "QuadTree.h"
#include "Point.h"
using namespace std;

int main(){
	QuadTree q(1000,1000);
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			q.insert(i,j);
		}
	}
	if(q.search(50,50)){
		cout<<"Punto existente"<<endl;
	}else{
		cout<<"Punto inexistente"<<endl;
	}
	q.remove(50,50);
	if(q.search(50,50)){
		cout<<"Punto existente"<<endl;
	}else{
		cout<<"Punto inexistente"<<endl;
	}
	q.insert(50,50);
	Point p=q.closest(300,300); // (99,99)
	cout<<p.getX()<<" "<<p.getY()<<endl;
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			q.remove(i,j);
		}
	}

	return 0;
}

#endif