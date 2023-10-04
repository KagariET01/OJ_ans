/*
[Q]https://codeforces.com/contest/1814/problem/0
[AC]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT n,k;
		cin>>n>>k;
		if(k==1){
			cout<<"YES"<<endl;
		}else if(k%2){//如果k是奇數，那也一定有解(已知k<=n)
			cout<<"YES"<<endl;
		}else if(n%2 ^ 1){//如果n是偶數，也一定有解
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}