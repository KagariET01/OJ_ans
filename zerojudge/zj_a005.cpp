/*
[Q]https://kagariet01.github.io/swap/?OJ=zj&P=a005
[AC]
[基本語法]
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
	int int_t;
	cin>>int_t;
	int list1[int_t][5];
	for(int i=0;i<int_t;i++){
		for(int j=0;j<=3;j++){
			cin>>list1[i][j];
		}
		if(
		   list1[i][0]-list1[i][1]==
		   list1[i][1]-list1[i][2]
		   ){
			int add=list1[i][0]-list1[i][1];
			list1[i][4]=list1[i][3]-add;
		}else{
			list1[i][4]=int((list1[i][1]*1.0)/list1[i][0]*list1[i][3]);
		}
	}
	for(int i=0;i<int_t;i++){
		for(int j=0;j<=4;j++){
			cout<<list1[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}