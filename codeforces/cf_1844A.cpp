/*
[q]
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
		INT a,b;
		cin>>a>>b;
		if(a>b)swap(a,b);
		if(a>1){
			cout<<1<<endl;
			continue;
		}else if(b==2){
			cout<<3<<endl;
		}else{
			cout<<2<<endl;
			continue;
		}
	}
	return 0;
}
//#endif
