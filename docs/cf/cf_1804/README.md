<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 1804` Nebius Welcome Round (Div. 1 + Div. 2)

[`back`](../)

## `CF 1804 PA` Lame King

### `c++`

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
	auto solve=[](INT casenum){
		INT x,y;
		cin>>x>>y;
		x=abs(x);
		y=abs(y);
		INT sn=min(x,y);
		INT mr=max(x,y)-sn;
		mr=max((INT)0,mr*2-1);
		cout<<sn*2+mr<<endl;
		return 0;
	};
	bool one_case=0;
	bool ynans=0;
	bool eof=0;
	string yes="yes";
	string no="no";
	INT t=(one_case?1:read(int));
	for(INT i=0;eof || i<t;i++){
		if(!ynans){
			if(solve(i)==-1)return 0;
		}else{
			if(solve(i)==1){
				cout<<yes<<endl;
			}else if(solve(i)==0){
				cout<<no<<endl;
			}else{
				return 0;
			}
		}
	}
	return 0;
}
```

## `CF 1804 PB` Vaccination

### `c++`

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
	auto solve=[](INT casenum){
		INT n,k,d,w;
		cin>>n>>k>>d>>w;
		INT lsttme=-1e9;
		INT nw=0;
		INT ans=0;
		for(INT i=0;i<n;i++){
			INT inin=read(INT);
			if(nw && (inin-lsttme)<=d){
				nw--;
			}else{
				lsttme=inin+w;
				nw=k-1;
				ans++;
			}
		}
		cout<<ans<<endl;
		return 0;
	};
	bool one_case=0;
	bool ynans=0;
	bool eof=0;
	string yes="yes";
	string no="no";
	INT t=(one_case?1:read(int));
	for(INT i=0;eof || i<t;i++){
		if(!ynans){
			if(solve(i)==-1)return 0;
		}else{
			if(solve(i)==1){
				cout<<yes<<endl;
			}else if(solve(i)==0){
				cout<<no<<endl;
			}else{
				return 0;
			}
		}
	}
	return 0;
}
```

## `CF 1804 PC` Pull Your Luck

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

struct str{
	INT nw=0;
	INT n=0;
	INT x=0;
	INT p=0;
	INT id=0;
};
bool operator>(str a,str b){
	return a.nw>b.nw;
}
struct vser{
	bool operator()(str a,str b){
		return a>b;
	}
};

int main(int argc,char** argv){
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	auto solve=[](INT casenum){
		INT t;
		cin>>t;
		priority_queue<str,vector<str>,vser> pq;
		bool ans[t]={};
		for(INT i=0;i<t;i++){
			str nw;
			cin>>nw.n>>nw.x>>nw.p;
			nw.id=i;
			nw.nw=nw.n-nw.x;
			pq.push(nw);
		}
		INT f=1;
		INT ftt=1;
		while(!pq.empty()){
			DBG cerr<<"f="<<f<<" ftt="<<ftt<<endl;
			while(!pq.empty()){
				str nw=pq.top();
				pq.pop();
				DBG cerr<<"f="<<f<<" ftt="<<ftt<<" nw="<<nw.nw<<" n="<<nw.n<<" x="<<nw.x<<" p="<<nw.p<<" id="<<nw.id<<endl;
				if(ftt<nw.nw){
					pq.push(nw);
					break;
				}
				if(nw.nw<ftt){
					INT xx=ftt-nw.nw;
					xx=xx/nw.n+(xx%nw.n?1:0);
					nw.nw+=nw.n*xx;
				}
				if(min(2*nw.n,nw.p)<f)continue;
				if(nw.nw==ftt){
					DBG cerr<<nw.id<<" pass"<<endl;
					ans[nw.id]=1;
					continue;
				}
				pq.push(nw);
			}
			f++;
			ftt+=f;
		}
		for(INT i=0;i<t;i++){
			cout<<(ans[i]?"yes":"no")<<endl;
		}
		return 0;
	};
	bool one_case=1;
	bool ynans=0;
	bool eof=0;
	string yes="yes";
	string no="no";
	INT t=(one_case?1:read(int));
	for(INT i=0;eof || i<t;i++){
		if(!ynans){
			if(solve(i)==-1)return 0;
		}else{
			if(solve(i)==1){
				cout<<yes<<endl;
			}else if(solve(i)==0){
				cout<<no<<endl;
			}else{
				return 0;
			}
		}
	}
	return 0;
}
```
