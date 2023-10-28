<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

# `CF 1800` Codeforces Round 855 (Div. 3)

[`back`](../)

> ## `CF 1800 PA` Is It a Cat?
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
> INT mod=998244353;
>
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 	auto solve=[](INT casenum){
> 		INT n;
> 		cin>>n;
> 		string str;
> 		cin>>str;
> 		INT step=0;
> 		for(char c:str){
> 			if(step==0){
> 				if(c=='m' || c=='M')step++;
> 				else return 0;
> 			}else if(step==1){
> 				if(c=='e' || c=='E')step++;
> 				else if(c!='m' && c!= 'M')return 0;
> 			}else if(step==2){
> 				if(c=='o' || c=='O')step++;
> 				else if(c!='e' && c!= 'E')return 0;
> 			}else if(step==3){
> 				if(c=='w' || c=='W')step++;
> 				else if(c!='o' && c!= 'O')return 0;
> 			}else{
> 				if(c!='w' && c!= 'W')return 0;
> 			}
> 		}
> 		return (step==4?1:0);
> 	};
> 	bool one_case=0;
> 	bool ynans=1;
> 	bool eof=0;
> 	debug=0;
> 	string yes="yes";
> 	string no="no";
> 	INT t=(one_case?1:read(int));
> 	for(INT i=0;eof || i<t;i++){
> 		INT re=solve(i);
> 		if(!ynans){
> 			if(re==-1 && eof)return 0;
> 		}else{
> 			if(re==1){
> 				cout<<yes<<endl;
> 			}else if(re==0){
> 				cout<<no<<endl;
> 			}else if(eof){
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
> String
> ```
