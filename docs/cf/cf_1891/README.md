<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 1891` Codeforces Round 907 (Div. 2)

[`back`](../)

## [`CF 1891 PA`] Sorting with Twos
[`CF 1891 PA`]: https://codeforces.com/contest/1891/problem/A
### `C++`
```c++
#include<bits/stdc++.h>

using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){tpe re;cin>>re;return re;}

int main(int argc,char** argv){
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

	function<int(INT)> solve=[](INT casenum){
		INT n=read(INT);
		vector<INT> a;
		a.reserve(n);
		for(INT i=0;i<n;i++){
			a.push_back(read(INT));
		}
		INT i=1;
		INT lst=-1;
		for(INT j=1;i<n;j<<=1){
			for(INT k=0;i<n && k<j;i++,k++){
				if(lst>a[i])return 0;
				lst=a[i];
			}
			lst=-1;
		}
		return 1;
	};
	bool one_case=0;
	bool ynans=1;
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

## [`CF 1891 PB`] Deja Vu
[`CF 1891 PB`]: https://codeforces.com/contest/1891/problem/B
### `C++`
```c++
#include<bits/stdc++.h>

using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){tpe re;cin>>re;return re;}

int main(int argc,char** argv){
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

	function<int(INT)> solve=[](INT casenum){
		INT n,q;
		cin>>n>>q;
		INT a[n];
		vector<INT> x;
		x.reserve(q);
		for(INT i=0;i<n;i++){cin>>a[i];}
		for(INT i=0;i<q;i++){INT inin=read(INT);if(x.empty() || inin<x.back())x.push_back(inin);}
		for(INT i=0;i<n;i++){
			for(INT j:x){
				DBG cout<<"a[i]="<<a[i]<<",j="<<j<<endl;
				if(!(a[i]%(1<<j))){
					a[i]+=1<<(j-1);
				}
			}
		}
		for(INT i=0;i<n;i++){
			if(i)cout<<" ";
			cout<<a[i];
		}
		cout<<endl;
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

## [`CF 1891 PC`] Smilo and Monsters
[`CF 1891 PC`]: https://codeforces.com/contest/1891/problem/C
### `C++`
```c++
#include<bits/stdc++.h>

using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

int lv[1000001];

int main(int argc,char** argv){
	for(int i=0;i<argc;i++){
		string nwstr=argv[i];
		if(nwstr=="-Dev"){
			debug=1;
			noTLE=0;
		}else if(nwstr=="-TLE"){
			noTLE=0;
		}
	}
	DBG{
		cout<<"> Temp by KagariET01"<<endl;
		cout<<"> My Webpage: https://kagariet01.github.io/about"<<endl;
		cout<<"> ===DBG mod on==="<<endl;
		cout<<"> Here's your CFG"<<endl;
		for(int i=0;i<argc;i++){
			string nwstr=argv[i];
			cout<<"> ["<<nwstr<<']'<<endl;
		}
		cout<<"> ===Code start==="<<endl;
	}
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	function<int(INT)> solve=[](INT casenum){
		INT n;
		if(!(cin>>n))return -1;
		vector<INT> a;
		a.reserve(n);
		for(int i=0;i<n;i++){
			a.push_back(read(INT));
		}
		sort(a.begin(),a.end());
		INT l=0,r=n-1;
		INT nw=0;
		INT ans=0;
		bool add[n]={};
		for(;l<r;){
			DBG cout<<"> a[l]="<<a[l]<<" a[r]="<<a[r]<<" ans="<<ans<<endl;
			if(a[l]==0){
				l++;
				continue;
			}
			if(nw+a[l]>=a[r]){
				INT ned=a[r]-nw;
				a[l]-=ned;
				add[r]=1;
				ans+=ned;
				nw=0;
				a[r]=0;
				r--;
				continue;
			}
			ans+=a[l];
			nw+=a[l];
			a[l]=0;
			l++;
		}
		DBG cerr<<"> l="<<l<<" r="<<r<<endl;
		if(a[r]>0){
			if(nw){
				a[r]-=nw;
				add[r]=1;
			}
			for(bool i:add){
				DBG cout<<"> "<<i<<" ";
			}
			DBG cout<<"> a[l]="<<a[l]<<" a[r]="<<a[r]<<" ans="<<ans<<endl;
			if(a[r]<=1 || (a[r]<=3 && !add[r])){
				ans+=a[r];
			}else{
				ans+=a[r]/2+(a[r]&1);
				add[r]=1;
			}
		}
		for(bool i:add){
			DBG cout<<"> "<<i<<" ";
			if(i)ans++;
		}
		DBG cout<<endl;
		cout<<ans<<endl;
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
				cout<<"> "<<yes<<endl;
			}else if(re==0){
				cout<<"> "<<no<<endl;
			}else{
				return 0;
			}
		}
	}
	return 0;
}
/**/
```
