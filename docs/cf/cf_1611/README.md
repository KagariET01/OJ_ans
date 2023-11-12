<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 1611` Codeforces Round 756 (Div. 3)

[`back`](../)

## [`CF 1611 PF`] ATM and Students
[`CF 1611 PF`]: https://codeforces.com/contest/1611/problem/F
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

const INT mxn=1e5;
INT lca[mxn+1][30];
INT n;
vector<INT> tre[mxn];
INT deep[mxn];

int main(int argc,char** argv){
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

	function<int(INT)> solve=[](INT casenum){
		INT n,m;
		cin>>n>>m;
		INT lst[n];
		for(INT i=0;i<n;i++){
			cin>>lst[i];
		}
		INT l=0;
		INT r=0;
		INT nw=m;
		INT ans=0;
		INT ansl=-1,ansr=-2;
		for(;r<n;r++){
			nw+=lst[r];
			while(l<=r && nw<0){
				nw-=lst[l];
				l++;
			}
			if((r-l)>(ansr-ansl)){
				ansr=r;
				ansl=l;
			}
		}
		if(ansl==-1){
			cout<<-1<<endl;
		}else{
			cout<<ansl+1<<" "<<ansr+1<<endl;
		}
		return 0;
	};
	bool one_case=0;
	bool ynans=0;
	bool eof=0;
	string yes="YES";
	string no="NO";
	INT t=(one_case?1:read(int));
	for(INT i=0;eof || i<t;i++){
		INT re=solve(i);
		if(!ynans){
			if(re==-1)return 0;
		}else{
			if(re==1){
				cout<<yes<<endl;
			}else if(re==0){
				cout<<no<<endl;
			}else{
				return 0;
			}
		}
	}
	return 0;
}
```
