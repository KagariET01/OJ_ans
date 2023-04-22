/*
[Q]https://neoj.sprout.tw/problem/138/
[DP]
[TLE]
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
INT mod=1000007;
INT ans[100002];


int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	ans[2]=3;
	for(INT i=4;i<=100000;i+=2){
		ans[i]=ans[i-2]*6;
		ans[i]%=mod;
		ans[i]+=2;
		ans[i]%=mod;
	}
	
	INT t;cin>>t;
	DBG{
		INT it=20;
		for(INT i=0;i<t;i++){
			cout<<i<<":"<<ans[i]<<" ";
			it--;
			if(!it){
				cout<<endl;
				it=20;
			}
		}
	}else{
		while(t--){
			cout<<ans[read(INT)]<<endl;
		}
	}
	return 0;
}