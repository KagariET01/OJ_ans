/*
[AC]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
bool debug=0;
template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}
INT n,w;
const INT mxn=1e6;
INT a[mxn+1],b[mxn+1];
INT pze[mxn+1];
bool solve(INT t){
	if(t==0)return true;
	priority_queue<INT> pq;
	INT pqs=0;
	INT cst=0;
	for(INT i=0;i<n;i++){
		INT nwp=a[i]+b[i]*t;
		if(pqs<t){
			pq.push(nwp);
			pqs++;
			cst+=nwp;
		}else if((pq.top())>nwp){
			cst-=(pq.top());
			pq.pop();
			pq.push(nwp);
			cst+=nwp;
		}
	}

	DBG cerr<<"t="<<t<<" cst="<<cst<<endl;
	return w>=cst;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=1;
	while(t--){
		cin>>n>>w;
		bool cse1=1,cse2=1;
		for(INT i=0;i<n;i++){
			cin>>a[i]>>b[i];
			if(a[i])cse1=0;
			if(b[i])cse2=0;
		}
		if(cse1){
			sort(b,b+n);
			INT nwans=0;
			INT badd=0;
			for(INT i=0;i<n;i++){
				badd+=b[i];
				if(badd*(i+1)<=w)nwans++;
				else break;
			}
			cout<<nwans<<endl;
			continue;
		}else if(cse2){
			sort(a,a+n);
			INT nwans=0;
			INT badd=0;
			for(INT i=0;i<n;i++){
				badd+=a[i];
				if(badd<=w)nwans++;
				else break;
			}
			cout<<nwans<<endl;
			continue;
		}else{
			INT l=0,r=n+1;//購買水晶數量
			while(r>l){
				INT mnt=(l+r)/2;
				if(solve(mnt))l=mnt+1;
				else r=mnt;
			}
			cout<<r-1<<endl;
		}
	}
	return 0;
}