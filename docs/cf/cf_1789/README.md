<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 1789` Codeforces Round 853 (Div. 2)

[`back`](../)

## `CF 1789 PA` Serval and Mocha's Array

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
	auto solve=[](INT casenum){
		INT n;
		cin>>n;
		INT a[n];
		for(INT i=0;i<n;i++){cin>>a[i];}
		INT ans=0;
		for(INT i=0;i<n;i++){
			for(INT j=0;j<n;j++){
				if(i==j)continue;
				if(__gcd(a[i],a[j])<=2){
					return 1;
				}
			}
		}
		return 0;
	};
	bool one_case=0;
	bool ynans=1;
	bool eof=0;
	string yes="yes";
	string no="no";
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

## `CF 1789 PB` Serval and Inversion Magic

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
	auto solve=[](INT casenum){
		INT n;
		cin>>n;
		string str;
		cin>>str;
		bool diff[n/2];
		for(INT i=0;i<n/2;i++){
			diff[i]=!(str[i]==str[n-i-1]);
		}
		bool fir1=0;
		for(INT i=0;i<n/2;i++){
			DBG cerr<<diff[i];
			if(fir1){
				if(diff[i-1]==0 && diff[i]==1){
					return 0;
				}
			}else fir1|=diff[i];
		}
		return 1;
	};
	bool one_case=0;
	bool ynans=1;
	bool eof=0;
	string yes="yes";
	string no="no";
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

## `CF 1789 PC` Serval and Toxel's Arrays

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
	auto solve=[](INT casenum){
		INT n,m;
		cin>>n>>m;
		INT lst[n];//紀錄現在狀態
		INT las[n];//紀錄上次值改變的時候
		INT nwcnt[n+m+1]={};
		INT allcnt[n+m+1]={};
		for(INT i=0;i<n;i++){
			cin>>lst[i];
			las[i]=0;
			nwcnt[lst[i]]++;
		}
		for(INT i=1;i<=m;i++){
			INT a,b;
			cin>>a>>b;
			a--;
			allcnt[lst[a]]+=i-las[a];
			lst[a]=b;
			las[a]=i;
		}
		for(INT i=0;i<n;i++){
			allcnt[lst[i]]+=(m+1)-las[i];
		}
		INT ans=((m+1)*m)*n;
		for(INT j:allcnt){
			ans-=j*(j-1)/2;
			DBG cout<<"  -"<<j*(j-1)/2<<endl;
		}
		cout<<ans<<endl;
		return 0;
	};
	bool one_case=0;
	bool ynans=0;
	bool eof=0;
	debug=0;
	string yes="yes";
	string no="no";
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
