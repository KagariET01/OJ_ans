<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 1873`<br>Codeforces Round 898 (Div. 4)
[`back`](../)

> ## `CF 1873 PA`<br>Short Sort
> ### `c++`
> ```c++
> #include<bits/stdc++.h>
> using namespace std;
> #define INT long long int
> #define endl "\n"
> #define read(n) reader<n>()
> #define DBG if(debug)
> #define PII pair<INT,INT>
> bool debug=0;
> bool noTLE=1;
> template<typename tpe>tpe reader(){
> 	tpe re;cin>>re;return re;
> }
> int main(int argc,char** argv){
> 	auto solve=[](INT casenum){
> 		string astr[4]={
> 			"abc",
> 			"acb",
> 			"bac",
> 			"cba"
> 		};
> 		string str=read(string);
> 		for(string a:astr){
> 			if(str==a)return 1;
> 		}
> 		return 0;
> 	};
> 	bool one_case=0;
> 	bool ynans=1;
> 	string yes="yes";
> 	string no="no";
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 	INT t=(one_case?1:read(int));
> 	for(INT i=0;i<t;i++){
> 		if(!ynans){
> 			solve(i);
> 		}else{
> 			if(solve(i)){
> 				cout<<yes<<endl;
> 			}else{
> 				cout<<no<<endl;
> 			}
> 		}
> 	}
> 	return 0;
> }
> ```

> ## `CF 1873 PB`<br>Good Kid
> ### `c++`
> ```c++
> #include<bits/stdc++.h>
> using namespace std;
> #define INT long long int
> #define endl "\n"
> #define read(n) reader<n>()
> #define DBG if(debug)
> #define PII pair<INT,INT>
> bool debug=0;
> bool noTLE=1;
> template<typename tpe>tpe reader(){
> 	tpe re;cin>>re;return re;
> }
> int main(int argc,char** argv){
> 	auto solve=[](INT casenum){
> 		INT n=read(INT);
> 		INT a[n];
> 		for(INT i=0;i<n;i++)cin>>a[i];
> 		INT asn=0;
> 		for(INT i=0;i<n;i++){
> 			INT nw=1;
> 			for(INT j=0;j<n;j++){
> 				if(i==j)nw*=(a[j]+1);
> 				else nw*=a[j];
> 			}
> 			asn=max(asn,nw);
> 		}
> 		cout<<asn<<endl;
> 		return 0;
> 	};
> 	bool one_case=0;
> 	bool ynans=0;
> 	string yes="yes";
> 	string no="no";
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 	INT t=(one_case?1:read(int));
> 	for(INT i=0;i<t;i++){
> 		if(!ynans){
> 			solve(i);
> 		}else{
> 			if(solve(i)){
> 				cout<<yes<<endl;
> 			}else{
> 				cout<<no<<endl;
> 			}
> 		}
> 	}
> 	return 0;
> }
> ```

> ## `CF 1873 PC`<br>Target Practice
> ### `c++`
> ```c++
> #include<bits/stdc++.h>
> using namespace std;
> #define INT long long int
> #define endl "\n"
> #define read(n) reader<n>()
> #define DBG if(debug)
> #define PII pair<INT,INT>
> bool debug=0;
> bool noTLE=1;
> template<typename tpe>tpe reader(){
> 	tpe re;cin>>re;return re;
> }
> int main(int argc,char** argv){
> 	auto solve=[](INT casenum){
> 		INT xxmp[10][10]={
> 			{1,1,1,1,1,1,1,1,1,1},
> 			{1,2,2,2,2,2,2,2,2,1},
> 			{1,2,3,3,3,3,3,3,2,1},
> 			{1,2,3,4,4,4,4,3,2,1},
> 			{1,2,3,4,5,5,4,3,2,1},
> 			{1,2,3,4,5,5,4,3,2,1},
> 			{1,2,3,4,4,4,4,3,2,1},
> 			{1,2,3,3,3,3,3,3,2,1},
> 			{1,2,2,2,2,2,2,2,2,1},
> 			{1,1,1,1,1,1,1,1,1,1}
> 		};
> 		INT ans=0;
> 		for(INT i=0;i<10;i++){
> 			string str=read(string);
> 			for(INT j=0;j<10;j++){
> 				ans+=xxmp[i][j]*(str[j]=='X'?1:0);
> 			}
> 		}
> 		cout<<ans<<endl;
> 		return 0;
> 	};
> 	bool one_case=0;
> 	bool ynans=0;
> 	string yes="yes";
> 	string no="no";
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 	INT t=(one_case?1:read(int));
> 	for(INT i=0;i<t;i++){
> 		if(!ynans){
> 			solve(i);
> 		}else{
> 			if(solve(i)){
> 				cout<<yes<<endl;
> 			}else{
> 				cout<<no<<endl;
> 			}
> 		}
> 	}
> 	return 0;
> }
> ```

> ## `CF 1873 PD`<br>1D Eraser
> ### `c++`
> ```c++
> #include<bits/stdc++.h>
> using namespace std;
> #define INT long long int
> #define endl "\n"
> #define read(n) reader<n>()
> #define DBG if(debug)
> #define PII pair<INT,INT>
> bool debug=0;
> bool noTLE=1;
> template<typename tpe>tpe reader(){
> 	tpe re;cin>>re;return re;
> }
> int main(int argc,char** argv){
> 	auto solve=[](INT casenum){
> 		INT n,m;
> 		cin>>n>>m;
> 		string str=read(string);
> 		INT i=0;
> 		INT ans=0;
> 		while(i<n){
> 			if(str[i]=='B'){
> 				ans++;
> 				i+=m;
> 			}else{
> 				i++;
> 			}
> 		}
> 		cout<<ans<<endl;
> 		return 0;
> 	};
> 	bool one_case=0;
> 	bool ynans=0;
> 	string yes="yes";
> 	string no="no";
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 	INT t=(one_case?1:read(int));
> 	for(INT i=0;i<t;i++){
> 		if(!ynans){
> 			solve(i);
> 		}else{
> 			if(solve(i)){
> 				cout<<yes<<endl;
> 			}else{
> 				cout<<no<<endl;
> 			}
> 		}
> 	}
> 	return 0;
> }
> ```

> ## `CF 1873 PE`<br>Building an Aquarium
> ### `c++`
> ```c++
> #include<bits/stdc++.h>
> using namespace std;
> #define INT long long int
> #define endl "\n"
> #define read(n) reader<n>()
> #define DBG if(debug)
> #define PII pair<INT,INT>
> bool debug=0;
> bool noTLE=1;
> template<typename tpe>tpe reader(){
> 	tpe re;cin>>re;return re;
> }
> 
> vector<INT> vec;
> INT x;
> 
> bool mxer(INT h){
> 	INT nw=0;
> 	for(INT i:vec){
> 		nw+=max((INT)0,h-i);
> 		//if(i>h)break;
> 	}
> 	if(nw<=x)return 1;
> 	else return 0;
> }
> INT BITsearch(INT l,INT r){
> 	while(l<r){
> 		INT mnt=(l+r)/2+1;
> 		if(mxer(mnt)){
> 			l=mnt;
> 		}else{
> 			r=mnt-1;
> 		}
> 	}
> 	return l;
> }
> 
> int main(int argc,char** argv){
> 	auto solve=[](INT casenum){
> 		INT n;
> 		cin>>n>>x;
> 		vec.clear();
> 		vec.reserve(n);
> 		for(INT i=0;i<n;i++){
> 			vec.push_back(read(INT));
> 		}
> 		sort(vec.begin(),vec.end());
> 		cout<<BITsearch((INT)(1),(INT)(1e10+7))<<endl;
> 		return 0;
> 	};
> 	bool one_case=0;
> 	bool ynans=0;
> 	string yes="yes";
> 	string no="no";
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 	INT t=(one_case?1:read(int));
> 	for(INT i=0;i<t;i++){
> 		if(!ynans){
> 			solve(i);
> 		}else{
> 			if(solve(i)){
> 				cout<<yes<<endl;
> 			}else{
> 				cout<<no<<endl;
> 			}
> 		}
> 	}
> 	return 0;
> }
> ```

> ## `CF 1873 PF`<br>Money Trees
> ### `c++`
> ```c++
> #include<bits/stdc++.h>
> using namespace std;
> #define INT long long int
> #define endl "\n"
> #define read(n) reader<n>()
> #define DBG if(debug)
> #define PII pair<INT,INT>
> bool debug=0;
> bool noTLE=1;
> template<typename tpe>tpe reader(){
> 	tpe re;cin>>re;return re;
> }
> int main(int argc,char** argv){
> 	auto solve=[](INT casenum){
> 		INT n,k;
> 		cin>>n>>k;
> 		INT h[n];
> 		INT a[n];
> 		for(INT i=0;i<n;i++){
> 			cin>>a[i];
> 		}
> 		for(INT i=0;i<n;i++){
> 			cin>>h[i];
> 		}
> 		bool cn[n];
> 		cn[0]=1;
> 		for(INT i=1;i<n;i++){
> 			if(h[i-1]%h[i])cn[i]=0;
> 			else cn[i]=1;
> 		}
> 		INT nw=0;
> 		INT ans=0;
> 		INT l=0,r=0;
> 		for(;r<n;r++){
> 			nw+=a[r];
> 			if(!cn[r]){
> 				l=r;
> 				nw=a[r];
> 			}
> 			while(nw>k){
> 				nw-=a[l];
> 				l++;
> 			}
> 			ans=max(ans,r-l+1);
> 		}
> 		cout<<ans<<endl;
> 		return 0;
> 	};
> 	bool one_case=0;
> 	bool ynans=0;
> 	string yes="yes";
> 	string no="no";
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 	INT t=(one_case?1:read(int));
> 	for(INT i=0;i<t;i++){
> 		if(!ynans){
> 			solve(i);
> 		}else{
> 			if(solve(i)){
> 				cout<<yes<<endl;
> 			}else{
> 				cout<<no<<endl;
> 			}
> 		}
> 	}
> 	return 0;
> }
> ```

> ## `CF 1873 PG`<br>ABBC or BACB
> ### `c++`
> ```c++
> #include<bits/stdc++.h>
> using namespace std;
> #define INT long long int
> #define endl "\n"
> #define read(n) reader<n>()
> #define DBG if(debug)
> #define PII pair<INT,INT>
> bool debug=0;
> bool noTLE=1;
> template<typename tpe>tpe reader(){
> 	tpe re;cin>>re;return re;
> }
> int main(int argc,char** argv){
> 	auto solve=[](INT casenum){
> 		string str=read(string);
> 		INT n=str.size();
> 		INT ans=0;
> 		INT nw=0;
> 		INT mn=1e9+7;
> 		INT tot=0;
> 		for(char c:str){
> 			if(c=='A'){
> 				nw++;
> 			}
> 			else{
> 				mn=min(mn,nw);
> 				ans+=nw;
> 				nw=0;
> 			}
> 		}
> 				mn=min(mn,nw);
> 				ans+=nw;
> 				nw=0;
> 		if(str[0]=='B' || str[n-1]=='B'){
> 			cout<<ans<<endl;
> 		}else{
> 			cout<<ans-mn<<endl;
> 		}
> 		//cout<<ans<<endl;
> 		return 0;
> 	};
> 	bool one_case=0;
> 	bool ynans=0;
> 	string yes="yes";
> 	string no="no";
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 	INT t=(one_case?1:read(int));
> 	for(INT i=0;i<t;i++){
> 		if(!ynans){
> 			solve(i);
> 		}else{
> 			if(solve(i)){
> 				cout<<yes<<endl;
> 			}else{
> 				cout<<no<<endl;
> 			}
> 		}
> 	}
> 	return 0;
> }
> ```
> ### `Tag`
> ```txt
> greedy
> ```


> ## `CF 1873 PH`<br>Mad City
> 
> ### [`HINT`](PH)
> 
> ### `c++`
> ```c++
> #include<bits/stdc++.h>
> using namespace std;
> #define INT long long int
> #define endl "\n"
> #define read(n) reader<n>()
> #define DBG if(debug)
> #define PII pair<INT,INT>
> bool debug=0;
> bool noTLE=1;
> template<typename tpe>tpe reader(){
> 	tpe re;cin>>re;return re;
> }
> INT n,a,b;
> const INT mxn=2e5+5;
> vector<INT> tre[mxn];//樹
> bool circ[mxn];//紀錄是否在環上
> bool visi[mxn];//紀錄是否走過
> deque<INT> road;//紀錄走過的路
> INT ato=0;
> INT atolen=1e9+7;
> INT btolen=1e9+7;
> 
> bool findcirc(INT n,INT lst){
> 	DBG cerr<<"n="<<n<<" lst="<<lst<<endl;
> 	if(visi[n] && !circ[n]){//發現環
> 		deque<INT>::iterator i=road.begin();
> 		while(*i!=n)i++;
> 		do{
> 			if(i==road.end())break;
> 			circ[*i]=1;
> 			i++;
> 		}while(*i!=n);
> 		return 1;
> 	}else{
> 		visi[n]=1;
> 		road.push_back(n);
> 		for(INT i:tre[n]){
> 			if(i==lst)continue;
> 			if(circ[i])continue;
> 			if(findcirc(i,n))return 1;
> 		}
> 	}
> 	visi[n]=0;
> 	road.pop_back();
> 	return 0;
> }
> 
> int main(int argc,char** argv){
> 	auto solve=[](INT casenum){
> 		cin>>n>>b>>a;
> 		a--,b--;
> 		for(INT i=0;i<=n;i++){
> 			tre[i].clear();
> 		}
> 		fill(circ,circ+n+1,false);
> 		fill(visi,visi+n+1,false);
> 		road.clear();
> 		for(INT i=0;i<n;i++){
> 			INT u,v;
> 			cin>>u>>v;
> 			u--;v--;
> 			tre[u].push_back(v);
> 			tre[v].push_back(u);
> 		}
> 		findcirc(0,0);
> 		
> 		bool vst[n+5]={};
> 		deque<PII> dq;
> 		dq.push_back({a,0});
> 		vst[a]=1;
> 		atolen=1e9+7;
> 		while(!dq.empty()){
> 			PII nw=dq.front();
> 			dq.pop_front();
> 			if(circ[nw.first]){
> 				ato=nw.first;
> 				atolen=nw.second;
> 				break;
> 			}
> 			for(INT i:tre[nw.first]){
> 				if(!vst[i]){
> 					vst[i]=1;
> 					dq.push_back({i,nw.second+1});
> 				}
> 			}
> 		}
> 
> 		memset(vst,0,sizeof(vst));
> 		dq.clear();
> 		dq.push_back({b,0});
> 		vst[b]=1;
> 		btolen=1e9+7;
> 		while(!dq.empty()){
> 			PII nw=dq.front();
> 			dq.pop_front();
> 			if(nw.first==ato){
> 				//bto=nw.first;
> 				btolen=nw.second;
> 				break;
> 			}
> 			for(INT i:tre[nw.first]){
> 				if(!vst[i]){
> 					vst[i]=1;
> 					dq.push_back({i,nw.second+1});
> 				}
> 			}
> 		}
> 		DBG cerr<<"atolen="<<atolen<<" btolen="<<btolen<<endl;
> 		return (atolen<btolen);
> 	};
> 	bool one_case=0;
> 	bool ynans=1;
> 	string yes="yes";
> 	string no="no";
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 	INT t=(one_case?1:read(int));
> 	for(INT i=0;i<t;i++){
> 		if(!ynans){
> 			solve(i);
> 		}else{
> 			if(solve(i)){
> 				cout<<yes<<endl;
> 			}else{
> 				cout<<no<<endl;
> 			}
> 		}
> 	}
> 	return 0;
> }
> ```
> ### `Tag`
> ```txt
> graphs
> ```

