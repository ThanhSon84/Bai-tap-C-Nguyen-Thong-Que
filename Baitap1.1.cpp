#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//y=x<<n;<==>x*2^n;
//z=x>>n;<==>x/2^n;

using namespace std;
main()
{
	system("clear");
	int x=23, y;
	y=x<<1;cout<<"Dich trai "<<x<<" di 1 bit= "<<y<<"; tuong duong 23*2^1=46"<<endl;
	//y=46
	y=x<<2;cout<<"Dich trai "<<x<<" di 2 bit= "<<y<<"; tuong duong 23*2^2=92"<<endl;
	//y=92
	cout<<"================================================================="<<endl;
	y=x>>1; cout<<"Dich phai "<<x<<" di 1 bit= "<<y<<"; tuong duong 23/2^1=11"<<endl;
	y=x>>2; cout<<"Dich phai "<<x<<" di 2 bit= "<<y<<"; tuong duong 23/2^2=5"<<endl;
	cout<<"(Nho: Toan tu / tren day la phep chia lay phan nguyen!"<<endl;
	cin.get();
	return 0;

}
