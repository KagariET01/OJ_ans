<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 1867` Codeforces Round 897 (Div. 2)

[`back`](../) [`CF 1867`](https://codeforces.com/contest/1867)

## `CF 1867 PA` green_gold_dog, array and permutation

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
		INT n;
		cin>>n;
		vector<PII> vec;
		for(INT i=0;i<n;i++){
			INT inin=read(INT);
			vec.push_back({inin,i});
		}
		sort(vec.begin(),vec.end());
		INT ans[n];
		INT cnt=n;
		for(PII i:vec){
			ans[i.second]=cnt;
			cnt--;
		}
		for(INT i=0;i<n;i++){
			if(i)cout<<" ";
			cout<<ans[i];
		}
		cout<<endl;
	}
	return 0;
}
```

### `Tag`

```txt
sort
```

## `CF 1867 PB` XOR Palindromes

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
		INT n;
		cin>>n;
		string str;
		cin>>str;
		bool s[n];
		for(INT i=0;i<n;i++)s[i]=str[i]-'0';
		INT duo=0,sin=0;
		for(INT i=0;i<n/2;i++){
			if(s[i]==s[n-i-1])duo++;
			else sin++;
		}
		for(INT i=0;i<sin;i++){
			cout<<"0";
		}

		if(n%2){
			for(INT i=0;i<(duo+1)*2;i++){
				cout<<"1";
			}
		}else{
			for(INT i=0;i<duo+1;i++){
				if(i)cout<<"0";
				cout<<"1";
			}
		}


		for(INT i=0;i<sin;i++){
			cout<<"0";
		}
		cout<<endl;
	}
	return 0;
}
```

### `Tag`

```txt
bit運算
math 數學
觀察
```
