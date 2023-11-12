<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 10` Codeforces Beta Round 10

[`back`](../)

## `CF 10 PA` Power Consumption Calculation

### `C++`

```c++
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

INT mod=998244353;

INT n,m,k;

INT checker(INT mx){
	INT r=m;
	INT re=0;
	for(INT i=1;i<=n;i++){
		while(i*r>mx)r--;
		re+=r;
		if(r==0)break;
	}
	return re;
}

INT BITsearch(INT l,INT r){
	while(l<r){
		INT mnt=(r-l)/2+l;
		if(checker(mnt)>=k){
			r=mnt;
		}
		else l=mnt+1;
	}
	return r;
}

int main(int argc,char** argv){
	auto solve=[](INT casenum){
		INT n,p1,p2,p3,t1,t2;
		cin>>n>>p1>>p2>>p3>>t1>>t2;
		INT ans=0;
		INT ll=-1,lr=-1;
		for(INT i=0;i<n;i++){
			INT l,r;
			cin>>l>>r;
			if(ll==-1){
				ans+=(r-l)*p1;
			}else{
				ans+=(r-l)*p1;
				ans+=min(max((l-lr),(INT)0),t1)*p1;
				ans+=min(max((l-lr-t1),(INT)0),t2)*p2;
				ans+=max((l-lr-t1-t2),(INT)0)*p3;
			}
			ll=l;lr=r;
		}
		cout<<ans<<endl;
		return 0;
	};
	bool one_case=1;
	bool ynans=0;
	string yes="yes";
	string no="no";
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=(one_case?1:read(int));
	for(INT i=0;i<t;i++){
		if(!ynans){
			solve(i);
		}else{
			if(solve(i)){
				cout<<yes<<endl;
			}else{
				cout<<no<<endl;
			}
		}
	}
	return 0;
}
```
