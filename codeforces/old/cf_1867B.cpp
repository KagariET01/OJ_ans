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
		string str;
		cin>>str;
		bool s[n];
		for(INT i=0;i<n;i++)s[i]=str[i]-'0';
		INT duo=0,sin=0;
		for(INT i=0;i<n/2;i++){
			if(s[i]==s[n-i-1])duo++;
			else sin++;
		}
		for(INT i=0;i<sin;i++){
			cout<<"0";
		}
		
		if(n%2){
			for(INT i=0;i<(duo+1)*2;i++){
				cout<<"1";
			}
		}else{
			for(INT i=0;i<duo+1;i++){
				if(i)cout<<"0";
				cout<<"1";
			}
		}


		for(INT i=0;i<sin;i++){
			cout<<"0";
		}
		cout<<endl;
	}
	return 0;
}
//#endif
