/*
[q]https://codeforces.com/contest/1846/problem/A
[AC]
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
		INT n=read(INT);
		INT ans=0;
		while(n--){
			INT a,b;
			cin>>a>>b;
			if(a>b)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
