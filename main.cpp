#include <bits/stdc++.h>
#include "QuadTree.h"
using namespace std;

int main(){
	QuadTree q(9,9);
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			q.insert(i,j);
		}
	}
	if(q.search(5,5))
		cout<<"encontra3"<<endl;
	//q.remove(5,5);
	if(q.search(5,5))
		cout<<"encontra3"<<endl;
	cout<<"inserto"<<endl;
	return 0;
}