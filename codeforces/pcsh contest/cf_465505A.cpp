/*
[q]https://codeforces.com/group/VEc3guEDmO/contest/465505/problem/A
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
#define PII pair<INT,INT>
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

bool vser(PII a,PII b){//{藝人得幾顆,剩多少
	if(a.second!=b.second){
		return a.second<b.second;
	}else{
		return a.first<b.first;
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
		INT n,k;
		cin>>n>>k;
		vector<PII> vec;
		vec.reserve(n);
		for(INT i=0;i<n;i++){
			INT inin=read(INT);
			vec.push_back({inin/k,inin%k});
		}
		sort(vec.begin(),vec.end(),vser);
		for(INT i=0;i<n;i++){
			if(i)cout<<" ";
			cout<<(vec[i].first*k+vec[i].second);
		}
		cout<<endl;
	}
	return 0;
}
//#endif
