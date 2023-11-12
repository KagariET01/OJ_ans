<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# [`CF 1783`] Educational Codeforces Round 141 (Rated for Div. 2)
[`CF 1783`]: https://codeforces.com/contest/1783
[`back`](../)

## [`CF 1783 PB`] Matrix of Differences
[`OJ CID PID`]: https://codeforces.com/contest/1783/problem/B
### `C++`
```c++
#include<bits/stdc++.h>

using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){tpe re;cin>>re;return re;}

int main(int argc,char** argv){
	if(noTLE && !debug){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}

	function<int(INT)> solve=[](INT casenum){
		INT n=read(INT);
		INT l=1;
		INT r=(n*n);
		INT x=0,y=0;
		INT ans[n][n];
		while(1){
			if((l+r)&1){
				ans[x][y]=r;
				r--;
			}else{
				ans[x][y]=l;
				l++;
			}
			if(!(y&1)){
				if(x==n-1)y++;
				else x++;
			}else{
				if(x==0)y++;
				else x--;
			}
			if(y==n)break;
		}
		for(INT i=0;i<n;i++){
			for(INT j=0;j<n;j++){
				cout<<ans[i][j]<<(j<n-1?(' '):'\n');
			}
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
### `Tag`
```txt
math 數學
模擬constructive algorithms
```
