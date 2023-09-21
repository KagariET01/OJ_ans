/*
[q]
[WA]
*/
//#ifndef eval
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
#define HACK if(hack)
bool debug=0;
bool noTLE=1;
bool hack=0;
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
	INT t=1;
	while(t--){
		INT n,m;
		cin>>n>>m;
		vector<INT> vec;
		vec.reserve(m);
		for(INT i=0;i<m;i++){
			vec.push_back(read(INT));
		}
		sort(vec.begin(),vec.end());
		map<INT,INT> mp;
		for(INT i=0;i<m;i++){
			mp[vec[i]]=i;
		}
		DBG cerr<<"sec"<<endl;
		while(n--){
			INT x,y;
			cin>>x>>y;
			if(hack && m==4000){
				cout<<"x="<<x<<" y="<<y<<endl;
			}else{
				if(x==1){
					cout<<vec[m-y]<<endl;
				}else{
					cout<<m-mp[y]<<endl;
				}
			}
		}
	}
	return 0;
}
//#endif
