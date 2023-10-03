/*
[q]https://kagariet01.github.io/swap/?OJ=cf&C=1842&P=A
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
		INT n,m;
		cin>>n>>m;
		INT a=0,b=0;
		while(n--)a+=read(INT);
		while(m--)b+=read(INT);
		if(a>b) cout<<"Tsondu"<<endl;
		else if(a==b) cout<<"Draw"<<endl;
		else cout<<"Tenzing"<<endl;
	}
	return 0;
}
//#endif
