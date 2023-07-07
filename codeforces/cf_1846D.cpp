/*
[q]https://codeforces.com/contest/1846/problem/D
[AC]
*/
//#ifndef eval
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define FINT long double
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
bool debug=0;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}
#define PIII pair<INT,pair<INT,INT>>

struct dta{
	INT id=0;
	INT ac=0;
	INT pen=0;
};

bool vser(dta a,dta b){
	if(a.ac != b.ac){
		return a.ac>b.ac;
	}else if(a.pen != b.pen){
		return a.pen<b.pen;
	}else{
		return a.id<b.id;
	}
	
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	DBG cerr<<"t="<<t<<endl;
	while(t--){
		INT n,d,h;
		cin>>n>>d>>h;
		INT lst[n];
		for(INT i=0;i<n;i++){
			cin>>lst[i];
		}
		sort(lst,lst+n);
		FINT ans=0;
		FINT orig=d*h;
		for(INT i=0;i<n;i++){
			if(i){
				INT hc=lst[i]-lst[i-1];
				if(hc<h){
					INT hb=h-hc;
					FINT db=hb*d/(FINT)(h);
					ans-=db*hb;
				}
			}
			ans+=orig;
			DBG cerr<<"nwans="<<ans<<endl;
		}
		cout<<fixed<<ans/2<<endl;
	}
	return 0;
}
//#endif
/*


*/