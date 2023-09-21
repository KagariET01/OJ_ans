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
#define XY(n) n.first][n.second
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

PII mv[]={
	{1,0},
	{-1,0},
	{0,1},
	{0,-1}
};

PII operator+(const PII a,const PII &b){
	return make_pair(a.first+b.first,a.second+b.second);
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
		PII st={0,0},ed={0,0};
		string mp[h];
		for(INT i=0;i<h;i++){
			cin>>mp[i];
		}

		//build
		for(INT i=0;i<h;i++){//S,G
			for(INT j=0;j<w;j++){
				if(mp[i][j]=='S'){
					st={i,j};
				}else if(mp[i][j]=='G'){
					ed={i,j};
				}
			}
		}

		for(INT i=0;i<h;i++){//>
			bool fire=0;
			for(INT j=0;j<w;j++){
				if(mp[i][j]=='>')fire=1;
				else if(fire && mp[i][j]=='.')mp[i][j]='X';
				else if(fire && mp[i][j]!='X')fire=0;
			}
		}
		for(INT i=0;i<h;i++){
			bool fire=0;
			for(INT j=w-1;j>=0;j--){
				if(mp[i][j]=='<')fire=1;
				else if(fire && mp[i][j]=='.')mp[i][j]='X';
				else if(fire && mp[i][j]!='X')fire=0;
			}
		}
		for(INT j=0;j<w;j++){
			bool fire=0;
			for(INT i=0;i<h;i++){
				if(mp[i][j]=='v')fire=1;
				else if(fire && mp[i][j]=='.')mp[i][j]='X';
				else if(fire && mp[i][j]!='X')fire=0;
			}
		}
		for(INT j=0;j<w;j++){
			bool fire=0;
			for(INT i=h-1;i>0;i--){
				if(mp[i][j]=='^')fire=1;
				else if(fire && mp[i][j]=='.')mp[i][j]='X';
				else if(fire && mp[i][j]!='X')fire=0;
			}
		}
		for(INT i=0;i<h;i++){//S,G
			for(INT j=0;j<w;j++){
				if(mp[i][j]=='S'){
					st={i,j};
				}else if(mp[i][j]=='G'){
					ed={i,j};
				}
			}
		}
		DBG{
			for(INT i=0;i<h;i++){
				cerr<<mp[i]<<endl;
			}
		}
		INT ans[h][w];
		memset(ans,h*w+5,sizeof(ans));
		ans[XY(st)]=0;
		deque<PII> dq;
		dq.push_back(st);
		bool ha=0;
		while(!dq.empty()){
			PII nw=dq.front();
			dq.pop_front();
			if(nw==ed){
				ha=1;
				break;
			}
			for(INT i=0;i<4;i++){
				PII nxt=nw+mv[i];
				if(0<= nxt.first && nxt.first<h){
					if(0<=nxt.second && nxt.second<w){
						if(mp[XY(nxt)]=='.' || mp[XY(nxt)]=='G'){
							if(ans[XY(nxt)]>ans[XY(nw)]+1){
								ans[XY(nxt)]=ans[XY(nw)]+1;
								dq.push_back(nxt);
							}
						}
					}
				}
			}
		}
		DBG{
			for(INT i=0;i<h;i++){
				for(INT j=0;j<w;j++){
					cerr<<ans[i][j]<<" ";
				}
				cerr<<endl;
			}
		}
		cout<<(ha?ans[XY(ed)]:-1)<<endl;
	}
	return 0;
}
//#endif
