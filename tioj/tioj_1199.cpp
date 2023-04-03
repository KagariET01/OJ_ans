/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/1199
*/

#include<iostream>
using namespace std;
#define INT long long int

INT modpow(INT x,INT n,INT mod){
	INT re=1;
	while(n>0){
		if(n&1){
			re=(re*x)%mod;
		}
		x=(x*x)%mod;
		n>>=1;
	}
	return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	INT qans,n,y;
	while(cin>>qans>>n>>y){
		if(qans==0 && n==0 && y==0)break;
		INT ans=0;
		for(INT x=0;x<y;x++){
			if(x==0 && n==0)continue;
			if(modpow(x,n,y)==qans)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

