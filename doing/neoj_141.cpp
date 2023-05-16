/*
[Q]
[]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;cin>>t;
	while(t--){
		INT n;cin>>n;
		INT k=2;
		INT lst[n+5];
		INT dp[n+5];
		INT ans=0;
		for(INT i=0;i<n;i++){
			dp[i]=0;
			cin>>lst[i];
		}
		for(INT i=0;i<k;i++){
			dp[i]=lst[i];
			ans=max(ans,dp[i]);
		}
		for(INT i=k;i<n;i++){
			dp[i]=0;
			for(INT j=k;j<k*2 && i-j>=0;j++){
				dp[i]=max(dp[i],dp[i-j]);
			}
			dp[i]+=lst[i];
			ans=max(ans,dp[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}