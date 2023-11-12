<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# [`CF 1868`] Codeforces Round 896 (Div. 1)
# [`CF 1869`] Codeforces Round 896 (Div. 2) 

[`back`](../)
[`CF 1868`]: https://codeforces.com/contest/1868
[`CF 1869`]: https://codeforces.com/contest/1869

## `CF 1869 PA` Make It Zero

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
		INT n=read(INT);
		for(INT i=0;i<n;i++){
			INT inin=read(INT);
		}
		if(n%2){
			cout<<"4"<<endl;
			cout<<"1 "<<n<<endl;
			cout<<"1 "<<n-1<<endl;
			cout<<n-1<<" "<<n<<endl;
			cout<<n-1<<" "<<n<<endl;
		}else{
			cout<<"2"<<endl;
			cout<<"1 "<<n<<endl;
			cout<<"1 "<<n<<endl;
		}
	}
	return 0;
}
```

### `Tag`

```txt
bit運算
math 數學
greedy
想法
```

## `CF 1869 PB` 2D Traveling

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
		INT n,k,a,b;
		cin>>n>>k>>a>>b;
		a--;b--;
		PII lst[n];
		for(INT i=0;i<n;i++){
			cin>>lst[i].first>>lst[i].second;
		}
		INT alen=0;
		alen=abs(lst[a].first-lst[b].first)+abs(lst[a].second-lst[b].second);
		INT blena=2e10+7;
		INT blenb=2e10+7;
		for(INT i=0;i<k;i++){
			blena=min(blena,(abs(lst[a].first-lst[i].first)+abs(lst[a].second-lst[i].second)));
			blenb=min(blenb,(abs(lst[b].first-lst[i].first)+abs(lst[b].second-lst[i].second)));
		}
		cout<<min(alen,(blena+blenb))<<endl;
	}
	return 0;
}
```

### `Tag`

```txt
math 數學
greedy
想法
```

## `CF 1869 PC` `CF 1868 PA` Fill in the Matrix

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
		INT n,m;
		cin>>n>>m;
		if(m==1){
			cout<<0<<endl;
			for(INT i=0;i<n;i++){
				cout<<0<<endl;
			}
		}else{
			cout<<min(n+1,m)<<endl;
			INT mp[n][m];
			for(INT i=0;i<n;i++){
				INT mv=i%(m-1);
				for(INT j=0;j<m;j++){
					if(j)cout<<" ";
					mp[i][j]=(m?(j+mv)%m:0);
					cout<<mp[i][j];
				}
				cout<<endl;
			}
		}

	}
	return 0;
}
```

### `Tag`

```txt
math 數學
想法
```

## `CF 1869 PD1` `CF 1868 PB1` Candy Party (Easy Version)

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
	auto solve=[](INT icase){
		INT n=read(INT);
		INT a[n];
		INT tot=0;
		for(INT i=0;i<n;i++){cin>>a[i];tot+=a[i];}
		if(tot%n)return 0;
		INT cen=tot/n;
		vector<INT> vec;
		vec.resize(64);
		auto lowbit=[](INT n){
			return n&(-n);
		};
		for(INT i=0;i<n;i++){
			if(a[i]==cen)continue;
			INT mx=abs(a[i]-cen);//距離平均的距離
			INT cnv=lowbit(mx);//要其他人給i的
			INT tot=mx+cnv;//i先給出多少給別人
			if(__builtin_popcount(tot)==1){//i先給出去的數量應該要是2^n
				if(a[i]>cen){
					vec[__lg(tot)]++;
					vec[__lg(cnv)]--;
				}else{
					vec[__lg(tot)]--;
					vec[__lg(cnv)]++;
				}
			}else return 0;
		}
		for(INT i:vec){
			if(i)return 0;
		}
		return 1;
	};
	bool one_case=0;
	bool ynans=1;
	string yes="yes";
	string no="no";
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=(one_case?1:read(int));
	for(INT i=0;i<t;i++){
		if(!ynans){
			solve(i);
		}else{
			if(solve(i)){
				cout<<yes<<endl;
			}else{
				cout<<no<<endl;
			}
		}
	}
	return 0;
}
```

### `Tag`

```txt
bit運算
math 數學
想法
greedy
```
