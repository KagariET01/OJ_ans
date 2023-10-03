/*
[Q]https://codeforces.com/contest/1828/problem/C
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
const INT mod=1e9+7;

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(INT);
	while(t--){
		INT n=read(INT);
		vector<pair<INT,bool>> vec;
		vec.reserve(n*2);
		for(INT i=0;i<n;i++){
			INT inin=read(INT);
			vec.push_back(make_pair(inin,0));
		}
		for(INT i=0;i<n;i++){
			INT inin=read(INT);
			vec.push_back(make_pair(inin,1));
		}
		sort(vec.begin(),vec.end());
		INT nwc=0;
		INT ans=1;
		for(pair<INT,bool> i:vec){
			if(ans==0)break;
			if(i.second)nwc++;
			else{
				ans*=nwc;
				ans%=mod;
				nwc--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
#endif