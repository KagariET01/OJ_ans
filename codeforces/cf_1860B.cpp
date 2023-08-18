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
		INT n,k,a1,ak;
		cin>>n>>k>>a1>>ak;
		INT ans=0;
		INT aneed=n%k;
		if(a1>=aneed){
			n-=aneed;
			a1-=aneed;
		}else{
			ans+=aneed-a1;
			a1=0;
		}
		n-=n%k;
		DBG cerr<<"n="<<n<<" ans="<<ans<<endl;
		ak+=a1/k;
		n/=k;
		INT kneed=n;
		if(kneed){
			if(ak>=kneed){
				n=0;
			}else{
				ans+=n-ak;
				n=0;
			}
		}
		cout<<ans<<endl;



	}
	return 0;
}
//#endif
