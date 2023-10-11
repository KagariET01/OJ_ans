#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

INT mod=998244353;

int main(int argc,char** argv){
	for(int i=0;i<argc;i++){
		string nwstr=argv[i];
		if(nwstr=="-Dev"){
			debug=1;
			noTLE=0;
		}else if(nwstr=="-TLE"){
			noTLE=0;
		}
	}
	DBG{
		cout<<"Temp by KagariET01"<<endl;
		cout<<"My Webpage: https://kagariet01.github.io/about"<<endl;
		cout<<"===DBG mod on==="<<endl;
		cout<<"Here's your CFG"<<endl;
		for(int i=0;i<argc;i++){
			string nwstr=argv[i];
			cout<<'['<<nwstr<<']'<<endl;
		}
		cout<<"===Code start==="<<endl;
	}
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

	auto solve=[](INT casenum){
		while(1){}
		INT px,py;
		INT ax,ay;
		INT bx,by;
		cin>>px>>py;
		cin>>ax>>ay;
		cin>>bx>>by;

		long double ato0=sqrt(ax*ax+ay*ay);
		long double atop=sqrt(
			(px-ax)*(px-ax)+
			(py-ay)*(py-ay)
		);
		long double bto0=sqrt(bx*bx+by*by);
		long double btop=sqrt(
			(px-bx)*(px-bx)+
			(py-by)*(py-by)
		);
		long double atob=sqrt(
			(ax-bx)*(ax-bx)+
			(ay-by)*(ay-by)
		)/2;
		long double ans=1e5+7;
		ans=min(ans,max(ato0,atop));//only use a
		ans=min(ans,max(bto0,btop));//only use b
		ans=min(ans,max(max(ato0,atob),btop));//0->a->b->p
		ans=min(ans,max(max(atop,atob),bto0));//0->b->a->p
		cout<<fixed<<setprecision(10)<<ans<<endl;
		return 0;
	};
	bool one_case=0;
	bool ynans=0;
	bool eof=0;
	string yes="YES";
	string no="NO";
	INT t=(one_case?1:read(int));
	for(INT i=0;eof || i<t;i++){
		INT re=solve(i);
		if(!ynans){
			if(re==-1)return 0;
		}else{
			if(re==1){
				cout<<yes<<endl;
			}else if(re==0){
				cout<<no<<endl;
			}else{
				return 0;
			}
		}
	}
	return 0;
}