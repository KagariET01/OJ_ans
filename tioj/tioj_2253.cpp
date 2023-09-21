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

const INT mxn=2000+5;
const INT mxm=8000+5;
const INT mxk=mxn;
INT n,m,k;//都市數量（點數）,道路數,道路中間村莊數
INT c[mxm][mxn];//邊[i]中的點[j]的花費
INT ctt[mxm];//每條邊的所有子點相加（包含尾站）
vector<INT> tre[mxn];//tre[i]可走到...(紀錄編號)
INT x[mxm],y[mxm];

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
		//cin
		cin>>n>>m>>k;
		for(INT i=1;i<=n;i++){
			cin>>c[0][i];
		}
		for(INT i=1;i<=m;i++){
			cin>>x[i]>>y[i];
			w[i]=c[0][y[i]];
			for(INT j=1;j<=k;j++){
				cin>>c[i][j];
				w[i]+=c[i][j];
			}
			tre[x[i]].push_back(i);
		}
		//cout
	}
	return 0;
}
//#endif
