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
		INT n,m,k;
		cin>>n>>m>>k;
		INT ans=0;
		INT last=-1;
		priority_queue<INT,vector<INT>,greater<INT>> wq;
		INT wquse=0;
		INT wqtt=0;
		priority_queue<INT,vector<INT>,greater<INT>> pq;
		for(INT i=0;i<n;i++){
			INT inin=read(INT);
			INT add=0;
			if(pq.size()<m){
				add=inin;
			}else{
				add=inin-pq.top();
			}
			add-=(i-last)*k;
			if(add>0){
				ans+=add;
				pq.push(inin);
				last=i;
				if(pq.size()>m)pq.pop();


				while(!wq.empty() && pq.size()<m){
					ans+=wq.top();
					pq.push(wq.top());
					wq.pop();
				}
				while(!wq.empty() && wq.top()>pq.top()){
					ans+=wq.top();
					ans-=pq.top();
					pq.pop();
					pq.push(wq.top());
					wq.pop();
				}
			}else if(inin>0){
				wq.push(inin);
			}
			while(wq.size()>m-pq.size()){
				wqtt-=wq.top();
				wq.pop();
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
