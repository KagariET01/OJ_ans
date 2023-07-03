/*
[q]https://kagariet01.github.io/swap/?OJ=cf&C=1845&P=B
[math]
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
		INT x1,y1,x2,y2,x3,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		INT rx2=x2-x1;
		INT rx3=x3-x1;
		bool canx=((rx2>=0 && rx3>=0)||(rx2<=0 && rx3<=0));
		INT ry2=y2-y1;
		INT ry3=y3-y1;
		bool cany=((ry2>=0 && ry3>=0)||(ry2<=0 && ry3<=0));
		INT ans=1;
		if(canx){
			rx2=abs(rx2);
			rx3=abs(rx3);
			ans+=min(rx2,rx3);
		}
		if(cany){
			ry2=abs(ry2);
			ry3=abs(ry3);
			ans+=min(ry2,ry3);
		}
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
