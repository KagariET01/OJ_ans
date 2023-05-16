/*
[Q]https://neoj.sprout.tw/problem/398/
[CE]
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
const double eps=1e-10;
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=1;
	while(t--){
		INT n=read(INT);
		map<double,INT> mp;
		for(INT i=0;i<n;i++){
			mp[read(double)]++;
		}
		INT ans=0;
		for(pair<double,INT> i:mp){
			for(pair<double,INT> j:mp){
				double tot=i.first+j.first;
				for(pair<double,INT> k:mp){//直接算會有福點數誤差
					if(fabs(tot-k.first)<=eps){
						ans+=i.second*j.second*k.second;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
#endif