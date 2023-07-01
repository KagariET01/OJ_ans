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
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}













struct edge{
	INT x=0,y=0,v=0;
};
bool operator>(edge a,edge b){
	if(a.v==b.v)return a.x>b.x;
	return a.v>b.v;
}
const INT mxn=2e5;
INT dsu[mxn+5];
INT price[mxn+5];
INT ans=0;
INT k,n,m;
void dsu_init(INT n){
	for(INT i=0;i<n;i++){
		dsu[i]=i;
	}
}
INT dsu_fboss(INT n){
	if(dsu[n]==n)return n;
	else return dsu[n]=dsu_fboss(dsu[n]);
}
void dsu_mrg(INT a,INT b){
	a=dsu_fboss(a);
	b=dsu_fboss(b);
	if(a>b)swap(a,b);
	dsu[b]=a;
}

bool dsu_waslink(INT a,INT b){
	return dsu_fboss(a)==dsu_fboss(b);
}
edge mkedge(INT x,INT y,INT v){
	edge re;
	re.x=x;
	re.y=y;
	re.v=v;
	return re;
}



int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=1;
	while(t--){
		cin>>n>>k>>m;
		priority_queue<edge,vector<edge>,greater<edge>> pq;
		for(INT i=1;i<=k;i++){
			INT pz=read(INT);
			pq.push(mkedge(0,i,pz));
		}
		for(INT i=0;i<m;i++){
			edge ad;
			cin>>ad.x>>ad.y>>ad.v;
			pq.push(ad);
		}
		dsu_init(n+2);	
		while(!pq.empty()){
			edge nw=pq.top();
			pq.pop();
			if(dsu_fboss(nw.x)==dsu_fboss(nw.y))continue;
			ans+=nw.v;
			dsu_mrg(nw.x,nw.y);
		}
		for(INT i=1;i<=n;i++){
			if(dsu[i]>0){
				ans=-1;
				break;
			}
		}
		cout<<ans<<endl;

	}
	return 0;
}
//#endif
