<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `TP 2023_11_EZ` `300/300` TOI練習賽 2023/11 新手組

## [`TP 2023_11_EZ_PA`] `100/100` 狼人殺
[`TP 2023_11_EZ_PA`]: ./2023_11_easy/PA.pdf
### `C++`
```cpp
//O(nnmm)
#include<bits/stdc++.h>

using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
template<typename tpe>tpe reader(){tpe re;cin>>re;return re;}

function<int(INT)> solve=[](INT casenum){
	INT n=read(INT);
	INT lst[n+1]={};
	INT bad=0;
	for(INT i=1;i<=n;i++){
		lst[i]=read(INT);
		if(lst[i]==-1){
			bad++;
		}
	}
	INT op;
	bool flag=1;
	while(cin>>op){
		if(op==0){
			break;
		}else{
			if(lst[op]==-10){
				cout<<"Wrong"<<endl;
				flag=0;
			}
			if(lst[op]==-1){
				bad--;
			}
			lst[op]=-10;
		}
	}
	if(flag){
		if(bad<=0){
			cout<<"Townsfolk"<<endl;
		}else{
			cout<<"Werewolves"<<endl;
		}
	}
	return 0;
};



int main(int argc,char** argv){
	{cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
  solve(i);
	return 0;
}
```

## [`TP 2023_11_EZ_PB`] `100/100` 書房
[`TP 2023_11_EZ_PB`]: ./2023_11_easy/PB.pdf
### `C++`
```c++
#include<bits/stdc++.h>

using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
template<typename tpe>tpe reader(){tpe re;cin>>re;return re;}

function<int(INT)> solve=[](INT casenum){
	INT n,m;
	cin>>n>>m;
	INT ans[m+1]={};
	for(INT i=1;i<=n;i++){
		INT a;
		cin>>a;
		if(a>0){
			ans[a]=i;
		}
	}
	for(INT i=1;i<=m;i++){
		if(i>1)cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
};



int main(int argc,char** argv){
	{cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
	solve(i);
	return 0;
}
```

## [`TP 2023_11_EZ_PC`] `100/100` 精靈王國
[`TP 2023_11_EZ_PC`]: ./2023_11_easy/PC.pdf
###` C++`
```c++
#include<bits/stdc++.h>

using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
template<typename tpe>tpe reader(){tpe re;cin>>re;return re;}

function<int(INT)> solve=[](INT casenum){
	INT n;
	cin>>n;
	INT a[n+1];
	INT ans=0;
	INT nw=0;
	for(INT i=1;i<=n;i++){
		cin>>a[i];
	}
	for(INT i=1;i<=n;i++){
		INT p=i;
		if(a[i]){
			nw=0;
			do{
				INT lst=p;
				p=a[p];
				a[lst]=0;
				nw++;
			}while(p!=i);
		}
		maxs(ans,nw);
	}
	cout<<ans<<endl;
	return 0;
};



int main(int argc,char** argv){
	{cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
	solve(i);
	return 0;
}
```
## `Tag`
```txt
圖論
```
