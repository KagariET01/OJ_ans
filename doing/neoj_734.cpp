/*
[q]https://neoj.sprout.tw/challenge/255592/
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
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

vector<INT> vec;

void reserve(INT n){
	vec.resize(n);
	for(INT i=0;i<n;i++){
		vec[i]=i;	
	}
}

INT fboss(INT n){
	if(vec[n]==n){
		return n;
	}else{
		vec[n]=fboss(vec[n]);
		return vec[n];
	}
}

void dmerge(INT a,INT b){
	a=fboss(a);
	b=fboss(b);
	vec[a]=b;
}

struct dta{
	INT u,v,w;
};

dta mkdta(INT a,INT b,INT c){
	dta re;
	re.u=a;
	re.v=b;
	re.w=c;
	return re;
}

bool operator>(const dta &a,const dta &b){
	return a.w>b.w;
}
bool operator>=(const dta &a,const dta &b){
	return a.w>=b.w;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=1;
	while(t--){
		INT N,M;
		cin>>N>>M;
		DBG cerr<<"N M="<<N<<" "<<M<<endl;
		priority_queue<dta,vector<dta>,greater<dta>> pq;
		for(INT i=0;i<M;i++){
			dta ndta;
			cin>>ndta.u>>ndta.v>>ndta.w;
			DBG cerr<<"u v w="<<ndta.u<<" "<<ndta.v<<" "<<ndta.w<<endl;
			pq.push(ndta);
		}
		reserve(N+1);
		INT ans=0;
		INT lst=N-1;
		while(lst && !pq.empty()){
			dta nw=pq.top();
			pq.pop();
			INT pa=nw.u;
			INT pb=nw.v;
			INT ww=nw.w;
			DBG cerr<<"nw: "<<nw.u<<" >"<<nw.v;
			DBG cerr<<" paboss="<<fboss(pa)<<" pbboss="<<fboss(pb);
			if(fboss(pa)!=fboss(pb)){
				
				ans+=ww;
				DBG cerr<<" add "<<ww;
				lst--;
				dmerge(pa,pb);
			}
			DBG cerr<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
