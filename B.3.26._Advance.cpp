//B.3.26
//Back tracking

#include<iostream>
#include<fstream>//doc ghi file
#include<stdio.h>
#include<stdlib.h>//clear screen
#define max 100
using namespace std;

const int INF=1e9;//Bien gia tri rat lon set Min
const char *name="BTDLIC.TXT";
FILE *f;

int minChiphi=INF;//Gan gia tri ban dau la rat lon
int paMin[max];//Luu tru lo trinh toi uu
int n;
int matran[max][max];
int daxet[max];
int pa[max];
int chiphi;
int c;

void InKetQua(){
	cout<<"\nLo trinh toi uu: ";
	for(int i=1;i<=n;i++){
		cout<<paMin[i]<<"->";
	}
	cout<<"->"<<paMin[1]<<", Chi phi nho nhat = "<<minChiphi<<endl;
}

void DocDL(){
	ifstream f(name);
	if(!f){
		puts("Loi mo tep");
		cin.get();
		exit(0);//thoat khoi ctr va tra ve 0
	}
	f>>n;
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			f>>matran[i][j];
			//f.close();//Ham f.close() dong file nen chua doc xong du lieu da tat
		}
	}
	f.close();
}

void In(){
	int i;
	puts(" ");
	cout<<"Lo trinh khep kin va chi phi tuong ung: \n";
	for(i=1;i<=n;i++){
		cout<<pa[i]<<"->";
	}
		cout<<pa[n+1]<<", Chi phi="<<chiphi;
		puts("");
}

void Try(int i){
	for(int j=2;j<=n;j++){
		if(!daxet[j] && matran[pa[i-1]][j]){
			pa[i]=j;
			daxet[j]=1;
			c+=matran[pa[i-1]][j];
			if(i==n){
				if(matran[pa[n]][1]){
					chiphi=c+matran[pa[n]][1];
					pa[n+1]=1;//Ket thu tai dinh dau tien
					In();//Hien thi lo trinh hien tai
					if(chiphi<minChiphi){
						minChiphi=chiphi;
						for(int k=1;k<=n;k++){
							paMin[k]=pa[k];
						}
						paMin[n+1]=1;//Cap nhat lo trinh toi uu
					}
				}
			}
			else{
				Try(i+1);
			}
			daxet[j]=0;
			c-=matran[pa[i-1]][j];
			
		}
	}
}

int main(){
	system("cls");
	DocDL();
	daxet[1]=1;
	pa[1]=1;
	c=0;
	Try(2);
	InKetQua();//hien thi lo trinh min cost

	cin.get();
	return 0;

}
