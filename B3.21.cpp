//B3.21.cpp
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

using namespace std;

int dem=0;
void hanoi(int n,  int c1, int c2, int c3){
	if(n==1){
		cout<<"\n Dia tu coc "<<c1<<" duoc chuyen sang coc "<<c2;
		dem++;
	}
	else{
		hanoi(n-1,c1,c3,c2);
		hanoi(1,c1,c2,c3);
		hanoi(n-1,c3,c2,c1);
	}
}

int main(){
	int n; system("cls");
	cout<<"\n Cho biet so dia can chuyen: "; cin>>n;
	hanoi(n, 1, 2, 3);
	cout<<"\n Xong! So lan chuyen  dia: "<<dem;
	cin.get();

	return 0;
}
