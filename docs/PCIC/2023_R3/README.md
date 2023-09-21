# [`PCIC`] > `PCIC 2023_R3`

> [題目](./R3_All.pdf)  
> [`PCIC 2023_R3 PA` `100/100` 旮旯同學亂填表單(Corner)](#PA)  
> [`PCIC 2023_R3 PB` `100/100` 能量飲料(Energy Drink)](#PB)  
> [`PCIC 2023_R3 PC` `100/100` 衛冕優勝者(Defending Winners)](#PC)  
> [`PCIC 2023_R3 PD` `070/100` 蘋果哥哥消蘋果(Fruit Box)](#PD)  
> [`PCIC 2023_R3 PE` `100/100` 密室尋寶(Treasure)](#PE)  

## PA
`PCIC 2023_R3 PA` 旮旯同學亂填表單(Corner)
`100/100`
```c++
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl '\n'
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
bool debug=0;
bool noTLE=1;
template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}

struct dta{
	INT a=0;
	INT b=0;
	INT c=0;
};

bool operator==(dta a,INT b){
	if(a.a==b || a.b==b || a.c==b)return 1;
	else return 0;
}

int main(int argc,char** argv){
	if(!debug && noTLE){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
	INT n;
	cin>>n;
	map<INT,dta> mp;
	for(INT i=0;i<n;i++){
		INT id;
		dta nw;
		cin>>id>>nw.a>>nw.b>>nw.c;
		if(mp[id]==(INT)0){
			mp[id]=nw;
		}
	}
	INT ansa=0,ansb=0,ansc=0;
	for(pair<INT,dta> i:mp){
		ansa+=i.second.a;
		ansb+=i.second.b;
		ansc+=i.second.c;
	}
	cout<<ansa<<" "<<ansb<<" "<<ansc<<endl;
}
```

## PB
`PCIC 2023_R3 PB` 能量飲料(Energy Drink)
`100/100`
```c++
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl '\n'
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
#define tmin(a,b) a=min(a,b)
bool debug=0;
bool noTLE=0;
template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}

int main(int argc,char** argv){
	if(!debug && noTLE){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
	INT n=read(INT);
	INT road[n+2]={};
	INT dp[n+2]={};
	for(INT i=0;i<=n;i++){
		dp[i]=(INT)1e9;
		road[i]=0;
	}
	for(INT i=1;i<=n;i++){
		road[i]=read(INT);
	}
	dp[1]=0;
	deque<INT> dq;
	dq.push_back(1);
	bool in[n+2]={};
	in[1]=1;
	while(!dq.empty()){
		INT nw=dq.front();
		dq.pop_front();
		in[nw]=0;
		//walk
		if(dp[nw]+1<dp[nw+1]){
			dp[nw+1]=dp[nw]+1;
			if(!in[nw+1]){
				in[nw+1]=1;
				dq.push_back(nw+1);
			}
		}
		//jump
		if(dp[nw]+1<dp[road[nw]]){
			dp[road[nw]]=dp[nw]+1;
			if(!in[road[nw]]){
				in[road[nw]]=1;
				dq.push_back(road[nw]);
			}
		}
		DBG{
			cerr<<"nw="<<nw<<endl;
			for(INT i=1;i<=n;i++){
				cerr<<dp[i]<<" ";
			}
			cerr<<endl;
		}
	}
	cout<<dp[n]<<endl;
}
```

## PC
`PCIC 2023_R3 PC` 衛冕優勝者(Defending Winners)
`100/100`
```c++
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl '\n'
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
bool debug=0;
bool noTLE=0;
template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}

int main(int argc,char** argv){
	if(!debug && noTLE){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
	INT n,m;
	cin>>n>>m;
	INT a[n][m];
	for(INT i=0;i<n;i++){
		for(INT j=0;j<m;j++){
			cin>>a[i][j];
		}
	}

	INT lastw[n*m+1];
	INT cnt[n*m+1];
	INT ans=0;
	for(INT i=0;i<=n*m;i++){
		lastw[i]=1000;
		cnt[i]=0;
	}

	for(INT i=0;i<n;i++){

		for(INT j=0;j<m;j++){
			if(lastw[a[i][j]]==i-1){
				cnt[a[i][j]]++;
			}else{
				cnt[a[i][j]]=1;
			}
			lastw[a[i][j]]=i;
			ans=max(ans,cnt[a[i][j]]);
		}
	}
	cout<<ans<<endl;
}
```

## PD
`PCIC 2023_R3 PD` 蘋果哥哥消蘋果(Fruit Box)
`070/100`
***下方兩隻程式皆須上傳，才可得到70分***

### `025/100`
> - [ ] 1. `000/000`  
> - [X] 2. `025/025`  
> - [ ] 3. `000/020`  
> - [ ] 4. `000/025`  
> - [ ] 5. `000/030`  

```c++
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl '\n'
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
bool debug=0;
bool noTLE=0;
template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}

int main(int argc,char** argv){
	if(!debug && noTLE){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
	INT n;
	cin>>n;
	INT dp[n+1]={};
	INT apple[n+1]={};
	for(INT i=1;i<=n;i++){
		cin>>apple[i];
		INT nw=0;
		INT j=i;
		while(j>0 && nw<10){
			nw+=apple[j];
			j--;
		}
		if(nw!=10)dp[i]=dp[i-1];
		else{
			dp[i]=max(dp[i-1],dp[j]+(i-j));
		}
	}
	cout<<dp[n]<<" "<<1<<endl;//	025/100
	//cout<<dp[n]<<" "<<-1<<endl;//	060/100
	//兩個上傳可以得到 070/100
}
```

### `060/100`
> - [X] 1. `000/000`  
> - [X] 2. `015/025`  
> - [X] 3. `012/020`  
> - [X] 4. `015/025`  
> - [X] 5. `018/030`  

```c++
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl '\n'
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
bool debug=0;
bool noTLE=0;
template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}

int main(int argc,char** argv){
	if(!debug && noTLE){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
	INT n;
	cin>>n;
	INT dp[n+1]={};
	INT apple[n+1]={};
	for(INT i=1;i<=n;i++){
		cin>>apple[i];
		INT nw=0;
		INT j=i;
		while(j>0 && nw<10){
			nw+=apple[j];
			j--;
		}
		if(nw!=10)dp[i]=dp[i-1];
		else{
			dp[i]=max(dp[i-1],dp[j]+(i-j));
		}
	}
	//cout<<dp[n]<<" "<<1<<endl;//	025/100
	cout<<dp[n]<<" "<<-1<<endl;//	060/100
	//兩個上傳可以得到 070/100
}
```

## PE
`PCIC 2023_R3 PE` 密室尋寶(Treasure)
`100/100`
```c++
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl '\n'
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
bool debug=0;
bool noTLE=0;
template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}

const INT mxn=2e5;
INT n;
INT a[mxn];
vector<INT> vec[mxn];
bool disab[mxn];	

vector<INT> anslst;
vector<INT> nwlst;
bool vis[mxn];

bool vser(INT a,INT b){return a<b;}

void dfs(INT nw=0){
	vis[nw]=1;
	nwlst.push_back(nw);
	for(INT i:vec[nw]){
		if(vis[i])continue;
		if(nw>0 && a[i]<a[nw])continue;//拿到更小的寶相
		//if(nw>0 && vec[i].size()>2)continue;//進入有>=3條通道的房間
		DBG cerr<<"id:"<<nw<<"->"<<i<<endl;
		DBG cerr<<"sz:"<<a[nw]<<"->"<<a[i]<<endl;
		dfs(i);
	}
	if(nwlst.size()>anslst.size()){
		anslst.clear();
		anslst.reserve(n);
		for(INT i:nwlst){
			anslst.push_back(i);
		}
	}
	nwlst.pop_back();
	vis[nw]=0;
}


int main(int argc,char** argv){
	if(!debug && noTLE){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
	cin>>n;
	for(INT i=0;i<n;i++){
		cin>>a[i];
	}
	for(INT i=1;i<n;i++){
		INT x,y;
		cin>>x>>y;
		x--;y--;
		vec[x].push_back(y);
		vec[y].push_back(x);
		if(x>1 && vec[x].size()>2){
			disab[x]=1;
		}
		if(y>1 && vec[y].size()>2){
			disab[y]=1;
		}
	}
	anslst.reserve(n);
	nwlst.reserve(n);
	for(INT i=0;i<n;i++){
		sort(vec[i].begin(),vec[i].end());
	}
	dfs();
	cout<<anslst.size()<<endl;
	bool ot=0;
	for(INT i:anslst){
		if(ot)cout<<" ";
		cout<<i+1;
		ot=1;
	}
	cout<<endl;
}
```







[`Codeforces`]: /OJ_ans/cf
[`Zerojudge`]: /OJ_ans/zj
[`PCIC`]: /OJ_ans/PCIC