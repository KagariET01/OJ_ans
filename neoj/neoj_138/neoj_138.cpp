/*
[Q]https://neoj.sprout.tw/problem/138/
[DP]
[AC]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT unsigned long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
bool debug=0;
template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}
INT mod=1000007;
INT ans[100005];


int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	ans[0]=1;
	ans[2]=3;
	for(INT i=4;i<=100000;i+=2){
		ans[i]=ans[i-2]*4-ans[i-4]+mod;
		ans[i]%=mod;
	}
	
	INT t;cin>>t;
	while(t--){
		cout<<ans[read(INT)]<<endl;
	}
	return 0;
}