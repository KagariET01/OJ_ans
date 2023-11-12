<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 1889` Codeforces Round 906 (Div. 1)<br>`CF 1890` Codeforces Round 906 (Div. 2)

[`back`](../)

## [`CF 1890 PA`] Doremy's Paint 3
[`CF 1890 PA`]: https://codeforces.com/contest/1890/problem/A
### `C++`
```c++
#include<bits/stdc++.h>

using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define mins(a,b) a=min(a,b)
#define maxs(a,b) a=max(a,b)
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

	//function<int(INT)> solve=[](INT casenum){
	auto solve=[](INT casenum){
		INT n=read(INT);
		map<INT,INT> mp;
		for(INT i=0;i<n;i++){
			mp[read(INT)]++;
		}
		bool cnt=0;
		if(mp.size()>2)return 0;
		if(mp.size()==1)return 1;
		INT a[2]={};
		INT p=0;
		for(PII i:mp){
			a[p]=i.second;
			p++;
		}
		if(abs(a[0]-a[1])<=1)return 1;
		return 0;
	};
	bool one_case=0;
	bool ynans=1;
	bool eof=0;
	string yes="Yes";
	string no="No";
	INT t=(one_case?1:read(int));
	for(INT i=0;eof || i<t;i++){
		INT re=solve(i);
		if(eof && re==-1){
			return 0;
		}else if(ynans){
			if(re==1){
				cout<<yes<<endl;
			}else if(re==0){
				cout<<no<<endl;
			}else{
				return re;
			}
		}
	}
	return 0;
}
```

## [`CF 1890 PB`] Qingshan Loves Strings
[`CF 1890 PB`]: https://codeforces.com/contest/1890/problem/B
### `C++`
```c++
#include<bits/stdc++.h>

using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define mins(a,b) a=min(a,b)
#define maxs(a,b) a=max(a,b)
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

	//function<int(INT)> solve=[](INT casenum){
	auto solve=[](INT casenum){
		INT n,m;
		cin>>n>>m;
		string s,t;
		cin>>s>>t;
		bool canfix=1;
		if(t[0]!=t[m-1])canfix=0;
		for(INT i=1;i<m;i++){
			if(t[i]==t[i-1]){canfix=0;break;}
		}
		for(INT i=1;i<n;i++){
			if(s[i]==s[i-1]){
				if(!canfix)return 0;
				if(s[i]==t[0])return 0;
			}
		}
		return 1;
	};
	bool one_case=0;
	bool ynans=1;
	bool eof=0;
	string yes="Yes";
	string no="No";
	INT t=(one_case?1:read(int));
	for(INT i=0;eof || i<t;i++){
		INT re=solve(i);
		if(eof && re==-1){
			return 0;
		}else if(ynans){
			if(re==1){
				cout<<yes<<endl;
			}else if(re==0){
				cout<<no<<endl;
			}else{
				return re;
			}
		}
	}
	return 0;
}
```

## [`CF 1889 PA`] Qingshan Loves Strings 2<br>[`CF 1890 PC`] Qingshan Loves Strings 2
[`CF 1889 PA`]: https://codeforces.com/contest/1889/problem/A
[`CF 1890 PC`]: https://codeforces.com/contest/1890/problem/C
### `C++`
```c++
#include<bits/stdc++.h>

using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define mins(a,b) a=min(a,b)
#define maxs(a,b) a=max(a,b)
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

	//function<int(INT)> solve=[](INT casenum){
	auto solve=[](INT casenum){
		INT n;
		cin>>n;
		INT ans=0;
		INT cnt[2]={};
		deque<int> dq;
		string str=read(string);
		if(n&1){
			cout<<"-1"<<endl;
			return 0;
		}
		for(char c:str){
			cnt[c-'0']++;
			dq.push_back(c-'0');
		}
		if(cnt[0]!=cnt[1]){
			cout<<"-1"<<endl;
			return 0;
		}
		vector<INT> vec;
		vec.reserve(300);
		INT l=0,r=n;
		while(!dq.empty()){
			if(dq.front()==dq.back()){
				if(dq.front()==1){
					dq.push_front(1);
					dq.push_front(0);
					vec.push_back(l);
				}else{
					dq.push_back(0);
					dq.push_back(1);
					vec.push_back(r);
				}
				r+=2;
			}
			dq.pop_back();
			dq.pop_front();
			l++,r--;
		}
		if(vec.size()<=300){
			cout<<vec.size()<<endl;
			for(INT i=0;i<vec.size();i++){
				if(i)cout<<" ";
				cout<<vec[i];
			}
			cout<<endl;
		}
		else{
			cout<<"-1"<<endl;
			return 0;
		}
		return 0;
	};
	bool one_case=0;
	bool ynans=0;
	bool eof=0;
	string yes="";
	string no="-1";
	INT t=(one_case?1:read(int));
	for(INT i=0;eof || i<t;i++){
		INT re=solve(i);
		if(eof && re==-1){
			return 0;
		}else if(ynans){
			if(re==1){
				cout<<yes<<endl;
			}else if(re==0){
				cout<<no<<endl;
			}else{
				return re;
			}
		}
	}
	return 0;
}
```

## [`CF 1889 PB`] Doremy's Connecting Plan<br>[`CF 1890 PD`] Doremy's Connecting Plan
[`CF 1889 PB`]: https://codeforces.com/contest/1889/problem/B
[`CF 1890 PD`]: https://codeforces.com/contest/1890/problem/D
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

const INT mxn=1e5;
INT lca[mxn+1][30];
INT n;
vector<INT> tre[mxn];
INT deep[mxn];

int main(int argc,char** argv){
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

	function<int(INT)> solve=[](INT casenum){
		INT n,c;
		cin>>n>>c;
		INT a[n+1]={};
		priority_queue<PII> pq;
		cin>>a[1];
		INT nw=a[1];
		for(INT i=2;i<=n;i++){
			cin>>a[i];
			pq.push({a[i]-i*c,i});
		}
		while(!pq.empty()){
			nw+=pq.top().first;
			if(nw<0){
				return 0;
			}
			nw+=pq.top().second*c;
			pq.pop();
		}
		return 1;
	};
	bool one_case=0;
	bool ynans=1;
	bool eof=0;
	string yes="Yes";
	string no="No";
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





