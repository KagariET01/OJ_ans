/*
[Q]https://neoj.sprout.tw/problem/63/
*/
#include<iostream>
using namespace std;
#define INT long long int
#define endl "\n"

const INT mxn=13;
INT k;
INT num[mxn+1];
INT choose[6];//挑選的號碼lst
void dfs(INT p=0,INT c=0){//p代表現在位置(表只能選num[i] i>=p
	if(c==6){
		for(INT i=0;i<6;i++){
			if(i)cout<<" ";
			cout<<choose[i];
		}
		cout<<endl;
		return;
	}else{
		for(INT i=p;i<k-(5-c);i++){
			choose[c]=num[i];
			dfs(i+1,c+1);
		}
	}
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		cin>>k;
		for(INT i=0;i<k;i++){
			cin>>num[i];
		}
		dfs();
	}
	return 0;
}