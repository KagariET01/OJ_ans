/*
[Q]https://codeforces.com/contest/1828/problem/B
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
		INT p[n+1];
		INT addp[n+1];
		for(INT i=1;i<=n;i++){
			p[i]=read(INT);
			addp[p[i]]=i;
		}
		DBG for(INT i=1;i<=n;i++){
			cerr<<addp[i]<<" ";
		}
		DBG cerr<<endl;

		INT ans=0;
		for(INT i=1;i<n && ans!=1;i++){
			DBG cerr<<ans<<" "<<addp[i]-i<<endl;;
			if(p[i]==i)continue;
			if(ans==0){
				ans=abs(addp[i]-i);
			}else{
				ans=__gcd(ans,abs(addp[i]-i));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
#endif