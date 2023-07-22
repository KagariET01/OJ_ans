/*
[q]
[grapth 圖論]
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
	INT t=1;
	while(t--){
		INT n;
		cin>>n;
		INT a[n+5];
		for(INT i=1;i<=n;i++){
			cin>>a[i];
		}
		vector<INT> ansb;
		INT ansm=0;
		vector<INT> path;
		path.resize(n+5);
		INT road[n+5];
		memset(road,0,sizeof(road));
		for(INT i=1;i<=n;i++){
			if(road[i])continue;
			INT nw=i;
			INT count=0;
			while(true){
				if(road[nw]==-1){
					break;
				}else if(road[nw]){
					INT nwans=count-road[nw];
					if(nwans>ansm){
						ansm=nwans;
						ansb.resize(ansm);
						for(INT j=0;j<nwans;j++){
							ansb[j]=nw;
							nw=a[nw];
						}
					}
					break;
				}else{
					road[nw]=count;
					path[count]=nw;
					count++;
					nw=a[nw];
				}
			}
			for(INT j=0;j<count;j++){
				road[path[j]]=-1;
			}
		}
		cout<<ansm<<endl;
		for(INT i=0;i<ansm;i++){
			if(i)cout<<" ";
			cout<<ansb[i];
		}
	}
	return 0;
}
//#endif
