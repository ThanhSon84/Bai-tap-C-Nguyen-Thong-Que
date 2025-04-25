//Code cai tien in ra lo trinh khi hoan vi
//B3.27
//Thuat toan tham lam tuong duong dung hoan vi
#include<iostream>
#include<stdio.h>
#include<stdlib.h>//clear screen

using namespace std;

	//Phan cac ham can khai bao
	//Khai bao ma tran chi phi
	int cost=999999;//luu chi phi min tuong duong gia tri lon nhat
	int cost_matrix[5][5]={ {0, 48, 43, 54, 31},
							{20, 0, 30, 63, 22},
							{29, 64, 0, 4, 7},
							{6, 19, 2, 0, 8},
							{1, 28, 9, 18, 0}};
	int best_path[5];

	//xu ly
	//ham hoan vi
	void swap(int* a, int* b){
		int tmp;
		tmp= *a;
		*a=*b;
		*b=tmp;
	}


	//ham tinh chi phi phuong an
	void copy_array(int* a,int n){
		int i;
		int sum=0;
		for(i=0;i<=n;i++){
			sum+=cost_matrix[a[i%5]][a[(i+1)%5]];
		}

		//In ra lo trinh hien tai
		cout<<"Current path:";
		for(int i=0;i<=n;i++){
			cout<<a[i]+1<<" ";//bat dau bang 1
		}
		cout<<a[0]+1<<" ";//Quay lai diem bat dau
		cout<<"| cost: "<<sum<<endl;//in ra chi phi hien tai

		//neu chi phi toi uu nho hon cost thi lay
		if(sum<cost){
			cost=sum;
			for(i=0;i<=n;i++){
				best_path[i]=a[i];//sao chep hoan vi toi uu
			}
		}
	}

	//ham de quy
	void permute(int* a, int i, int n){
	int j;
		if(i==n){
			//kiem tra da het hanh trinh, goi ham tinh tong
			copy_array(a, n);
		}
		else{
			//tao hoan vi
			for(j=i;j<=n;j++){
				swap((a+i),(a+j));
				//goi de qui
				permute(a,i+1,n);
				//nghich dao hoan vi khi het nhanh
				swap((a+i), (a+j));
			}
		}
	}
	//in ket qua
int main(){
	//cau hinh de bai
	system("cls");
	int a[]={0,1,2,3,4};//phuong an bat dau
	permute(a,0,4);//chon phuong an 0 de bat dau

	cout<<"Min cost= "<<cost<<endl;//cost from void copy_array
	cout<<"Optimal path: ";
	for(int i=0;i<5;i++){
		cout<<best_path[i]+1 <<" ";
	}
	cout<<best_path[0]+1<<endl;
	cin.get();//cho go Enter thoat man hinh

	return 0;
}
