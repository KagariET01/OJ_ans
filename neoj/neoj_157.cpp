/*
[Q]https://neoj.sprout.tw/problem/157/
[DP]
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
		INT n,m;
		cin>>n>>m;
		INT A[n],B[n];
		INT Atot=0,Btot=0;
		for(INT i=0;i<n;i++){
			cin>>A[i]>>B[i];
			Atot+=A[i];
			Btot+=B[i];
		}
		if(m>=Atot){
			cout<<Btot<<endl;
		}else{
			INT dp[m+1];
			memset(dp,0,sizeof(dp));
			for(INT i=0;i<n;i++){
				for(INT j=m;j>=A[i];j--){
					dp[j]=max(dp[j],dp[j-A[i]]+B[i]);
				}
			}
			cout<<dp[m]<<endl;
		}
	}
	return 0;
}