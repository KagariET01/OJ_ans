/*
[Q]https://codeforces.com/contest/1828/problem/A
[AC]
*/
#ifndef EVAL
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
bool debug=0;
template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(INT);
	while(t--){
		INT n=read(INT);
		INT otherTOT=(2+n)*(n-1)/2;
		otherTOT%=n;
		cout<<n-otherTOT+n;
		for(INT i=2;i<=n;i++){
			cout<<" "<<i;
		}
		cout<<endl;
	}
	return 0;
}
#endif