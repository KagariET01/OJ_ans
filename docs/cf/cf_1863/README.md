<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 1863` Pinely Round 2 (Div. 1 + Div. 2)

[`back`](../) [`CF 1863`](https://codeforces.com/contest/1863)

## `CF 1863 PA` Channel

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


int main(int argc,char** argv){
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

	function<int(INT)> solve=[](INT casenum){
		INT n,a,b;
		string q;
		cin>>n>>a>>b>>q;
		INT alladd=a;
		INT nw=a;
		INT ans=0;
		if(nw>=n){
			ans=2;
			cout<<"YES"<<endl;
			return 0;
		}
		if(alladd>=n){
			ans=1;
		}
		for(char c:q){
			if(c=='+'){
				alladd++;
				nw++;
				if(nw>=n){
					ans=2;
					break;
				}
				if(alladd>=n){
					ans=1;
				}
			}else{
				nw--;
			}
			DBG cout<<"alladd="<<alladd<<" nw="<<nw<<" ans="<<ans<<endl;
		}
		switch(ans){
			case 0:
				cout<<"NO"<<endl;
			break;
			case 1:
				cout<<"MAYBE"<<endl;
			break;
			case 2:
				cout<<"YES"<<endl;
			break;
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
		solve(i);
	}
	return 0;
}
```

## `CF 1863 PC` MEX Repetition

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

int main(int argc,char** argv){
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	while(t--){
		INT n,k;
		cin>>n>>k;
		INT lst[n+1]={};
		bool isit[n+1]={};
		for(INT i=0;i<n;i++){
			cin>>lst[i];
			isit[lst[i]]=1;
		}
		for(INT i=0;i<=n;i++){
			if(!isit[i]){
				lst[n]=i;
				isit[i]=1;
				break;
			}
		}
		INT mv=k%(n+1);
		for(INT i=0;i<n;i++){
			if(i)cout<<" ";
			cout<<lst[(i-mv+(n+1))%(n+1)];
		}
		cout<<endl;
	}
	return 0;
}
```

### `Tag`

```txt
math 數學,觀察
```
