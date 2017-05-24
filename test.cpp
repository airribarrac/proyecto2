#ifdef PARTE4
#include <bits/stdc++.h>
#include "QuadTree.h"
#include "Point.h"
using namespace std;

int main(){
	QuadTree a(1000000000,1000000000);			//puntos distribuidos uniformemente en todo el espacio
	QuadTree b(1000000000,1000000000);			//puntos distribuidos de forma concentrada

	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			a.insert(i*100000000,j*100000000);
			b.insert(2*i,2*j);
		}
	}
	clock_t t1=clock();
	int aa=0;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			a.search(i*100000000,j*100000000);
		}
	}
	cout<<"Busqueda de elementos insertados: "<<endl;
	cout<<"Tiempo en distribucion uniforme: "<<(double)(clock()-t1)/CLOCKS_PER_SEC<<endl;
	t1=clock();
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			b.search(2*i,2*j);
		}
	}
	cout<<"Tiempo en distribucion concentrada: "<<(double)(clock()-t1)/CLOCKS_PER_SEC<<endl;


	cout<<"Busqueda de elementos no insertados: "<<endl;
	t1=clock();
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			a.search(i*100000000+1,j*100000000+1);	
		}
	}
	cout<<"Tiempo en distribucion uniforme: "<<(double)(clock()-t1)/CLOCKS_PER_SEC<<endl;
	t1=clock();
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			b.search(2*i+1,2*j+1);
		}
	}
	cout<<"Tiempo en distribucion concentrada: "<<(double)(clock()-t1)/CLOCKS_PER_SEC<<endl;
	
}

#endif

#ifdef PARTE3
#include <bits/stdc++.h>
#include "QuadTree.h"
#include "Point.h"
using namespace std;

bool arraysearch(Point *p[], int x, int y){
	for(int i=0; i<10000; i++){
		if(p[i]->getX() == x && p[i]->getY() == y){
			return true;
		}
	}
	return false;
}


int main(){
	QuadTree *qt = new QuadTree(10001,10001);
	Point *array[10000];
	srand(3);
	for(int i=0; i<10000; i++){
		array[i] = new Point(rand()%10000,rand()%10000);
	}
	puts("asdasd");
	for(int i=0; i<10000; i++){
		cout << array[i]->getX() << " " << array[i]->getY() <<  " " << i << endl; 
		qt->insert(array[i]->getX(),array[i]->getY());
	}
	/*bool encontrado;
	clock_t t0, t1;
	puts("QuadTree:");
	t0 = clock();
	encontrado = qt->search(1234,1234);
	t1 = clock();
	cout << (encontrado?"se encontro \t":"no se encontro \t");
	cout << "Tiempo = " << (double)(t1-t0)/CLOCKS_PER_SEC << endl;
	puts("Array:");
	t0 = clock();
	encontrado = arraysearch(array,1234,1234);
	t1 = clock();
	cout << (encontrado?"se encontro \t":"no se encontro \t");
	cout << "Tiempo = " << (double)(t1-t0)/CLOCKS_PER_SEC << endl;
	*/

	return 0;
}

#endif

#ifdef AAA
#include <bits/stdc++.h>
#include "QuadTree.h"
using namespace std;

int main(){
	QuadTree q(100000,100000);
	
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			q.insert(100+i,100+j);
		}
	}
	Point p=q.closest(50000,20000);
	cout<<p.getX()<<" "<<p.getX()<<endl;
	p=q.closest(0,0);
	q.remove(0,0);
	cout<<p.getX()<<" "<<p.getX()<<endl;
	if(q.search(1,1)){
		cout<<"asdasdas"<<endl;
	}
	if(q.search(10000,10000)){
		cout<<"asdasdas"<<endl;
	}
	
	q.insert(100,100);
	Point p=q.closest(1,1);
	cout<<p.getX()<<" "<<p.getX()<<endl;	
	return 0;
}
#endif