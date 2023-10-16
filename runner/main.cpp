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

	auto solve=[](INT casenum){
		string str=read(string);
		INT q=read(INT);
		INT n=str.size();
		INT lst[n]={};
		INT nwnm=1;
		stack<pair<char,INT>> st;
		for(INT i=0;i<n;i++){
			while(!st.empty()){
				pair<char,INT> nw=st.top();
				if(nw.first>str[i]){
					lst[nw.second]=nwnm;
					nwnm++;
					st.pop();
				}else break;
			}
			st.push({str[i],i});
			continue;
		}
		while(!st.empty()){
			pair<char,INT> nw=st.top();
			lst[nw.second]=nwnm;
			nwnm++;
			st.pop();
		}
		INT nwmm=n;
		INT qid=0;
		while(nwmm<q){
			q-=nwmm;
			qid++;
			nwmm--;
		}
		DBG cerr<<"q="<<q<<endl;
		INT i=0;
		for(INT i=0;i<n;i++){
			q-=(lst[i]>qid)?1:0;
			if(!q){
				cout<<str[i];
				DBG cerr<<endl;
				return 0;
			}
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