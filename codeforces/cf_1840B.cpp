/*
[q]
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
#define PII pair<INT,INT>
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

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
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
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
	INT t=read(int);
	while(t--){
		INT n,k;
		cin>>n>>k;
		INT nwbit=1<<(min((INT)30,k-1));
		INT ans=1;
		n=min(n,(nwbit<<1)-1);
		DBG{
			cerr<<"start"<<endl;
			cerr<<"n="<<n<<" nwbot="<<nwbit<<" ans="<<ans<<endl;
		}
		for(;nwbit>0;nwbit>>=1){
			DBG cerr<<"n="<<n<<" nwbot="<<nwbit<<" ans="<<ans<<endl;
			if(n&nwbit){
				ans+=nwbit;
				n^=nwbit;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
