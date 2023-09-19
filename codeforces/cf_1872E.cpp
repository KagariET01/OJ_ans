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
		INT n;
		cin>>n;
		INT a[n+1];
		for(INT i=1;i<=n;i++){
			cin>>a[i];
		}
		bool b[n+1];
		string str;
		cin>>str;
		for(INT i=1;i<=n;i++){
			b[i]=(str[i-1]=='1');
		}
		INT addall[n+1]={};
		INT ans[2]={};
		for(INT i=1;i<=n;i++){
			addall[i]=addall[i-1]^a[i];
			ans[b[i]]^=a[i];
		}
		INT q=read(INT);
		while(q--){
			INT inin=read(INT);
			if(inin==2){
				cout<<ans[read(INT)]<<" ";
			}else{
				INT l,r;
				cin>>l>>r;
				l--;
				ans[0]^=addall[r]^addall[l];
				ans[1]^=addall[r]^addall[l];
			}
		}
		cout<<endl;

	}
	return 0;
}
//#endif
