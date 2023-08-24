/*
[q]
[未分類]
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
	INT t=1;
	while(t--){
		INT h,w;
		cin>>h>>w;
		char c[h][w];
		for(INT i=0;i<h;i++){
			string str=read(string);
			for(INT j=0;j<w;j++){
				c[i][j]=str[j];
			}
		}
		INT xc[h][26]={};
		INT yc[w][26]={};
		for(INT i=0;i<h;i++){
			for(INT j=0;j<w;j++){
				xc[i][c[i][j]-'a']++;
				yc[j][c[i][j]-'a']++;
			}
		}
		INT rn=h+w;
		INT ansh=h,answ=w;
		bool xdel[h]={},ydel[w]={};
		while(rn--){
			vector<PII> xbye,ybye;
			for(INT i=0;answ>=2 && i<h;i++){
				if(xdel[i])continue;
				for(INT j=0;j<26;j++){
					if(xc[i][j]==answ && answ>=2){
						xbye.push_back({i,j});
						break;
					}
				}
			}
			for(INT i=0;ansh>=2 && i<w;i++){
				if(ydel[i])continue;
				for(INT j=0;j<26;j++){
					if(yc[i][j]==ansh && ansh>=2){
						ybye.push_back({i,j});
						break;
					}
				}
			}
			for(PII i:xbye){
				ansh--;
				xdel[i.first]=1;
				DBG{
					cerr<<"xbye {"<<i.first<<","<<i.second<<"}"<<endl;
				}
				for(INT j=0;j<w;j++){
					yc[j][i.second]--;
				}
			}
			for(PII i:ybye){
				answ--;
				ydel[i.first]=1;
				DBG{
					cerr<<"ybye {"<<i.first<<","<<i.second<<"}"<<endl;
				}
				for(INT j=0;j<h;j++){
					xc[j][i.second]--;
				}
			}
			if(xbye.empty() && ybye.empty()){
				break;
			}
		}
		cout<<ansh*answ<<endl;
	}
	return 0;
}
//#endif
