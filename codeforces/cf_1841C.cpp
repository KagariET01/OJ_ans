/*
[q]
[greedy]
[AC]
*/
//#ifndef eval
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}
string str;
INT n;
INT swaper[]={1,10,100,1000,10000};

INT countv(){
	INT re=0;
	INT x=1;
	char mxc='A';
	for(INT i=n-1;i>=0;i--){
		if(str[i]<mxc){
			re-=swaper[str[i]-'A'];
		}
		else{
			re+=swaper[str[i]-'A'];
		}
		mxc=max(mxc,str[i]);
	}
	return re;
}

INT solve(){
	INT re=-1e9;
	//將前面第1個出現的'A'交換
	for(char i='A';i<='E';i++){
		INT j=0;
		while(j<n && str[j]!=i)j++;
		if(j>=n)continue;
		for(char k='A';k<='E';k++){
			str[j]=k;
			INT nw=countv();
			DBG cerr<<"change["<<i<<"]to["<<k<<"]="<<str<<":"<<nw<<endl;
			re=max(re,nw);
		}
		str[j]=i;
	}
	for(char i='A';i<='E';i++){
		INT j=n-1;
		while(j>=0 && str[j]!=i)j--;
		if(j<0)continue;
		for(char k='A';k<='E';k++){
			str[j]=k;
			INT nw=countv();
			DBG cerr<<"change["<<i<<"]to["<<k<<"]="<<str<<":"<<nw<<endl;
			re=max(re,nw);

		}
		str[j]=i;
	}
	return re;
}

int main(int argc,char** argv){
	for(int i=0;i<argc;i++){
		string nwstr=argv[i];
		if(nwstr=="-Dev"){
			debug=1;
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
		cin>>str;
		n=str.size();
		cout<<solve()<<endl;
	}
	return 0;
}
//#endif
