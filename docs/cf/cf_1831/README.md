<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 1831` Codeforces Round 875 (Div. 2)

[`back`](../)

> ## [`CF 1831 PA`] Twin Permutations
> [`CF 1831 PA`]: https://codeforces.com/contest/1831/problem/A
> ### `C++`
> ```c++
> #include<bits/stdc++.h>
> 
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
> const INT mxn=1e5;
> INT lca[mxn+1][30];
> INT n;
> vector<INT> tre[mxn];
> INT deep[mxn];
> 
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 
> 	function<int(INT)> solve=[](INT casenum){
> 		INT n=read(INT);
> 		for(INT i=0;i<n;i++){
> 			if(i)cout<<" ";
> 			cout<<(n-read(INT)+1);
> 		}
> 		cout<<endl;
> 		return 0;
> 	};
> 	bool one_case=0;
> 	bool ynans=0;
> 	bool eof=0;
> 	string yes="YES";
> 	string no="NO";
> 	INT t=(one_case?1:read(int));
> 	for(INT i=0;eof || i<t;i++){
> 		INT re=solve(i);
> 		if(!ynans){
> 			if(re==-1)return 0;
> 		}else{
> 			if(re==1){
> 				cout<<yes<<endl;
> 			}else if(re==0){
> 				cout<<no<<endl;
> 			}else{
> 				return 0;
> 			}
> 		}
> 	}
> 	return 0;
> }
> ```

> ## [`CF 1831 PB`] Array merging
> [`CF 1831 PB`]: https://codeforces.com/contest/1831/problem/B
> ### `C++`
> ```c++
> #include<bits/stdc++.h>
> 
> using namespace std;
> #define INT long long int
> #define endl "\n"
> #define read(n) reader<n>()
> #define DBG if(debug)
> #define PII pair<INT,INT>
> #define min(a,b) (a<b?a:b)
> #define max(a,b) (a>b?a:b)
> #define mins(a,b) a=min(a,b)
> #define maxs(a,b) a=max(a,b)
> bool debug=0;
> bool noTLE=1;
> template<typename tpe>tpe reader(){
> 	tpe re;cin>>re;return re;
> }
> 
> const INT mxn=1e5;
> INT lca[mxn+1][30];
> INT n;
> vector<INT> tre[mxn];
> INT deep[mxn];
> 
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 
> 	function<int(INT)> solve=[](INT casenum){
> 		INT n=read(INT);
> 		map<INT,INT> mpa;
> 		map<INT,INT> mpb;
> 		INT mx=0;
> 		INT nwnum=0;
> 		INT nwcnt=0;
> 		for(INT i=0;i<n;i++){
> 			INT inin=read(INT);
> 			maxs(mx,inin);
> 			if(nwnum==inin){
> 				nwcnt++;
> 			}else{
> 				nwnum=inin;
> 				nwcnt=1;
> 			}
> 			maxs(mpa[inin],nwcnt);
> 		}
> 		nwnum=0;
> 		nwcnt=0;
> 		for(INT i=0;i<n;i++){
> 			INT inin=read(INT);
> 			maxs(mx,inin);
> 			if(nwnum==inin){
> 				nwcnt++;
> 			}else{
> 				nwnum=inin;
> 				nwcnt=1;
> 			}
> 			maxs(mpb[inin],nwcnt);
> 		}
> 		INT ans=0;
> 		for(INT i=0;i<=mx;i++){
> 			maxs(ans,mpa[i]+mpb[i]);
> 		}
> 		cout<<ans<<endl;
> 		return 0;
> 	};
> 	bool one_case=0;
> 	bool ynans=0;
> 	bool eof=0;
> 	string yes="YES";
> 	string no="NO";
> 	INT t=(one_case?1:read(int));
> 	for(INT i=0;eof || i<t;i++){
> 		INT re=solve(i);
> 		if(!ynans){
> 			if(re==-1)return 0;
> 		}else{
> 			if(re==1){
> 				cout<<yes<<endl;
> 			}else if(re==0){
> 				cout<<no<<endl;
> 			}else{
> 				return 0;
> 			}
> 		}
> 	}
> 	return 0;
> }
> ```

> ## [`CF 1831 PC`] Copil Copac Draws Trees
> [`CF 1831 PC`]: https://codeforces.com/contest/1831/problem/C
> ### `C++`
> ```c++
> #include<bits/stdc++.h>
> 
> using namespace std;
> #define INT long long int
> #define endl "\n"
> #define read(n) reader<n>()
> #define DBG if(debug)
> #define PII pair<INT,INT>
> #define min(a,b) (a<b?a:b)
> #define max(a,b) (a>b?a:b)
> #define mins(a,b) a=min(a,b)
> #define maxs(a,b) a=max(a,b)
> bool debug=0;
> bool noTLE=1;
> template<typename tpe>tpe reader(){
> 	tpe re;cin>>re;return re;
> }
> 
> const INT mxn=1e5;
> INT lca[mxn+1][30];
> INT n;
> vector<INT> tre[mxn];
> INT deep[mxn];
> 
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 
> 	function<int(INT)> solve=[](INT casenum){
> 		INT n=read(INT);
> 		vector<PII> tre[n+1];
> 		for(INT i=1;i<n;i++){
> 			INT a,b;
> 			cin>>a>>b;
> 			tre[a].push_back({b,i});
> 			tre[b].push_back({a,i});
> 		}
> 		struct dta{
> 			INT nw=0;//now node id
> 			INT lst=0;//last node id
> 			INT cnt=0;//redo count
> 			INT lid=0;//line id
> 			string operator()(){
> 				string re="";
> 				re+='{';
> 				re+=to_string(nw);
> 				re+=',';
> 				re+=to_string(lst);
> 				re+=',';
> 				re+=to_string(cnt);
> 				re+=',';
> 				re+=to_string(lid);
> 				re+='}';
> 				return re;
> 			}
> 		};
> 		deque<dta> que;
> 		que.push_back({1,-1,1,0});//node id,line id
> 		INT ans=1;
> 		bool hve[n+1]={};
> 		hve[1]=1;
> 		while(!que.empty()){
> 			dta i=que.front();
> 			que.pop_front();
> 
> 			//cout<<i()<<endl;
> 			maxs(ans,i.cnt);
> 			for(PII j:tre[i.nw]){
> 				if(hve[j.first])continue;
> 				if(j.first==i.lst)continue;
> 				//cout<<i.nw<<" to "<<j.first<<endl;
> 
> 				if(j.second<i.lid){
> 					dta ad={j.first,i.nw,i.cnt+1,j.second};
> 					//cout<<ad()<<endl;
> 					que.push_back(ad);
> 					hve[j.first]=1;
> 					continue;
> 				}else{
> 					dta ad={j.first,i.nw,i.cnt,j.second};
> 					//cout<<ad()<<endl;
> 					que.push_back(ad);
> 					hve[j.first]=1;
> 					continue;
> 				}
> 
> 			}
> 
> 		}
> 		cout<<ans<<endl;
> 		return 0;
> 	};
> 	bool one_case=0;
> 	bool ynans=0;
> 	bool eof=0;
> 	string yes="YES";
> 	string no="NO";
> 	INT t=(one_case?1:read(int));
> 	for(INT i=0;eof || i<t;i++){
> 		INT re=solve(i);
> 		if(!ynans){
> 			if(re==-1)return 0;
> 		}else{
> 			if(re==1){
> 				cout<<yes<<endl;
> 			}else if(re==0){
> 				cout<<no<<endl;
> 			}else{
> 				return 0;
> 			}
> 		}
> 	}
> 	return 0;
> }
> ```

