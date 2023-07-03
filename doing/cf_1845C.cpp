/*
[q]
[WA]
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
		string s,l,r;
		INT m;
		cin>>s>>m>>l>>r;
		INT lp=0,rp=0;
		for(char c:s){
			if(lp<m && l[lp]==c){
				lp++;
			}
			if(rp<m && r[rp]==c){
				rp++;
			}
			if(lp>=m && rp>=m)break;
		}
		if(lp>=m && rp>=m){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
//#endif
