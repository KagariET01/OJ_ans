/*
[TLE 55%]
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
		string nme[n];
		map<string,INT> mp;
		for(INT i=0;i<n;i++){
			cin>>nme[i];
			string nws="";
			INT m=nme[i].size();
			nws.reserve(m);
			for(INT j=0;j<m;j++){
				nws.push_back(nme[i][j]);
				mp[nws]++;
			}
		}

		for(INT i=0;i<n;i++){
			INT ans=0;
			string nws="";
			INT m=nme[i].size();
			nws.reserve(m);
			for(INT j=0;j<m;j++){
				nws.push_back(nme[i][j]);
				ans+=mp[nws]-1;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}