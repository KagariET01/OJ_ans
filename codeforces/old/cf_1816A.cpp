/*
[Q]https://codeforces.com/contest/1816/problem/A
[AC]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);	INT t;cin>>t;
	while(t--){
		INT a,b;
		cin>>a>>b;
		if(__gcd(a,b)==1){
			cout<<1<<endl;
			cout<<a<<" "<<b<<endl;
			continue;
		}else{
			cout<<2<<endl;
			cout<<a-1<<" "<<1<<endl;
			cout<<a<<" "<<b<<endl;
		}
	}
	return 0;
}
