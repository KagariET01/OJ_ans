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

INT mod=998244353;

vector<INT> prime;
void build_prime(INT n){
	INT lst[n+1]={};
	for(INT i=2;i<=n;i++){
		if(!lst[i]){
			prime.push_back(i);
		}
		for(INT j:prime){
			if(i*j>n)break;
			lst[i*j]=j;
			if(j==i)break;
		}
	}
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


	build_prime(1000);
	auto solve=[](INT casenum){
		string str=read(string);
		for(INT i:prime){
			if(i<10)continue;
			string nw="";
			INT ii=i;
			while(ii){
				nw+=('0'+ii%10);
				ii/=10;
			}
			reverse(nw.begin(),nw.end());
			INT j=0;
			for(char c:nw){
				while(j<10 && str[j]!=c)j++;
				j++;
			}
			if(j>10){continue;}
			else{cout<<i<<endl;return 0;}
		}
		cout<<-1<<endl;
		return 0;
	};
	bool one_case=0;
	bool ynans=0;
	string yes="yes";
	string no="no";
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=(one_case?1:read(int));
	for(INT i=0;i<t;i++){
		if(!ynans){
			solve(i);
		}else{
			if(solve(i)){
				cout<<yes<<endl;
			}else{
				cout<<no<<endl;
			}
		}
	}
	return 0;
}
