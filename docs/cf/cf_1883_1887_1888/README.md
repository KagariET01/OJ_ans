<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 1883` `CF 1887` `CF 1888`<br>Codeforces Round 905 (Div. 1, Div. 2, Div. 3)

[`back`](../)
[`CF 1883`](https://codeforces.com/contest/1883)
[`CF 1887`](https://codeforces.com/contest/1887)
[`CF 1888`](https://codeforces.com/contest/1888)

> ## [`CF 1883 PA`]<br>Morning
> ### `C++`
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
> 	function<int(INT)> solve=[](INT casenum){
> 		string str=read(string);
> 		INT ans=4;
> 		INT nw=1;
> 		for(INT i=0;i<4;i++){
> 			if(str[i]-'0'==nw)continue;
> 			if(nw==0){
> 				if(str[i]=='0')continue;
> 				ans+=10-(str[i]-'0');
> 			}else if(str[i]=='0'){
> 				ans+=10-nw;
> 			}else{
> 				ans+=abs(nw-(str[i]-'0'));
> 			}
> 			nw=str[i]-'0';
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

> ## [`CF 1883 PB`] [`CF 1888 PA`]<br>Chemistry
> ### `C++`
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
> 		map<char,INT> mp;
> 		string str=read(string);
> 		for(char c:str){
> 			mp[c]++;
> 		}
> 		INT oddcount=0;
> 		for(pair<char,INT> i:mp){
> 			if(i.second&1)oddcount++;
> 		}
> 		oddcount--;
> 		if(k>=oddcount){
> 			return 1;
> 		}
> 		return 0;
> 	};
> 	bool one_case=0;
> 	bool ynans=1;
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

> ## [`CF 1883 PC`] [`CF 1888 PB`]<br>Raspberries
> ### `C++`
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
> 		if(k==4){
> 			INT cnt[4]={};
> 			for(INT i=0;i<n;i++){
> 				cnt[read(INT)%4]++;
> 			}
> 			if(cnt[2]>=2 || cnt[0]>=1){
> 				cout<<0<<endl;
> 				return 0;
> 			}else if(cnt[3] || (cnt[1] && cnt[2])){
> 				cout<<1<<endl;
> 			}else if(cnt[1]>=2 || cnt[2]){
> 				cout<<2<<endl;
> 			}else{
> 				cout<<3<<endl;
> 			}
> 		}else{
> 			INT ans=10;
> 			for(INT i=0;i<n;i++){
> 				INT inin=read(INT)%k;
> 				ans=min(ans,k-inin);
> 				if(inin==0)ans=0;
> 			}
> 			cout<<ans<<endl;
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

> ## [`CF 1883 PD`]<br>In Love
> ### `C++`
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
> 		struct mncmp{
> 			bool operator()(PII a,PII b){
> 				return a.second>b.second;
> 			}
> 		};
> 		struct mxcmp{
> 			bool operator()(PII a,PII b){
> 				return a.first<b.first;
> 			}
> 		};
> 		
> 
> 		INT q=read(INT);
> 		DBG cerr<<"q="<<q<<endl;
> 		map<PII,INT> del_mx;
> 		map<PII,INT> del_mn;
> 		priority_queue<PII,vector<PII>,mncmp> mn;
> 		priority_queue<PII,vector<PII>,mxcmp> mx;
> 		while(q--){
> 			char c=read(char);
> 			INT l,r;
> 			cin>>l>>r;
> 			if(c=='+'){
> 				//DBG cerr<<"add "<<l<<" "<<r<<endl;
> 				mn.push({l,r});
> 				mx.push({l,r});
> 			}else{
> 				//DBG cerr<<"del "<<l<<" "<<r<<endl;
> 				del_mx[{l,r}]++;
> 				del_mn[{l,r}]++;
> 			}
> 			while(del_mn[mn.top()]){
> 				del_mn[mn.top()]--;
> 				mn.pop();
> 			}
> 			while(del_mx[mx.top()]){
> 				del_mx[mx.top()]--;
> 				mx.pop();
> 			}
> 			if(mn.empty()){
> 				cout<<"NO"<<endl;
> 				continue;
> 			}
> 			PII mnpi=mn.top();
> 			PII mxpi=mx.top();
> 			DBG cerr<<"mnpi={"<<mnpi.first<<","<<mnpi.second<<"}"<<endl;
> 			DBG cerr<<"mxpi={"<<mxpi.first<<","<<mxpi.second<<"}"<<endl;
> 			if(mxpi.first<=mnpi.second){
> 				cout<<"NO"<<endl;
> 			}else{
> 				cout<<"YES"<<endl;
> 			}
> 		}
> 		return 0;
> 	};
> 	bool one_case=1;
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





[`CF 1883 PA`]: https://codeforces.com/contest/1883/problem/A
[`CF 1883 PB`]: https://codeforces.com/contest/1883/problem/B
[`CF 1883 PC`]: https://codeforces.com/contest/1883/problem/C
[`CF 1883 PD`]: https://codeforces.com/contest/1883/problem/D

[`CF 1888 PA`]: https://codeforces.com/contest/1888/problem/A
[`CF 1888 PB`]: https://codeforces.com/contest/1888/problem/B