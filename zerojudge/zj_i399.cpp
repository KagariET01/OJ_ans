/*
[Q]https://zerojudge.tw/ShowProblem?problemid=i399
[AC]
*/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	int a[4];
	for(int i=0;i<3;i++){
		cin>>a[i];
	}
	a[3]=87;
	sort(a,a+3);
	int cc=1;
	if(a[0]==a[1] || a[1]==a[2])cc=2;
	if(a[0]==a[1] && a[1]==a[2])cc=3;
	cout<<cc<<" ";
	for(int i=2;i>=0;i--){
		if(a[i]==a[i+1])continue;
		else cout<<a[i]<<" ";
	}
	return 0;
}