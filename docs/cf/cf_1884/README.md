<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `OJ CID` N

[`back`](../)

> ## `CF 1884 PA` Simple Design
>
> [`CF 1884 PA`]: https://codeforces.com/contest/1884/problem/A
>
> ### `C++`
>
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
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
>
> 	function<int(INT)> solve=[](INT casenum){
> 		INT n,k;
> 		cin>>n>>k;
> 		while(true){
> 			INT nw=0;
> 			INT nn=n;
> 			while(nn){
> 				nw+=nn%10;
> 				nn/=10;
> 			}
> 			if(nw%k==0){
> 				cout<<n<<endl;
> 				return 0;
> 			}
> 			n++;
> 		}
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

> ## `CF 1884 PB` Haunted House
>
> [`CF 1884 PB`]: https://codeforces.com/contest/1884/problem/B
>
> ### `C++`
>
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
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
>
> 	function<int(INT)> solve=[](INT casenum){
> 		INT n=read(INT);
> 		string str;
> 		cin>>str;
> 		reverse(str.begin(),str.end());
> 		//cout<<str<<endl;
> 		bool impos=0;
> 		INT nw1cnt=0;
> 		INT ans=0;
> 		INT r=0;
> 		for(INT i=0;i<n;i++,r++){
> 			if(i)cout<<" ";
> 			if(nw1cnt+i>=n)impos=1;
> 			if(impos){
> 				cout<<-1;
> 			}else{
> 				while(r<n && str[r]=='1'){
> 					nw1cnt++;
> 					r++;
> 				}
> 				if(r>=n){
> 					impos=1;
> 					cout<<-1;
> 				}else{
> 					ans+=nw1cnt;
> 					cout<<ans;
> 				}
> 			}
> 			//cout<<"str="<<str[r]<<endl;
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

> ## `CF 1884 PC` Medium Design
>
> [`CF 1884 PC`]: https://codeforces.com/contest/1884/problem/C
>
> ### `C++`
>
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
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
>
> 	function<int(INT)> solve=[](INT casenum){
> 		INT q,m;
> 		cin>>q>>m;
> 		function<bool(PII,PII)> vser=[](PII a,PII b){
> 			if(a.first!=b.first) return a.first<b.first;
> 			else return a.second>b.second;
> 		};
> 		vector<PII> vec1;
> 		vector<PII> vecm;
> 		while(q--){
> 			INT l,r;
> 			cin>>l>>r;
> 			r++;
> 			if(l!=1){
> 				vec1.push_back({l,1});
> 				vec1.push_back({r,-1});
> 			}
> 			if(r!=m+1){
> 				vecm.push_back({l,1});
> 				vecm.push_back({r,-1});
> 			}
> 		}
> 		sort(vec1.begin(),vec1.end());
> 		sort(vecm.begin(),vecm.end());
> 		INT lstn=1;
> 		INT mx=0;
> 		INT nw=0;
> 		for(PII i:vec1){
> 			//cout<<"nw={"<<i.first<<","<<i.second<<"}"<<endl;
> 			if(i.first!=lstn){
> 				mx=max(mx,nw);
> 			}
> 			lstn=i.first;
> 			nw+=i.second;
> 		}
> 		nw=0;
> 		lstn=1;
> 		//cout<<"=============="<<endl;
> 		for(PII i:vecm){
> 			//cout<<"nw={"<<i.first<<","<<i.second<<"}"<<endl;
> 			if(i.first!=lstn){
> 				mx=max(mx,nw);
> 			}
> 			lstn=i.first;
> 			nw+=i.second;
> 		}
> 		cout<<mx<<endl;
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

> ## [`CF 1884 PD`] Counting Rhyme
>
> [`CF 1884 PD`]: https://codeforces.com/contest/1884/problem/D
>
> ### `C++`
>
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
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
>
> 	function<int(INT)> solve=[](INT casenum){
> 		//cerr<<"Task "<<casenum<<" ==============="<<endl;
> 		INT n=read(INT);
> 		INT mp[n+1]={};
> 		bool se[n+1]={};
> 		for(INT i=0;i<n;i++){
> 			INT inin=read(INT);
> 			mp[inin]++;
> 			se[inin]=1;
> 			DBG cerr<<"Your Input="<<inin<<endl;
> 		}
> 		bool newse[n+1]={};
> 		//newse.reserve(n);
> 		for(INT i=1;i<=n;i++){
> 			if(se[i])
> 				for(INT j=i;j<=n;j+=i)
> 					newse[j]=1;
> 		}
> 		DBG{
> 			cerr<<"newse=";
> 			for(INT i:newse){
> 				cerr<<" "<<i;
> 			}
> 			cerr<<endl;
> 		}
> 		INT dp[n+1]={};
> 		INT ans=0;
> 		DBG cerr<<"run start"<<endl;
>
> 		for(INT i=n;i>=1;i--){
> 			DBG cerr<<"i="<<i<<endl;
> 			dp[i]=0;
> 			INT j=i;
> 			while(j<=n){
> 				dp[i]+=mp[j];
> 				j+=i;
> 			}
> 			dp[i]=(dp[i]-1)*dp[i]/2;
> 			for(INT j=i+i;j<=n;j+=i){
> 				dp[i]-=dp[j];
> 			}
> 			ans+=dp[i];
> 		}
> 		DBG cerr<<"finish"<<endl;
> 		DBG for(INT i=1;i<=n;i++){
> 			cerr<<dp[i]<<" ";
> 		}
> 		for(INT i=1;i<=n;i++){
> 			if(newse[i])
> 				ans-=dp[i];
> 		}
> 		DBG cerr<<"cout ans"<<endl;
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
>
> ### `Tag`
>
> ```txt
> 基本輸出輸入
> String
> math 數學
> 觀察
> sort
> bit運算
> greedy
> 想法
> DP
> 模擬constructive algorithms
> Binary Search
> graphs
> 家庭暴力防治法
> trie 字典數
> ```
