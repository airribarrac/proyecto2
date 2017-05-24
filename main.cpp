//agregar comentario a define si se utiliza prueba.cpp
//#define MAIN
#ifdef MAIN

#include <bits/stdc++.h>
#include "QuadTree.h"
#include "Point.h"
using namespace std;

int main(){
	ifstream f ("input.txt");
	int n,m,p;
	f>>n>>m>>p;
	QuadTree q(n,m);
	for(int i=0;i<p;i++){
		int x,y;
		f>>x>>y;
		q.insert(x,y);
		if(q.search(x,y)){
			cout<<x<<" "<<y<<" insertado"<<endl;
		}
	}
	return 0;
}

#endif