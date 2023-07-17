/*
[q]https://kagariet01.github.io/swap/?OJ=at&C=abc310&P=A
[water]
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
	INT t=1;
	while(t--){
		INT n,p,q;
		cin>>n>>p>>q;
		INT a[n];
		INT mina=1e9;
		for(INT i=0;i<n;i++){
			cin>>a[i];
			mina=min(mina,a[i]);
		}
		cout<<min(p,q+mina)<<endl;
	}
	return 0;
}
//#endif
