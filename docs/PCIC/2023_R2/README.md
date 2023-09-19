# [`PCIC`] > `PCIC 2023_R2`

> [題目](./R2_All.pdf)  
> [`PCIC 2023_R2 PA` 戀愛家教(Edward)](#pA)  
> [`PCIC 2023_R2 PB` 有限阿貝爾群(Finite Abelian Group)](#pB)  
> [`PCIC 2023_R2 PC` 山道猴子(Road Monkey)](#pC)  
> [`PCIC 2023_R2 PD` 魔法之域(Magic Realm)](#pD)  
> ~~[`PCIC 2023_R2 PE` 魔數師(Magician)](#pE)~~  

## pA
`PCIC 2023_R2 PA` 戀愛家教(Edward)
`100/100`
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
	for(int i=0;i<argc;i++){
		string nwstr=argv[i];
		if(nwstr=="-Dev"){
			debug=1;
			noTLE=0;
		}else if(nwstr=="-TLE"){
			noTLE=0;
		}
	}
	if(noTLE && !debug){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
	DBG cerr<<"=====DBG mod====="<<endl;
	INT t=read(INT);
	INT ans=0;
	while(t--){
		string str;
		INT a;
		cin>>str>>a;
		INT bg=0;
		for(char c:str){
			if('A'<=c && c<='Z')bg++;
		}
		if(bg*2>=str.size()){
			ans+=a;
		}
	}
	cout<<ans<<endl;
	return 0;
}
```
## pB
`PCIC 2023_R2 PB` 有限阿貝爾群(Finite Abelian Group)
`100/100`
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


int swmp[4][4]={
	{0,1,2,3},
	{1,3,0,2},
	{2,0,3,1},
	{3,2,1,0}
};

char rp(char a,char b){
	return 'a'+swmp[a-'a'][b-'a'];
}

string str;
INT p;
INT n;


char solve(INT deep=0){
	char bef='0';
	for(;p<n;){
		DBG{
			for(INT i=0;i<deep;i++){
				cout<<"|";
			}
		}
		char nw='0';
		if(str[p]=='('){
			p++;
			nw=solve(deep+1);
		}else if(str[p]==')'){
			DBG cout<<bef<<endl;
			return bef;
		}else if(str[p]=='*'){
			p++;
			DBG cout<<endl;
			continue;
		}else{
			nw=str[p];
		}

		if(bef=='0'){
			bef=nw;
			DBG cout<<bef<<endl;
			p++;
			continue;
		}else{
			bef=rp(bef,nw);
			DBG cout<<bef<<endl;
			p++;
			continue;
		}
	}
	return bef;
}

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
	if(noTLE && !debug){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
	DBG cerr<<"=====DBG mod====="<<endl;
	cin>>str;
	p=0;
	n=str.size();
	cout<<solve()<<endl;
	return 0;
}
```

## pC
`PCIC 2023_R2 PC` 山道猴子(Road Monkey)
`100/100`
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
	for(int i=0;i<argc;i++){
		string nwstr=argv[i];
		if(nwstr=="-Dev"){
			debug=1;
			noTLE=0;
		}else if(nwstr=="-TLE"){
			noTLE=0;
		}
	}
	if(noTLE && !debug){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
	DBG cerr<<"=====DBG mod====="<<endl;
	INT t=1;
	while(t--){
		INT n,x,y,t;
		cin>>n>>x>>y>>t;
		n+=1;
		PII lst[n+1];
		lst[0]={0,0};
		for(INT i=1;i<n;i++){
			cin>>lst[i].first>>lst[i].second;
		}
		lst[n]={t,x*t+5};
		DBG cerr<<lst[n].second<<endl;
		// INT finalrun=0;
		// finalrun=t-lst[n-1].first;
		// finalrun*=x;
		INT basicsp=0;//到最後一個測站時的速度
		for(INT i=0;i<n;i++){
			INT road=lst[i+1].first-lst[i].first;
			basicsp=basicsp+road*x;
			basicsp=min(basicsp,lst[i+1].second);
			DBG cerr<<basicsp<<" ";
		}

		cout<<basicsp<<endl;;
	}
	return 0;
}
```

## pD
`PCIC 2023_R2 PD` 魔法之域(Magic Realm)
`100/100`
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

struct superfloat{
	INT up;
	INT dn;
	void fix(){
		INT xx=__gcd(up,dn);
		up/=xx;
		dn/=xx;
	}
};
bool operator<(superfloat a,superfloat b){
	INT xx=__gcd(a.dn,b.dn);
	INT ax=b.dn/xx;
	INT bx=a.dn/xx;
	INT aa=a.up*ax;
	INT bb=b.up*bx;
	return aa<bb;
}

bool operator==(superfloat a,superfloat b){
	return a.up==b.up && a.dn==b.dn;
}

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
	if(noTLE && !debug){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
	DBG cerr<<"=====DBG mod====="<<endl;
	INT n=read(INT);
	superfloat lst[n];
	for(INT i=0;i<n;i++){
		cin>>lst[i].up;
	}
	for(INT i=0;i<n;i++){
		cin>>lst[i].dn;
		lst[i].fix();
	}
	sort(lst,lst+n);
	INT ans=0;
	INT xx=0;
	for(INT i=n-1;i>=0;i--){
		xx++;
		if(!(lst[i]==lst[i-1])){
			ans+=i*xx;
			xx=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}
```

## pE
整理中





[`Codeforces`]: /OJ_ans/cf
[`Zerojudge`]: /OJ_ans/zj
[`PCIC`]: /OJ_ans/PCIC