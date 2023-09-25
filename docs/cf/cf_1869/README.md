# `CF 1869` <br>Codeforces Round 896 (Div. 2)
[`back`](../)

> [`CF 1869 PA` Make It Zero](#pa)  
> [`CF 1869 PB` 2D Traveling](#pb)  
> [`CF 1869 PC` Fill in the Matrix](#pc)  

# PA
`CF 1869 PA` Make It Zero
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
> Tag:
> `bit運算`,`math`,`greedy`,`想法`

# PB
`CF 1869 PB` 2D Traveling
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
> Tag:
> `math`,`greedy`,`想法`

# PC
`CF 1868 PA` `CF 1869 PC` Fill in the Matrix
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
> Tag:
> `math`,`想法`


