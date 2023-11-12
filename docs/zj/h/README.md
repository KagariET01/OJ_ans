# `ZJ h___`

[`back`](../)

## `ZJ h399` 蛋糕店促銷（簡易版）

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

INT superx(INT a,INT n,INT mod=0){
	INT re=1;
	INT xx=a;
	while(n>0){

		if(n&1){
			re*=xx;
		}
		xx*=xx;
		n>>=1;
		if(mod){
			re%=mod;
			xx%=mod;
		}
	}
	return re;
}

const INT Amod=998244353;

int main(int argc,char** argv){
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	while(t--){
		INT n;
		cin>>n;
		if(n<=4){
			cout<<n<<endl;
			continue;
		}
		INT xx=n/3;
		INT mod=n%3;
		DBG cerr<<"xx="<<xx<<" mod="<<mod<<endl;
		INT ans=0;
		if(mod==0){
			ans=superx(3,xx,Amod);
		}else if(mod==1){
			ans=superx(3,xx-1,Amod)%Amod;
			ans*=4;
			ans%=Amod;
		}else{
			ans=superx(3,xx,Amod)*2%Amod;
		}
		cout<<ans<<endl;
	}
	return 0;
}
```

### `Tag`

```txt
math 數學
觀察
greedy
```

## `ZJ h400` 蛋糕店促銷（困難版）

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

INT superx(INT a,INT n,INT mod=0){
	INT re=1;
	INT xx=a;
	while(n>0){

		if(n&1){
			re*=xx;
		}
		xx*=xx;
		n>>=1;
		if(mod){
			re%=mod;
			xx%=mod;
		}
	}
	return re;
}

const INT Amod=998244353;

int main(int argc,char** argv){
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	while(t--){
		INT n;
		cin>>n;
		if(n<=4){
			cout<<n<<endl;
			continue;
		}
		INT xx=n/3;
		INT mod=n%3;
		DBG cerr<<"xx="<<xx<<" mod="<<mod<<endl;
		INT ans=0;
		if(mod==0){
			ans=superx(3,xx,Amod);
		}else if(mod==1){
			ans=superx(3,xx-1,Amod)%Amod;
			ans*=4;
			ans%=Amod;
		}else{
			ans=superx(3,xx,Amod)*2%Amod;
		}
		cout<<ans<<endl;
	}
	return 0;
}
```

### `Tag`

```txt
math 數學
觀察
greedy
exponentiating by squaring 平方求冪
```

##

##

<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">
