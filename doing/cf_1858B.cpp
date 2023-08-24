/*
[q]
[]
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
		INT n,m,d;
		cin>>n>>m>>d;
		INT s[m+1]={};
		s[0]=1;
		for(INT i=1;i<=m;i++){
			cin>>s[i];
			if(s[i]==1){
				i--;
				m--;
			}
		}
		INT ms=1e9;
		INT se=0;
		for(INT i=1;i<=m;i++){
			INT nw=0;
			for(INT j=0;j<=m;j++){
				if(i==j)continue;
				if(j==0){
					nw++;
					continue;
				}
				INT bef=j-1;
				if(bef==i){
					bef--;
				}
				nw+=(s[j]-s[bef]-1)/d;
				nw++;
			}
			INT bef=m;
			if(bef==i)bef--;
			nw+=(n-s[bef])/d;
			DBG cerr<<"nw="<<nw<<"ms="<<ms<<"se="<<se<<endl;
			if(nw<ms){
				ms=nw;
				se=0;
			}
			if(nw==ms){
				se++;
			}
		}
		cout<<ms<<" "<<se<<endl;
	}
	return 0;
}
//#endif
