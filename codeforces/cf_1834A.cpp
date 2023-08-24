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
	INT t=read(INT);
	while(t--){
		INT n;
		cin>>n;
		DBG cerr<<"n="<<n<<endl;
		INT mn=0,mx=0;
		for(INT i=0;i<n;i++){
			INT inin=read(INT);
			if(inin==-1)mn++;
			else mx++;
		}
		
		INT ans=0;
		INT x=mn-mx;
		if(x>0){
			x=x/2+x%2;
			ans+=x;
			mn-=x;
			mx+=x;
		}
		if(mn%2){
			ans++;
			mn--;
			mx++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
