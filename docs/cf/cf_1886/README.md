<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 1886` Educational Codeforces Round 156 (Rated for Div. 2)

[`back`](../)

## `CF 1886 PA` Sum of Three

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
		INT n=read(INT);
		if(n>=7 && n%3){
			cout<<"YES"<<endl;
			cout<<n-3<<" 2 1"<<endl;
			return 0;
		}else if(n>=12 && !(n%3)){
			cout<<"YES"<<endl;
			cout<<n-5<<" 1 4"<<endl;
			return 0;
		}else{
			cout<<"NO"<<endl;
			return 0;
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
基本輸出輸入
greedy
```

## `CF 1886 PB` Fear of the Dark

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
		INT px,py;
		INT ax,ay;
		INT bx,by;
		cin>>px>>py;
		cin>>ax>>ay;
		cin>>bx>>by;

		long double ato0=sqrt(ax*ax+ay*ay);
		long double atop=sqrt(
			(px-ax)*(px-ax)+
			(py-ay)*(py-ay)
		);
		long double bto0=sqrt(bx*bx+by*by);
		long double btop=sqrt(
			(px-bx)*(px-bx)+
			(py-by)*(py-by)
		);
		long double atob=sqrt(
			(ax-bx)*(ax-bx)+
			(ay-by)*(ay-by)
		)/2;
		long double ans=1e5+7;
		ans=min(ans,max(ato0,atop));//only use a
		ans=min(ans,max(bto0,btop));//only use b
		ans=min(ans,max(max(ato0,atob),btop));//0->a->b->p
		ans=min(ans,max(max(atop,atob),bto0));//0->b->a->p
		cout<<fixed<<setprecision(10)<<ans<<endl;
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

## `CF 1886 PC` Decreasing String

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
		string str=read(string);
		INT q=read(INT);
		INT n=str.size();
		INT lst[n]={};
		INT nwnm=1;
		stack<pair<char,INT>> st;
		for(INT i=0;i<n;i++){
			while(!st.empty()){
				pair<char,INT> nw=st.top();
				if(nw.first>str[i]){
					lst[nw.second]=nwnm;
					nwnm++;
					st.pop();
				}else break;
			}
			st.push({str[i],i});
			continue;
		}
		while(!st.empty()){
			pair<char,INT> nw=st.top();
			lst[nw.second]=nwnm;
			nwnm++;
			st.pop();
		}
		INT nwmm=n;
		INT qid=0;
		while(nwmm<q){
			q-=nwmm;
			qid++;
			nwmm--;
		}
		DBG cerr<<"q="<<q<<endl;
		INT i=0;
		for(INT i=0;i<n;i++){
			q-=(lst[i]>qid)?1:0;
			if(!q){
				cout<<str[i];
				DBG cerr<<endl;
				return 0;
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
	cout<<endl;
	return 0;
}
```
