#include <bits/stdc++.h>
#include "QuadTree.h"
using namespace std;

int main(){
	QuadTree q(100000000,1000000000);
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			q.insert(100+i,100+j);
		}
	}
	Point p=q.closest(10000,10000);
	cout<<p.getX()<<" "<<p.getX()<<endl;
	p=q.closest(0,0);
	cout<<p.getX()<<" "<<p.getX()<<endl;
	if(q.search(1,1)){
		cout<<"asdasdas"<<endl;
	}
	if(q.search(10000,10000)){
		cout<<"asdasdas"<<endl;
	}
	cout<<"inserto"<<endl;
	return 0;
}