# `Meta 2023-1` Meta Hacker Cup 2023 Round 1

> ## `Meta 2023-1 PB1`<br>Sum 41 (Chapter 1)
> ### `OUTPUT`
> [`output`](./Meta_2023-1_PB1_output)
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
> INT mod=998244353;
> 
> deque<INT> ans;
> 
> bool getans(INT p,INT mx=41){
> 	DBG cout<<"p="<<p<<" mx="<<mx<<endl;
> 	if(p==1){
> 		for(INT i=0;i<mx;i++){
> 			ans.push_back(1);
> 		}
> 		return 1;
> 	}
> 	for(INT i=mx;i>=2;i--){
> 		if(p%i)continue;
> 		else{
> 			ans.push_back(i);
> 			if(getans(p/i,mx-i))return 1;
> 			ans.pop_back();
> 		}
> 	}
> 	return 0;
> }
> 
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 	auto solve=[](INT casenum){
> 		cout<<"Case #"<<casenum+1<<": ";
> 		ans.clear();
> 		INT p=read(INT);
> 		DBG cerr<<"running"<<endl;
> 		if(getans(p)){
> 			cout<<ans.size();
> 			for(INT i:ans){
> 				cout<<" "<<i;
> 			}
> 			cout<<endl;
> 		}else{
> 			cout<<"-1"<<endl;
> 		}
> 		return 0;
> 	};
> 	bool one_case=0;
> 	bool ynans=0;
> 	bool eof=0;
> 	string yes="yes";
> 	string no="no";
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
> ### `Tag`
> ```txt
> Bowle 暴力
> ```