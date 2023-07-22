/*
[q]
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
	INT t=1;
	while(t--){
		INT n,d;
		cin>>n>>d;
		bool dta[d];
		memset(dta,1,sizeof(dta));
		for(INT i=0;i<n;i++){
			string str;
			cin>>str;
			for(INT j=0;j<d;j++){
				if(str[j]=='x'){
					dta[j]=0;
				}
			}
		}
		INT ans=0;
		INT nw=0;
		for(INT i=0;i<d;i++){
			if(dta[i]){
				nw++;
			}else{
				ans=max(ans,nw);
				nw=0;
			}
		}
		ans=max(ans,nw);
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
