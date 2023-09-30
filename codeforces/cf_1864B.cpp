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

INT lowbit(INT n){
	return n&(-n);
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
		INT n,k;
		cin>>n>>k;
		string s=read(string);
		if(k%2){
			string a[2];
			a[0].reserve(n/2+1);
			a[1].reserve(n/2);
			for(INT i=0;i<n;i++){
				a[i%2].push_back(s[i]);
			}
			sort(a[0].begin(),a[0].end());
			sort(a[1].begin(),a[1].end());
			s="";
			s.reserve(n);
			for(INT i=0;i<a[0].size() || i<a[1].size();i++){
				if(i<a[0].size())
					s.push_back(a[0][i]);
				if(i<a[1].size())
					s.push_back(a[1][i]);
			}
		}else{

			sort(s.begin(),s.end());
		}
		cout<<s<<endl;
	}
	return 0;
}
//#endif
