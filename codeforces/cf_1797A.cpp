/*
[Q]https://codeforces.com/contest/1797/problem/A
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
		INT n,m;
		cin>>n>>m;
		INT x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		INT bans=4;
		INT aans=4;
		if(x1==1){
			aans--;
		}
		if(x1==n){
			aans--;
		}
		if(y1==1){
			aans--;
		}
		if(y1==m){
			aans--;
		}
		
		if(x2==1){
			bans--;
		}
		if(x2==n){
			bans--;
		}
		if(y2==1){
			bans--;
		}
		if(y2==m){
			bans--;
		}
		cout<<min(aans,bans)<<endl;
	}
	return 0;
}