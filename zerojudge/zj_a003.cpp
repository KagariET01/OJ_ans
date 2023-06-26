/*
[Q]https://kagariet01.github.io/swap/?OJ=zj&P=a003
[AC]
[if,else]
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
	int M,D;
	cin>>M>>D;
	int S=(M*2+D)%3;
	if(S==0) cout<<"普通";
	else if(S==1) cout<<"吉";
	else cout<<"大吉";
	return 0;
}