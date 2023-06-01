/*
[q]https://neoj.sprout.tw/problem/431/
[AC]
[tree]
[最短路徑]
[Dijkstra]
*/
//#ifndef eval
#include<bits/stdc++.h>
using namespace std;
#define INT unsigned long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
bool debug=0;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=1;
	while(t--){
		INT n,m,q;
		cin>>n>>m>>q;
		vector<PII> tre[n+1];//做一次最短路，從1到所有點
		vector<PII> bktre[n+1];//再做一次最短路，從所有點到N
		
		for(INT i=0;i<m;i++){
			INT a,b,w;
			cin>>a>>b>>w;
			tre[a].push_back(make_pair(b,w));
			bktre[b].push_back(make_pair(a,w));
		}
		
		INT road[n+1];
		fill(road,road+n+1,1e16);road[1]=0;
		INT visit[n+1];
		memset(visit,0,sizeof(visit));
		priority_queue<PII,vector<PII>,greater<PII>> pq;
		pq.push(make_pair(0,1));
		
		INT bkroad[n+1];
		fill(bkroad,bkroad+n+1,1e16);bkroad[n]=0;
		INT bkvisit[n+1];
		memset(bkvisit,0,sizeof(bkvisit));
		priority_queue<PII,vector<PII>,greater<PII>> bkpq;
		bkpq.push(make_pair(0,n));
		

		while(!pq.empty()){
			INT nw=pq.top().second;
			pq.pop();
			if(visit[nw])continue;
			for(PII i:tre[nw]){
				if(road[i.first]>road[nw]+i.second){
					road[i.first]=road[nw]+i.second;
					pq.push(make_pair(road[i.first],i.first));
				}
			}
			visit[nw]=1;
		}
		INT nwmn=road[n];

		DBG{
			for(INT i=1;i<=n;i++){
				cerr<<road[i]<<" ";
			}
			cerr<<endl;
		}

		while(!bkpq.empty()){
			INT nw=bkpq.top().second;
			bkpq.pop();
			DBG cerr<<"now in "<<nw<<endl;
			if(bkvisit[nw])continue;
			DBG cerr<<"now in "<<nw<<endl;
			for(PII i:bktre[nw]){
				DBG cerr<<nw<<" to "<<i.first<<endl;
				if(bkroad[i.first]>bkroad[nw]+i.second){
					bkroad[i.first]=bkroad[nw]+i.second;
					bkpq.push(make_pair(bkroad[i.first],i.first));
				}
			}
			bkvisit[nw]=1;
		}

		DBG{
			for(INT i=1;i<=n;i++){
				cerr<<bkroad[i]<<" ";
			}
			cerr<<endl;
		}


		while(q--){
			INT a,b;cin>>a>>b;
			cout<<min(road[n],road[a]+1+bkroad[b])<<endl;
		}
	

	}
	return 0;
}
//#endif

/*
[I1]
6 5 3
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
2 5
1 6
3 2
[O1]
3
1
5
*/
