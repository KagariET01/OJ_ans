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

	function<int(INT)> solve=[](INT casenum){
		INT n,a,b;
		string q;
		cin>>n>>a>>b>>q;
		INT alladd=a;
		INT nw=a;
		INT ans=0;
		if(nw>=n){
			ans=2;
			cout<<"YES"<<endl;
			return 0;
		}
		if(alladd>=n){
			ans=1;
		}
		for(char c:q){
			if(c=='+'){
				alladd++;
				nw++;
				if(nw>=n){
					ans=2;
					break;
				}
				if(alladd>=n){
					ans=1;
				}
			}else{
				nw--;
			}
			DBG cout<<"alladd="<<alladd<<" nw="<<nw<<" ans="<<ans<<endl;
		}
		switch(ans){
			case 0:
				cout<<"NO"<<endl;
			break;
			case 1:
				cout<<"MAYBE"<<endl;
			break;
			case 2:
				cout<<"YES"<<endl;
			break;
		}
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
	cout<<endl;
	return 0;
}