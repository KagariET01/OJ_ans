/*
[Q]https://codeforces.com/contest/1763/problem/A
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
		INT n;cin>>n;
		INT mx=0,mn=2047;
		for(INT i=0;i<n;i++){
			INT inin;cin>>inin;
			if(i){
				mx=mx|inin;
				mn=mn&inin;
			}
			else{
				mx=mn=inin;
			}
		}
		cout<<mx-mn<<endl;
	}
	return 0;
}