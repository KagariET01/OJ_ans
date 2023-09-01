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
	INT t=1;
	map<string,INT> mp;
	mp["win"]=2;
	mp["tie"]=0;
	mp["lose"]=1;
	char RPS[]={'R','P','S'};
	while(t--){
		INT n;
		cin>>n;
		vector<INT> vec[3];
		vec[0].reserve(n);
		vec[1].reserve(n);
		vec[2].reserve(n);
		INT me='R';
		char ans[3];
		for(INT i=2;i<=n;i++){
			cout<<"? "<<1<<" "<<i<<" "<<RPS[me]<<endl;
			string inin;
			cin>>inin;
			vec[mp[inin]].push_back(i);
		}
		for(INT i=0;i<2;i++){
			if(vec[i].size()>=2){
				cout<<"? "<<vec[i][0]<<" "<<vec[i][1]<<" "<<RPS[me]<<endl;
				string inin;
				cin>>inin;
				ans[i]=me+mp[inin];

				break;
			}
		}

	}
	return 0;
}
//#endif
