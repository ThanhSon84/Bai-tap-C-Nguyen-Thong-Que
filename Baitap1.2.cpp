//B1.2.cpp
#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

main(){
	system("clear");
	int a, b, c, d;
	a=0&0;
	b=0&1;
	c=1&0;
	d=1&1;
	cout<<"CAC TOAN TU LOGIC SO HOC:"<<endl;
	cout<<"0 & 0 ="<<a<<endl;
	cout<<"0 & 1 ="<<b<<endl;
	cout<<"1 & 0 ="<<c<<endl;
	cout<<"1 & 1 ="<<d<<endl;
	cin.get();
	return 0;
}
