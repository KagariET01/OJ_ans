/*
[q]
[graph]
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
		INT n1,n2,m;
		cin>>n1>>n2>>m;
		vector<INT> vec[n1+n2+5];
		for(INT i=0;i<m;i++){
			INT a,b;
			cin>>a>>b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		INT path[n1+n2+5];
		memset(path,0,sizeof(path));
		path[1]=1;
		path[n1+n2]=1;
		deque<INT> dq;
		dq.push_back(1);
		dq.push_back(n1+n2);
		INT lans=0,rans=0;
		while(!dq.empty()){
			INT nw=dq.front();
			dq.pop_front();
			for(INT i:vec[nw]){
				if(path[i])continue;
				path[i]=path[nw]+1;
				dq.push_back(i);
			}
			if(nw<=n1){
				lans=max(lans,path[nw]);
			}else{
				rans=max(rans,path[nw]);
			}
		}
		DBG{
			for(INT i=1;i<=n1+n2;i++){
				cerr<<path[i]<<" ";
			}
			cerr<<endl;
		}
		cout<<lans+rans-1<<endl;
	}
	return 0;
}
//#endif
