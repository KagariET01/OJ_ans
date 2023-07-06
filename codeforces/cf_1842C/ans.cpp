/*
[q]https://kagariet01.github.io/swap/?OJ=cf&C=1842&P=C
[AC]
*/
//#ifndef eval
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
bool debug=0;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	while(t--){
		INT n=read(INT);
		INT a[n+1],mndp[n+1],dp[n+1];
		for(INT i=0;i<=n;i++){
			a[i]=0,mndp[i]=n+5,dp[i]=0;
			if(i){
				cin>>a[i];
			}
		}
		for(INT i=1;i<=n;i++){
			dp[i]=min(dp[i-1]+1,mndp[a[i]]);
			mndp[a[i]]=min(mndp[a[i]],dp[i-1]);
		}
		cout<<n-dp[n]<<endl;
	}
	return 0;
}
//#endif
