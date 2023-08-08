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
		INT n;
		cin>>n;
		INT a[n];
		INT b[n];
		for(INT i=0;i<n;i++){
			cin>>a[i];
		}
		for(INT i=0;i<n;i++){
			cin>>b[i];
		}
		PII c[n];
		for(INT i=0;i<n;i++){
			c[i]={a[i]-b[i],i};
		}
		sort(c,c+n);
		INT ansc=0;
		for(INT i=n-1;i>=0;i--){
			if(c[i].first==c[n-1].first){
				ansc++;
			}else break;
		}
		cout<<ansc<<endl;
		for(INT i=n-ansc,cnt=0;cnt<ansc;i++,cnt++){
			if(cnt)cout<<" ";
			cout<<c[i].second+1;
		}
		cout<<endl;
	}
	return 0;
}
//#endif
