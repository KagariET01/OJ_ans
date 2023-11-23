<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

[`back`](../)

# `NHSPC-NTPC 2023` 北二區學科能力競賽

## [`NHSPC-NTPC 2023 PA`] 2024 跨年煙火秀
[`NHSPC-NTPC 2023 PA`]: ./NHSPC-NTPC_2023/PA.pdf
### `C++`
```c++
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl '\n'
bool debug=0;
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT M,D,h,m,s;
	cin>>M>>D>>h>>m>>s;
	INT ansD=0;
	INT ansh=0;
	INT ansm=0;
	INT anss=0;
	if(s){
		anss=60-s;
		m++;
	}
	if(m>=60){
		h++;
		m-=60;
	}
	if(m){
		ansm=60-m;
		h++;
	}
	if(h){
		ansh=24-h;
		D++;
	}
	if(M==11){
		ansD=31+30-D+1;
	}else{
		ansD=31-D+1;
	}
	cout<<ansD<<" ";
	cout<<ansh<<" ";
	cout<<ansm<<" ";
	cout<<anss<<"\n";
	return 0;
}
```

## [`NHSPC-NTPC 2023 PB`] 2048
[`NHSPC-NTPC 2023 PB`]: ./NHSPC-NTPC_2023/PB.pdf
### `C++`
```c++
//AC
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define read(n) reader<n>()
#define DBG i(debug)
#define endl '\n'
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
#define PII pair<INT,INT>
bool debug=0;


template<typename T>T reader(){
	T re;cin>>re;return re;
}

vector<INT> oper(vector<INT> a){
	vector<INT> re;
	INT l=0;
	INT r=1;
	while(l<4 && r<4){
		if(l>=r)r=l+1;
		if(a[l]==0){
			l++;
			r++;
			continue;
		}else if(a[r]==0){
			r++;
			continue;
		}else if(a[r]!=a[l]){
			re.push_back(a[l]);
			l=r;
			r++;
			continue;
		}else if(a[r]==a[l]){
			re.push_back(a[l]<<1);
			l=r+1;
			r=l+1;
		}
	}
	re.push_back(a[l]);
	return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT mp[4][4];
	for(INT i=0;i<4;i++){
		for(INT j=0;j<4;j++){
			cin>>mp[i][j];
		}
	}
	INT op=read(INT);
	INT ans[4][4]={};
	switch(op){
		case 1:
			for(INT j=0;j<4;j++){
				vector<INT> nw;
				for(INT i=0;i<4;i++){
					nw.push_back(mp[i][j]);
				}
				nw=oper(nw);
				INT i=0;
				for(INT p:nw){
					ans[i][j]=p;
					i++;
				}
			}
		break;

		case 4:
			for(INT i=0;i<4;i++){
				vector<INT> nw;
				for(INT j=3;j>=0;j--){
					nw.push_back(mp[i][j]);
				}
				nw=oper(nw);
				INT j=3;
				for(INT p:nw){
					ans[i][j]=p;
					j--;
				}
			}
		break;

		case 2:
			for(INT j=0;j<4;j++){
				vector<INT> nw;
				for(INT i=3;i>=0;i--){
					nw.push_back(mp[i][j]);
				}
				nw=oper(nw);
				INT i=3;
				for(INT p:nw){
					ans[i][j]=p;
					i--;
				}
			}
		break;

		case 3:
			for(INT i=0;i<4;i++){
				vector<INT> nw;
				for(INT j=0;j<4;j++){
					nw.push_back(mp[i][j]);
				}
				nw=oper(nw);
				INT j=0;
				for(INT p:nw){
					ans[i][j]=p;
					j++;
				}
			}
		break;
	}

	for(INT i=0;i<4;i++){
		for(INT j=0;j<4;j++){
			if(j)cout<<" ";
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
}
```

## [`NHSPC-NTPC 2023 PD`] 場地租借
[`NHSPC-NTPC 2023 PD`]: ./NHSPC-NTPC_2023/PD.pdf
### `C++`
```c++
//AC
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define read(n) reader<n>()
#define DBG i(debug)
#define endl '\n'
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
#define PII pair<INT,INT>
bool debug=0;
template<typename T>T reader(){
	T re;cin>>re;return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT n=read(INT);
	PII lst[n];
	for(INT i=0;i<n;i++){
		cin>>lst[i].first;
	}
	for(INT j=0;j<n;j++){
		cin>>lst[j].second;
	}
	INT ans=0;
	sort(lst,lst+n,[](PII a,PII b){return a.second<b.second;});
	INT r=-1;
	for(PII i:lst){
		if(r<i.first){
			ans++;
			r=i.second;
		}
	}
	cout<<ans<<endl;
	return 0;
}
```

## [`NHSPC-NTPC 2023 PE`] 入境審查
[`NHSPC-NTPC 2023 PE`]: ./NHSPC-NTPC_2023/PE.pdf
### `C++`
```c++
//AC
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define read(n) reader<n>()
#define DBG if(debug)
#define endl '\n'
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
#define PII pair<INT,INT>
bool debug=0;
template<typename T>T reader(){
	T re;cin>>re;return re;
}
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT n,m,k;
	cin>>n>>m>>k;
	queue<INT> t;
	for(INT i=0;i<n;i++)t.push(read(INT));
	priority_queue<PII,vector<PII>,greater<PII>> pq;//{time,id}
	queue<INT> cque[m];

	for(INT i=0;i<k && (!t.empty());i++){//排隊直到排滿
		for(INT j=0;j<m && (!t.empty());j++){
			cque[j].push(t.front());
			t.pop();
		}
	}
	INT leavetime[m]={};
	for(INT i=0;i<m;i++){//將每個人的前面加入pq
		if(cque[i].empty()){
			leavetime[i]=0;
		}else
			pq.push({cque[i].front(),i});
	}
	INT allt=0;
	while(!pq.empty()){
		PII nw=pq.top();
		pq.pop();
		DBG cout<<nw.first<<" "<<nw.second<<endl;
		maxs(allt,nw.first);
		cque[nw.second].pop();
		if(t.empty()){//沒人ㄌ
			if(cque[nw.second].empty()){
				leavetime[nw.second]=nw.first;
				continue;
			}
		}else{
			cque[nw.second].push(t.front());
			t.pop();
		}
		pq.push(
			{nw.first+cque[nw.second].front(),
			nw.second
		});
	}
	cout<<allt;
	for(INT i=0;i<m;i++){
		if(leavetime[i]==allt){
			cout<<" "<<i+1;
		}
	}
	cout<<endl;
	return 0;
}
```

## [`NHSPC-NTPC 2023 PH`] 癲癇訊號偵測
[`NHSPC-NTPC 2023 PH`]: ./NHSPC-NTPC_2023/PH.pdf
### `C++`
```c++
//AC
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define read(n) reader<n>()
#define DBG if(debug)
#define endl '\n'
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
#define PII pair<INT,INT>
#define PIPII pair<INT,pair<INT,INT>>
bool debug=0;
template<typename T>T reader(){
	T re;cin>>re;return re;
}
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT n=read(INT);
	INT a[n];
	for(INT i=0;i<n;i++){
		cin>>a[i];
	}
	PII ans[4]={};
	for(INT i=1;i<n;i++){
		ans[0].first=abs(a[i]-a[i-1]);
		ans[0].second=i;
		sort(
			ans,
			ans+4,
			[](PII a,PII b){
				if(a.first==b.first)return ((a.second)>(b.second));
				return ((a.first)<(b.first));
			}
		);
	}
	cout<<ans[3].first<<" "<<ans[3].second<<" "<<ans[3].second+1<<endl;
	cout<<ans[2].first<<" "<<ans[2].second<<" "<<ans[2].second+1<<endl;
	cout<<ans[1].first<<" "<<ans[1].second<<" "<<ans[1].second+1<<endl;
	return 0;
}
```

## [`NHSPC-NTPC 2023 PI`] 發燒影片
[`NHSPC-NTPC 2023 PI`]: ./NHSPC-NTPC_2023/PI.pdf
```c++
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define read(n) reader<n>()
#define DBG if(debug)
#define endl '\n'
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
#define PII pair<INT,INT>
bool debug=0;
template<typename T>T reader(){
	T re;cin>>re;return re;
}
struct str{
	INT vid=0;
	INT uid=0;
	INT t=0;
	INT k=0;
};
bool operator>(str a,str b){
	return a.k>b.k;
}
template<typename T>void swap_sort(T l,T r){
	while(l<r){
		T nxt=l+1;
		if(*l>*nxt){
			swap(*l,*nxt);
			l++;
		}else return;
	}
}
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT m,t,n;
	cin>>m>>t>>n;
	str lst[n+1]={};
	for(INT i=0;i<m;i++){
		cin>>lst[0].vid;
		cin>>lst[0].uid;
		cin>>lst[0].t;
		cin>>lst[0].k;;
		if(lst[0].t<t)continue;
		else swap_sort(lst,lst+n);
	}
	for(INT i=n;i>0;i--){
		cout<<lst[i].vid<<" ";
		cout<<lst[i].uid<<" ";
		cout<<lst[i].t<<" ";
		cout<<lst[i].k<<endl;
	}
	return 0;
}
```


## [`NHSPC-NTPC 2023 PL`] 處方箋
[`NHSPC-NTPC 2023 PL`]: ./NHSPC-NTPC_2023/PL.pdf
### `C++`
```c++
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define read(n) reader<n>()
#define DBG if(debug)
#define endl '\n'
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
#define PII pair<INT,INT>
bool debug=0;


template<typename T>T reader(){
	T re;cin>>re;return re;
}

const INT mxn=1005;
INT n,m;
INT flag[mxn];//0=IDK, 1=eat, -1=danger
vector<INT> tree[mxn];

void dfs(INT nw,INT lst=-1){
	for(INT i:tree[nw]){
		if(flag[i]==1){
			flag[nw]=-1;
			continue;
		}
	}

	if(flag[nw]==0)flag[nw]=1;

	for(INT i:tree[nw]){
		if(flag[i]==0){
			flag[i]=0-flag[nw];
			dfs(i,nw);
		}
	}
}
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cin>>n>>m;
	for(INT i=0;i<m;i++){
		INT a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	INT ans=0;
	for(INT i=1;i<=n;i++){
		if(!flag[i])dfs(i);
		ans+=(flag[i]==1);
	}
	cout<<ans<<endl;
	return 0;
}
```

# `PCSH Mid-2023-01` PCSH Midterm Exam Contest #007

## [`PCSH Mid-2023-01 PD`] 好想跟鄭國手一樣強(User333 Orz)

[`PCSH Mid-2023-01 PD`]: https://codeforces.com/group/VEc3guEDmO/contest/477514/problem/D

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

const INT mxn=500000;
function<
	void(
		vector<INT>::iterator,
		vector<INT>::iterator,
		INT*
	)
 mrgesort;
int main(int argc,char** argv){
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

	function<int(INT)> solve=[](INT casenum){
		INT n;
		if(!(cin>>n))return -1;
		vector<INT> lst;
		lst.reserve(n);
		INT ans=0;
		for(INT i=0;i<n;i++){
			lst.push_back(read(INT));
		}
		mrgesort=[](
			vector<INT>::iterator l,
			vector<INT>::iterator r,
			INT *ans
		){
			DBG{
				for(INT i=0;i<(r-l);i++){
					cout<<*(l+i)<<" ";
				}
				cout<<endl;
			}
			if(l==r)return;
			if(r-l<=1)return;
			vector<INT> vec;
			vec.reserve(r-l);
			INT ltt=0;
			INT lpt=0;
			vector<INT>::iterator mnt=(r-l)/2+l;
			mrgesort(l,mnt,ans);
			mrgesort(mnt,r,ans);
			for(vector<INT>::iterator it=l;it<mnt;it++){
				ltt+=*it;
				lpt+=(*it)*(*it);
			}
			vector<INT>::iterator lit=l;
			for(vector<INT>::iterator rit=mnt;rit<r;rit++){
				while(lit<mnt && *lit<=*rit){
					ltt-=*lit;
					lpt-=(*lit)*(*lit);
					vec.push_back(*lit);
					lit++;
				}
				*ans+=(mnt-lit)*(*rit)*(*rit)+2*(*rit)*ltt+lpt;
				vec.push_back(*rit);
			}
			while(lit<mnt){
				vec.push_back(*lit);
				lit++;
			}
			vector<INT>::iterator it=l;
			for(INT i:vec){
				*l=i;
				l++;
			}
			DBG{
				cout<<"to==>";
				for(INT i:vec){
					cout<<" "<<i;
				}
				cout<<" Ans="<<*ans<<endl;
			}
		};
		mrgesort(lst.begin(),lst.end(),&ans);
		cout<<ans<<endl;
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

# `Meta 2023-1` Meta Hacker Cup 2023 Round 1

## `Meta 2023-1 PB1` Sum 41 (Chapter 1)

### [`OUTPUT`](./Meta_2023-1_PB1_output)

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

deque<INT> ans;

bool getans(INT p,INT mx=41){
	DBG cout<<"p="<<p<<" mx="<<mx<<endl;
	if(p==1){
		for(INT i=0;i<mx;i++){
			ans.push_back(1);
		}
		return 1;
	}
	for(INT i=mx;i>=2;i--){
		if(p%i)continue;
		else{
			ans.push_back(i);
			if(getans(p/i,mx-i))return 1;
			ans.pop_back();
		}
	}
	return 0;
}

int main(int argc,char** argv){
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	auto solve=[](INT casenum){
		cout<<"Case #"<<casenum+1<<": ";
		ans.clear();
		INT p=read(INT);
		DBG cerr<<"running"<<endl;
		if(getans(p)){
			cout<<ans.size();
			for(INT i:ans){
				cout<<" "<<i;
			}
			cout<<endl;
		}else{
			cout<<"-1"<<endl;
		}
		return 0;
	};
	bool one_case=0;
	bool ynans=0;
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

### `Tag`

```txt
家庭暴力防治法
```
# `Luogu` 洛谷
## [`Luogu P3865`] 【模板】ST 表
[`Luogu P3865`]: https://www.luogu.com.cn/problem/P3865
### `C++`
```c++
// [st表]
// 區間極值查詢
// 不支援修改
// 預處理：$O(n*log_2(n))$
// 查詢：$O(1)$
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)

const INT mxn=1e5;
const INT lgn=32;
INT orig[mxn+5];
INT n;
INT logn[mxn+5];
INT f[mxn+5][lgn];
void glog(){
	logn[0]=0;
	logn[1]=0;
	logn[2]=1;
	for(INT i=3;i<=mxn;i++){
		logn[i]=logn[i/2]+1;//log_2(i)=log_2((i/2) * 2)=log_2(i/2)+log_2(2)=log_2(i/2)+1
	}
}
void build(){
	for(INT i=0;i<n;i++){
		f[i][0]=orig[i];
	}
	for(INT j=1;j<lgn;j++){
		for(INT i=0; (i+(1<<(j-1))) <n;i++){
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
}
INT query(INT l,INT r){
	INT lp=(r-l)+1;
	INT lglp=logn[lp];
	INT ans=f[l][lglp];
	maxs(ans,f[r-(1<<lglp)+1][lglp]);
	return ans;
}



//use
#define endl '\n'
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT m;
	cin>>n>>m;
	for(INT i=0;i<n;i++){
		cin>>orig[i];
	}
	glog();
	build();
	while(m--){
		INT l,r;
		cin>>l>>r;
		l--,r--;
		cout<<query(l,r)<<endl;
	}
	return 0;
}
```
### `Tag`
```txt
ST表
區間極值
```


# Unknow

## `AOJ 129` 電皇的小寫英文字母
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
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	function<int(INT)> solve=[](INT casenum){
		string str;
		if(!(cin>>str))return -1;
		INT n=str.size();
		INT cnt[30]={};
		INT charcnt=0;
		INT ansl=-1,ansr=-1;
		INT l=0,r=0;
		for(;r<n;r++){
			DBG cout<<"nw="<<str[r]<<endl;
			cnt[(str[r]-'a')]++;
			if(cnt[(str[r]-'a')]==1)charcnt++;
			while(cnt[(str[l]-'a')]>1){
				cnt[(str[l]-'a')]--;
				l++;
			}
			if(charcnt==26){
				if(ansr==-1 || ansr-ansl>r-l){
					ansr=r;
					ansl=l;
				}
			}
		}
		if(charcnt==26){
			for(INT i=ansl;i<=ansr;i++){
				DBG cerr<<i<<" ";
				cout<<str[i];
			}
		}else{
			cout<<"QQ";
		}
		cout<<endl;
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




