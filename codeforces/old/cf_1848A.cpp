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
		INT n,m,k;
		INT ax,ay;
		cin>>n>>m>>k>>ax>>ay;
		bool ans=1;
		while(k--){
			INT bx,by;
			cin>>bx>>by;
				ans&=((abs(ax-bx)+abs(ay-by))%2);
		}
		if(!ans){
			cout<<"no"<<endl;
		}else{
			cout<<"yes"<<endl;
		}
	}
	return 0;
}
//#endif
