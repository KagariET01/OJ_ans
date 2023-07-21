/*
[q]
[BIT search]
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

vector<INT> a;
INT n;
INT findans(INT k){
	INT nw=0;
	for(INT i=0;i<n;i++){
		if(nw<k)nw+=a[i];
		else nw=max(k,nw+a[i]);
	}
	return nw;
}

INT solve(INT r){
	if(false){
		for(INT i=0;i<=r;i++){
			cerr<<"i:"<<i<<" ans="<<findans(i)<<endl;
		}
		return 0;
	}else{
		INT l=0;
		for(INT i:a){
			if(i<0)break;
			l+=i;
		}
		INT root=findans(0);
		while(l<r){
			DBG cerr<<"l:"<<l<<"r:"<<r<<endl;	
			INT mnta=(r-l)/3+l;
			INT nwansa=findans(mnta);
			INT mntb=(r-l)*2/3+l;
			INT nwansb=findans(mnta);
			
			if(nwansa<nwansb)l=mnta;
			else if(nwansa>=nwansb)r=mnta;
		}
		return r;
	}
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	while(t--){
		cin>>n;
		a.resize(n);
		INT bigr=0;
		bool allb=1;
		bool alls=1;
		for(INT i=0;i<n;i++){
			cin>>a[i];
			bigr+=abs(a[i]);
			allb&=(a[i]>=0);
			alls&=(a[i]<=0);
		}
		if(allb || alls)cout<<0<<endl;
		else cout<<solve(bigr)<<endl;
	}
	return 0;
}
//#endif
