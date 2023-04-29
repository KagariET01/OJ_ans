/*
[Q]https://codeforces.com/contest/1630/problem/A
[Q]https://codeforces.com/contest/1631/problem/C
[AC]
*/
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
		INT n,m;cin>>n>>m;
		if(n==4 && m==3){
			cout<<-1<<endl;
			continue;
		}else if(m==0){
			for(INT i=0;i<n/2;i++){
				cout<<i<<" "<<((n-1)^i)<<endl;
			}
		}else if(m==n-1){
			cout<<n-1<<" "<<n-2<<endl;
			cout<<1<<" "<<n-3<<endl;
			cout<<0<<" "<<2<<endl;
			for(INT i=3;i<n/2;i++){
				cout<<i<<" "<<((n-1)^i)<<endl;
			}
		}else{
			cout<<n-1<<" "<<m<<endl;
			cout<<((n-1)^m)<<" "<<0<<endl;
			for(INT i=1;i<n/2;i++){
				if(i==m || ((n-1)^i)==m)continue;
				cout<<i<<" "<<((n-1)^i)<<endl;
			}
		}
	}
	return 0;
}