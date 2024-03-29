# `PCIC 2023_R1`

[`back`](../)

## `PCIC 2023_R1 PA` 尖叫雞的三角形詛咒(Triangle Curse)

[`題目`](./pA.pdf)

### `Score`

```diff
+ 100/100
```

### `C++`

```c++
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define ET01 cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define DBG if(debug)
bool debug=0;
bool iofast=1;

template<typename TPE>TPE reader(){
	TPE re;
	cin>>re;
	return re;
}
#define read( n ) reader< n >()
int main(){
	if(iofast){ET01}
	INT t=1;
	while(t--){
		INT n=read(INT);
		vector<INT> vec;
		vec.reserve(n);
		for(INT i=0;i<n;i++){
			vec.push_back(read(INT));
		}
		sort(vec.begin(),vec.end());
		bool ans=0;
		for(INT i=1;i<n-1 && !ans;i++){
			if(vec[i]+vec[i-1]>vec[i+1]){
				ans=1;
			}
		}
		if(ans){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
```

## `PCIC 2023_R1 PB` 堅持下去(Give Up)

[`題目`](./pB.pdf)

### `Score`

```diff
+ 100/100
```

### `C++`

```c++
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define ET01 cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define DBG if(debug)
bool debug=0;
bool iofast=1;

template<typename TPE> TPE reader(){
	TPE re;
	cin>>re;
	return re;
}
#define read(n) reader<n>()

int main(){
	if(iofast){ET01}
	INT t=1;
	while(t--){
		INT n=read(INT);
		map<string,string> mp;
		while(n--){
			string a=read(string);
			string b=read(string);
			mp[a]=b;
		}
		string nw;
		bool st=0;
		while(cin>>nw){
			if(st)cout<<" ";
			cout<<mp[nw];
			st=1;
		}
		cout<<endl;
	}
	return 0;
}
```

## `PCIC 2023_R1 PC` 拆地雷(Minesweeper)

[`題目`](./pC.pdf)

### `Score`

```diff
+ 100/100
```

### `C++`

```c++
//[AC]
#include "Minesweeper.h"
#include<bits/stdc++.h>
using namespace std;
#define DBG if(debug)
bool debug=0;
//----do not modify above----
void defuse_mines(int N){
	int mx[]={-1,-1,-1,0,0,0,1,1,1};
	int my[]={-1,0,1,-1,0,1,-1,0,1};
	int mp[N+5][N+5]={};//表周圍有幾顆地雷
	int mpmn[N+5][N+5]={};
	bool ask[N+1][N+1]={};
	int bomb[N+5][N+5]={};//1保證有地雷
	int rembomb=0;//紀錄已拆除的地雷數量
	pair<int,int> ans[N];
	for(int i=1;i<=N;i++){//初始化
			for(int j=1;j<=N;j++){
				bomb[i][j]=0;
			}
	}
	for(int i=1;i<=N;i++){//最邊邊一定沒有地雷
		bomb[i][1]=0;
		bomb[1][i]=0;
		bomb[i][N]=0;
		bomb[N][i]=0;
	}
	for(int i=3;i<=N;i++){//拆雷
		if(i%3 && i!=N)continue;
		if(rembomb>=N)break;
		for(int j=3;j<=N;j++){
			if(j%3 && j!=N)continue;
			if(rembomb>=N)break;
			if(!ask[i][j]){
				mp[i][j]=detect(i,j);
				ask[i][j]=1;
			}
			if(mp[i][j]==0){//周圍沒地雷
				for(int k=0;k<9;k++){//拆
					int nx=i+mx[k];
					int ny=j+my[k];
					if(1<=nx && nx<=N &&
						1<=ny && ny<=N
					){
						bomb[i][1]=1;
					}
				}
			}else{//周圍有地雷
				int cx=i-1;
				int cy=j-1;
				int nwbmb=mp[i][j];
				for(int k=0;k<9;k++){//九宮格搜尋
					if(rembomb==N)break;
					if(!nwbmb){
						bomb[cx+1][cy+1]=0;
					}
					int nx=cx+mx[k];
					int ny=cy+my[k];
					if(1<=nx && nx<=N &&
						1<=ny && ny<=N
						){
						if(!ask[nx][ny]){
							mp[nx][ny]=detect(nx,ny);
							ask[nx][ny]=1;
						}
						int nwfnd=mp[nx][ny]-mpmn[nx][ny];
						if(nwfnd==0){
							bomb[nx+1][ny+1]=0;
						}else{
							bomb[nx+1][ny+1]=1;
							defuse(nx+1,ny+1);
							for(int ii=0;ii<9;ii++){
								mpmn[nx+1+mx[ii]][ny+1+my[ii]]+=1;
							}
							rembomb++;
							nwbmb--;
						}
					}
				}
			}
		}
	}
}
```

## `PCIC 2023_R1 PD` 長頸鹿(Giraffe)

[`題目`](./pD.pdf)

### `Score`

```diff
+ 100/100
```

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

struct dta{
	INT id=0;
	INT w=0;
	INT a=0;
	INT l=0;
	string sortby="WAL";
	INT getv(char c){
		if(c=='w' || c=='W')return w;
		else if(c=='a' || c=='A')return a;
		else return l;
	}
};
struct vser{
	bool operator()(dta a,dta b){
		for(INT i=0;i<3;i++){
			if(a.getv(a.sortby[i])!=b.getv(b.sortby[i])){
				return a.getv(a.sortby[i])>b.getv(b.sortby[i]);
			}
		}
		return a.id>b.id;
	}
};

int main(int argc,char** argv){
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=1;
	while(t--){
		INT n,m,q;
		cin>>n>>m>>q;
		string s[n];
		for(INT i=0;i<n;i++){
			cin>>s[i];
		}
		priority_queue<dta,vector<dta>,vser> pq_WAL;
		priority_queue<dta,vector<dta>,vser> pq_WLA;
		priority_queue<dta,vector<dta>,vser> pq_AWL;
		priority_queue<dta,vector<dta>,vser> pq_ALW;
		priority_queue<dta,vector<dta>,vser> pq_LAW;
		priority_queue<dta,vector<dta>,vser> pq_LWA;
		vector<dta> vec;
		vec.reserve(m+q);
		INT id=0;
		for(;id<m;){
			dta nw;
			cin>>nw.w>>nw.a>>nw.l;
			nw.id=id;
			vec.push_back(nw);
			nw.sortby="WAL";pq_WAL.push(nw);
			nw.sortby="WLA";pq_WLA.push(nw);
			nw.sortby="AWL";pq_AWL.push(nw);
			nw.sortby="ALW";pq_ALW.push(nw);
			nw.sortby="LAW";pq_LAW.push(nw);
			nw.sortby="LWA";pq_LWA.push(nw);
			id++;
		}
		INT ans[n][3]={};
		INT mp[m+q+5]={};
		while(q--){
			INT a=read(INT);
			if(a==1){
				dta nw;
				cin>>nw.w>>nw.a>>nw.l;
				nw.id=id;
				vec.push_back(nw);
				nw.sortby="WAL";pq_WAL.push(nw);
				nw.sortby="WLA";pq_WLA.push(nw);
				nw.sortby="AWL";pq_AWL.push(nw);
				nw.sortby="ALW";pq_ALW.push(nw);
				nw.sortby="LAW";pq_LAW.push(nw);
				nw.sortby="LWA";pq_LWA.push(nw);
				id++;
			}else{
				INT b=read(INT)-1;
				INT tk=0;
				if(s[b]=="WAL"){while(!pq_WAL.empty() && mp[pq_WAL.top().id])pq_WAL.pop();tk=pq_WAL.top().id;}
				if(s[b]=="WLA"){while(!pq_WLA.empty() && mp[pq_WLA.top().id])pq_WLA.pop();tk=pq_WLA.top().id;}
				if(s[b]=="AWL"){while(!pq_AWL.empty() && mp[pq_AWL.top().id])pq_AWL.pop();tk=pq_AWL.top().id;}
				if(s[b]=="ALW"){while(!pq_ALW.empty() && mp[pq_ALW.top().id])pq_ALW.pop();tk=pq_ALW.top().id;}
				if(s[b]=="LAW"){while(!pq_LAW.empty() && mp[pq_LAW.top().id])pq_LAW.pop();tk=pq_LAW.top().id;}
				if(s[b]=="LWA"){while(!pq_LWA.empty() && mp[pq_LWA.top().id])pq_LWA.pop();tk=pq_LWA.top().id;}
				ans[b][0]+=vec[tk].w;
				ans[b][1]+=vec[tk].a;
				ans[b][2]+=vec[tk].l;
				mp[tk]=1;
			}
		}
		for(INT i=0;i<n;i++){
			cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
		}
	}
	return 0;
}
```

## `PCIC 2023_R1 PE` 戀愛關係(Relationship)

[`題目`](./pE.pdf)

### `Score`

```diff
+ 100/100
```

### `C++`

```c++
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define ET01 cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define DBG if(debug)
bool debug=0;
bool iofast=1;
//長頸鹿的資料
#define dta map<char,INT>

template<typename TPE> TPE reader(){
	TPE re;
	cin>>re;
	return re;
}
#define read(n) reader<n>()

int main(){
	if(iofast){ET01}
	INT t=1;
	while(t--){
		INT n=read(INT);
		INT a[n];
		for(INT i=0;i<n;i++){
			a[i]=read(INT)-1;
		}

		bool inlove[n]={};//1=in love
		INT eme[n]={};//有eme[i]個人愛i
		for(INT i=0;i<n;i++){
			if(a[a[i]]==i){
				inlove[i]=inlove[a[i]]=1;
			}else{
				inlove[i]=0;
				eme[a[i]]++;
			}
		}
		for(INT i=0;i<n;i++){
			if(inlove[i]){
				cout<<"\\owo/"<<endl;
			}else if(inlove[a[i]]){
				cout<<"\\|/"<<endl;
			}else{
				cout<<eme[a[i]]-1<<endl;
			}
		}
	}
	return 0;
}
```

[`Codeforces`]: /OJ_ans/cf
[`Zerojudge`]: /OJ_ans/zj
[`PCIC`]: /OJ_ans/PCIC

<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">
