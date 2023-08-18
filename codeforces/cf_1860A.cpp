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
		string str=read(string);
		INT n=str.size();
		bool t1=1;//()()...
		bool t2=1;//)()(...
		bool t3=1;//((...))
		for(INT i=0;i<n;i++){
			if(i%2){
				if(str[i]!=')'){
					t1=0;
					break;
				}
			}else{
				if(str[i]!='('){
					t1=0;
					break;
				}
			}
		}
		for(INT i=0;i<n;i++){
			if(i%2){
				if(str[i]!='('){
					t2=0;
					break;
				}
			}else{
				if(str[i]!=')'){
					t2=0;
					break;
				}
			}
		}
		bool sw=0;
		for(INT i=0;i<n;i++){
			if(!sw){
				if(str[i]==')'){
					sw=1;
				}
			}else{
				if(str[i]!=')'){
					t3=0;
					break;
				}
			}
		}
		if(!t1 && !t2){
			cout<<"YES"<<endl;
			for(INT i=0;i<n;i++){
				cout<<"()";
			}
			cout<<endl;
		}else if(!t3){
			cout<<"YES"<<endl;
			for(INT i=0;i<n;i++){
				cout<<"(";
			}
			for(INT i=0;i<n;i++){
				cout<<")";
			}
			cout<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
//#endif
