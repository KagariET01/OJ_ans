/*
[Q]https://neoj.sprout.tw/problem/399/
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
	INT t=1;
	while(t--){
		INT n=read(INT);
		pair<INT,INT> lst[n];
		for(INT i=0;i<n;i++){
			lst[i]=make_pair(read(INT),read(INT));
		}
		map<INT,INT> mp;
		for(INT i=0;i<n;i++){
			for(INT j=i+1;j<n;j++){
				INT xx=abs(lst[i].first-lst[j].first);
				INT yy=abs(lst[i].second-lst[j].second);
				mp[xx*xx+yy*yy]++;
			}
		}
		INT ans=0;
		for(pair<INT,INT> i:mp){
			DBG cerr<<i.second<<endl;
			ans+=i.second*(i.second-1)/2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
