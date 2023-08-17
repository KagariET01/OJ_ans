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
bool debug=0;
bool noTLE=0;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

set<char> se;
vector<string> alls;
set<char> vec;
vector<char> vec2;
INT n;
string ans="00000";
string toout_2="00000";
bool sel[5];

template<typename TPE>void coutall(TPE l,TPE r){
	while(l!=r){
		cout<<*l<<" ";
		l++;
	}
	cout<<endl;
}

void solve1(){//找出所有答案的字元
	string toout="aaaaa";
	INT it=0;
	for(char c:se){
		toout[it]=c;
		it++;
		if(it==5){
			cout<<toout<<endl;//暴力尋找所有可能的字元
			string inin=read(string);
			for(INT i=0;i<5;i++){
				if(inin[i]=='1'){
					vec.insert(toout[i]);
				}else if(inin[i]=='2'){
					ans[i]=toout[i];
					vec.insert(toout[i]);
				}
			}
		}
	}
	if(it){
		cout<<toout<<endl;
		string inin=read(string);
		for(INT i=0;i<it;i++){
			if(inin[i]=='1'){
				vec.insert(toout[i]);
			}else if(inin[i]=='2'){
				ans[i]=toout[i];
				vec.insert(toout[i]);
			}
		}
	}
}

void solve2(){//答案可能會有一個字元出現多次的情況
	for(char c:vec){
		for(INT i=0;i<5;i++){
			cout<<c;
		}
		cout<<endl;
		string inin=read(string);
		for(INT i=0;i<5;i++){
			if(inin[i]=='1'){
				vec2.push_back(c);
			}else if(inin[i]=='2'){
				ans[i]=c;
			}
		}
	}
}

void solve3(INT index=0){
	if(index==5){
		cout<<toout_2<<endl;
		string inin=read(string);
		for(INT i=0;i<5;i++){
			if(inin[i]=='2'){
				ans[i]=toout_2[i];
			}
		}
	}else{
		for(INT i=0;i<vec2.size();i++){
			if(ans[index]!='0')break;
			if(sel[i])continue;
			sel[i]=1;
			toout_2[index]=vec2[i];
			solve3(index+1);
			sel[i]=0;
		}
		toout_2[index]=ans[index];
		solve3(index+1);
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
	cin>>n;
	alls.reserve(n);
	for(INT i=0;i<n;i++){
		alls.push_back(read(string));
		for(INT j=0;j<5;j++){
			se.insert(alls[i][j]);
		}
	}
	DBG cerr<<"solve1"<<endl;
	solve1();
	DBG{
		cout<<"============"<<endl;
		cout<<"vec: ";
		coutall(vec.begin(),vec.end());
		cout<<"ans: "<<ans<<endl;
	}
	DBG cerr<<"solve2"<<endl;
	solve2();
	DBG{
		cout<<"============"<<endl;
		cout<<"vec: ";
		coutall(vec.begin(),vec.end());
		cout<<"vec2: ";
		coutall(vec2.begin(),vec2.end());
		cout<<"ans: "<<ans<<endl;
	}
	DBG cerr<<"solve3"<<endl;
	solve3();
	DBG{
		cout<<"============"<<endl;
		cout<<"vec: ";
		coutall(vec.begin(),vec.end());
		cout<<"vec2: ";
		coutall(vec2.begin(),vec2.end());
		cerr<<"ans="<<ans<<endl;
	}
	return 0;
}
//#endif
