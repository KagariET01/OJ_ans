<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">


[`back`](../)

## [`ZJ J242`] `NHSPC 111N P1A` 111 北二 1a.自然數的平方根
[`ZJ J242`]: https://zerojudge.tw/ShowProblem?problemid=j242
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
		if(!(cin>>n)){
			return -1;
		}
		for(INT i=sqrt(n);i>=2;i--){
			if(n%(i*i)==0){
				if(n/(i*i)==1){
					cout<<i<<endl;
					return 0;
				}
				cout<<i<<" sqrt("<<n/(i*i)<<")"<<endl;
				return 0;
			}
		}
		cout<<"sqrt("<<n<<")"<<endl;
		return 0;
	};
	bool one_case=1;
	bool ynans=0;
	bool eof=1;
	string yes="YES";
	string no="NO";
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

## [`ZJ J244`] `NHSPC 111N P1C` 111北二3a.兌獎問題
[`ZJ J244`]: https://zerojudge.tw/ShowProblem?problemid=j244
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
		INT n,m;
		cin>>n>>m;
		string lucky[3];
		for(INT i=0;i<3;i++){
			cin>>lucky[i];
		}
		INT ans=0;
		INT nw=0;
		for(INT i=0;i<m;i++){
			string st=read(string);
			for(INT j=0;j<3;j++){
				for(INT i=n-1,s=1;i>=0;i--,s++){
					if(st[i]!=lucky[j][i])break;
					if(s==3){
						maxs(nw,300);
					}else if(s==n-4){
						maxs(nw,1000);
					}else if(s==n-2){
						maxs(nw,10000);
					}else if(s==n){
						maxs(nw,500000);
					}
				}
			}
			ans+=nw;
			nw=0;
		}
		cout<<ans<<endl;
		return 1;
	};
	bool one_case=1;
	bool ynans=0;
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


## [`ZJ J245`] `NHSPC 111N P1D` 111北二4a.加密密文
[`ZJ J245`]: https://zerojudge.tw/ShowProblem?problemid=j245
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
		string s;
		
		if(!(cin>>s))return -1;
		string s2;
		if(s.size()&1){
			s2+=s[s.size()/2];
			for(INT i=0;i<s.size()/2;i++){
				s2+=s[i];
			}
			for(INT i=s.size()/2+1;i<s.size();i++){
				s2+=s[i];
			}
			s2+=s[s.size()/2];
		}else{
			s2+=s[s.size()/2-1];
			for(INT i=0;i<s.size()/2-1;i++){
				s2+=s[i];
			}
			for(INT i=s.size()/2+1;i<s.size();i++){
				s2+=s[i];
			}
			s2+=s[s.size()/2];
		}
		//cout<<s2<<endl;
		string t;
		INT l=0,r=(s2.size()-1);
		for(int i:s2){
			//cout<<"nw="<<i<<endl;
			if(i&1){
				t+=s2[l];
				//cout<<"add:"<<l<<endl;
				l++;
			}else{
				t+=s2[r];
				//cout<<"add:"<<r<<endl;
				r--;
			}
		}
		//cout<<t<<endl;
		INT h=0;
		for(INT i=(s2.size()-1),j=0;j<4;i--,j++){
			//cout<<(int(s2[i])+int(t[i]))<<endl;
			int a=s2[j]&1;
			int b=t[j]&1;
			h+=a^b;
		}
		//cout<<"h="<<h<<endl;
		string t2;
		for(char c:t){
			int nw=c-'a';
			nw+=h;
			nw%=('z'-'a'+1);
			char ans=nw+'a';
			cout<<ans;
		}
		cout<<endl;
		return 0;
	};
	bool one_case=1;
	bool ynans=0;
	bool eof=1;
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

## [`ZJ J247`] `NHSPC 111N P1F` 111北二6a.不平衡配對數
[`ZJ J247`]: https://zerojudge.tw/ShowProblem?problemid=j247
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

int main(int argc,char** argv){
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

	auto solve=[](INT casenum){
		INT n,k;
		if(!(cin>>n>>k))return -1;
		vector<INT> a;
		a.reserve(n);
		for(INT i=0;i<n;i++){
			a.push_back(read(INT));
		}
		INT ans=0;
		function<void(
			vector<INT>::iterator,
			vector<INT>::iterator,
			INT*,
			INT
		)> mrgsort=[&](
			vector<INT>::iterator l,
			vector<INT>::iterator r,
			INT *ans,
			INT k
		){
			if(r-l<=1)return;
			DBG cerr<<"leng="<<r-l<<endl;
			vector<INT>::iterator mnt=(r-l)/2+l,nl=l,nr=mnt;
			mrgsort(l,mnt,ans,k);
			mrgsort(mnt,r,ans,k);
			//check
			while(nl!=mnt && nr!=r){
				DBG cerr<<(*nl)<<" vs "<<(*nr)<<" * "<<k<<endl;
				if((*nl)>(*nr)*k){
					*ans+=r-nr;
					DBG cerr<<"ans="<<ans<<endl;
					nl++;
				}else nr++;
			}
			nl=l,nr=mnt;
			vector<INT> re;
			re.reserve(r-l+1);
			while(nl!=mnt && nr!=r){
				if((*nl)<(*nr)){
					re.push_back(*nr);
					nr++;
				}else{
					re.push_back(*nl);
					nl++;
				}
			}
			while(nl!=mnt){
					re.push_back(*nl);
					nl++;
			}
			while(nr!=r){
				re.push_back(*nr);
				nr++;
			}
			for(INT i:re){
				*l=i;
				l++;
			}
		};
		mrgsort(a.begin(),a.end(),&ans,k);
		cout<<ans<<endl;
		return 0;
	};
	bool one_case=1;
	bool ynans=0;
	bool eof=1;
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

## [`ZJ J248`] `NHSPC 111N P1G` 111北二7a.驛站換馬、郵政系統
[`ZJ J248`]: https://zerojudge.tw/ShowProblem?problemid=j248
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

const INT mxn=100000;
INT n,m;
INT a[mxn+1];
INT ans=0;
vector<pair<INT,PII>> tre[mxn+1];//node,(cost,get)

void dfs(INT nw=1,INT lst=-1){
	for(pair<INT,PII> i:tre[nw]){
		if(i.first==lst)continue;
		dfs(i.first,nw);
		INT mv=abs(a[i.first]-m);//move car
		ans-=mv*i.second.first;
		if(mv){
			ans+=i.second.second;
		}else if(i.second.first*2<i.second.second){
			ans+=i.second.second-i.second.first*2;
		}
		a[nw]+=a[i.first]-m;
	}
}

int main(int argc,char** argv){
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

	auto solve=[](INT casenum){
		if(!(cin>>n>>m))return -1;
		for(INT i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		for(INT i=0;i<=n;i++)tre[i].clear();
		for(INT i=1;i<n;i++){
			INT a,b,c,d;
			cin>>a>>b>>c>>d;
			d=min(d,150)*2+max(d-150,0);
			tre[a].push_back({b,{c,d}});
			tre[b].push_back({a,{c,d}});
		}
		dfs();
		cout<<ans<<endl;
		return 0;
	};
	bool one_case=1;
	bool ynans=0;
	bool eof=1;
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
`Tag`
```txt
greedy
graphs
```