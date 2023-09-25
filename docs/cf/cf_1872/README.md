# `CF 1872` <br>Codeforces Round 895 (Div. 3)
[`back`](../)

> [`CF 1872 PA` Two Vessels](#pa)  
> [`CF 1872 PB` The Corridor or There and Back Again](#pb)  
> [`CF 1872 PC` Non-coprime Split](#pc)  
> [`CF 1872 PD` Plus Minus Permutation](#pd)  
> [`CF 1872 PE` Data Structures Fan](#pe)  



## pA
`cf 1872 PA` Two Vessels  
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
		INT a,b,c;
		cin>>a>>b>>c;
		INT n=abs(a-b);
		c*=2;
		INT ans=n/c+(n%c?1:0);
		cout<<ans<<endl;
	}
	return 0;
}
```

## pB
`cf 1872 PB` The Corridor or There and Back Again  
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
		INT ans=-1;
		while(n--){
			INT a,b;
			cin>>a>>b;
			b++;
			b/=2;
			b--;
			a+=b;
			if(ans==-1)ans=a;
			else ans=min(ans,a);
		}
		cout<<ans<<endl;
	}
	return 0;
}
```

## pC
`cf 1872 PC` Non-coprime Split  
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
const INT nn=100000;
INT ll[nn+5];
vector<INT> odlst;
void ggetod(INT n=nn){
	memset(ll,0,sizeof(ll));
	odlst.push_back(2);
	for(INT i=3;i<=n;i++){
		if(ll[i]<=1){
			odlst.push_back(i);
		}
		for(INT j:odlst){
			if(j*i>n)break;
			ll[j*i]=j;
			if(j==ll[i])break;
		}
	}
}

int main(int argc,char** argv){
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	ggetod();
	INT t=read(int);
	while(t--){
		INT l,r;
		cin>>l>>r;
		INT t=4;
		if(r<4){
			cout<<-1<<endl;
			continue;
		}
		bool ans=0;
		while(t-- && !ans){
			if(l>r)break;
			INT bse=0;
			for(INT i:odlst){
				//DBG cerr<<" i="<<i<<endl;
				if(i>=l)break;
				if(l%i==0){
					bse=i;
					break;
				}
			}
			//DBG cerr<<"l="<<l<<"bse="<<bse<<endl;
			if(!bse){
				l++;
				continue;
			}
			cout<<bse<<" ";
			l-=bse;
			cout<<l<<endl;
			ans=1;
			break;
		}
		if(!ans)cout<<-1<<endl;
	}
	return 0;
}
```

## pD
`cf 1872 PD` Plus Minus Permutation  
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
		INT n,x,y;
		cin>>n>>x>>y;
		if(x==y){
			cout<<0<<endl;
			continue;
		}
		INT ad=0;
		INT mn=0;
		INT xxx=__gcd(x,y);
		INT aaa=x*(y/xxx);
		INT sme=n/aaa;
		INT adcnt=n/x-sme;
		INT mncnt=n/y-sme;
		ad=(n+(n-adcnt+1))*adcnt/2;
		mn=(1+mncnt)*mncnt/2;
		cout<<ad-mn<<endl;
	}
	return 0;
}
```

## pE
`cf 1872 PE` Data Structures Fan  
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
		INT a[n+1];
		for(INT i=1;i<=n;i++){
			cin>>a[i];
		}
		bool b[n+1];
		string str;
		cin>>str;
		for(INT i=1;i<=n;i++){
			b[i]=(str[i-1]=='1');
		}
		INT addall[n+1]={};
		INT ans[2]={};
		for(INT i=1;i<=n;i++){
			addall[i]=addall[i-1]^a[i];
			ans[b[i]]^=a[i];
		}
		INT q=read(INT);
		while(q--){
			INT inin=read(INT);
			if(inin==2){
				cout<<ans[read(INT)]<<" ";
			}else{
				INT l,r;
				cin>>l>>r;
				l--;
				ans[0]^=addall[r]^addall[l];
				ans[1]^=addall[r]^addall[l];
			}
		}
		cout<<endl;

	}
	return 0;
}
```




[`Codeforces`]: /OJ_ans/cf
[`Zerojudge`]: /OJ_ans/zj
[`PCIC`]: /OJ_ans/PCIC