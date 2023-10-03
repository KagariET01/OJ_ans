/*
[q]
[想法][greedy][math]
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
		INT n,m,d;
		cin>>n>>m>>d;
		vector<INT> s;
		s.push_back(1-d);//1那一格也要被算到，所以我們假設他從1-d那邊走過來，然後到1的時候肚子餓，吃了一快餅乾
		INT orig=0;
		for(INT i=0;i<m;i++){
			s.push_back(read(INT));
		}
		s.push_back(n+1);//他還要走出n這個空間，也就是說他要到達n+1才算離開
		for(INT i=1;i<m+2;i++){
			orig+=(s[i]-s[i-1]-1)/d;//計算每個區間中會吃的餅乾數
		}
		orig+=m;//計算攤位給的餅乾數(一個攤位給一個)
		INT ans=1e9;
		INT c=0;
		for(INT i=1;i<=m;i++){//現在總共有m+2項，第0,m+1項是頭尾，我們可以刪除1~m項
			INT A=s[i+1]-s[i-1]-1;//新區間
			A/=d;
			INT B=s[i+1]-s[i]-1;//舊區間(右
			B/=d;
			INT C=s[i]-s[i-1]-1;//舊區間(左
			C/=d;
			INT D=A-B-C-1;
			if(D<ans){
				ans=D;
				c=0;
			}
			if(D<=ans){
				c++;
			}
		}
		cout<<orig+ans<<" "<<c<<endl;
		DBG cerr<<"ans="<<ans<<" orig="<<orig<<endl;
	}
	return 0;
}
//#endif
