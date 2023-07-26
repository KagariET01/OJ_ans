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
		INT n,m;
		cin>>n>>m;
		vector<INT> vec[n+1];
		for(INT i=2;i<=n;i++){
			INT p;
			cin>>p;
			vec[p].push_back(i);
		}
		INT helpe[n+1];memset(helpe,0,sizeof(helpe));
		for(INT i=0;i<m;i++){
			INT x,y;
			cin>>x>>y;
			helpe[x]=max(helpe[x],y+1);//自己，還有下y代，假設y=0，helpe[x]=y不就變成0了ㄇ？，所以y+1
		}
		deque<INT> dq;
		dq.push_back(1);
		INT ans=0;
		while(!dq.empty()){
			INT nw=dq.front();
			dq.pop_front();
			if(helpe[nw]){
				ans++;
			}
			INT nxt=helpe[nw]-1;
			if(nxt<0)nxt=0;
			for(INT i:vec[nw]){
				helpe[i]=max(helpe[i],nxt);
				dq.push_back(i);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
