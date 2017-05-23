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
	srand(time(NULL));
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



/*
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
*/