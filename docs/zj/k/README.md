# `ZJ k___`

[`back`](../)

> ## `ZJ k465` `TOIP 2023-04-HARD PC`<br>姓名分析 (Name)
> ### `c++`
> ```c++
> #include<bits/stdc++.h>
> using namespace std;
> #define INT long long int
> #define endl "\n"
> #define read(n) reader<n>()
> #define DBG if(debug)
> bool debug=0;
> bool noTLE=1;
> template<typename tpe>tpe reader(){
> 	tpe re;cin>>re;return re;
> }
> 
> struct dta{
> 	INT cnt=0;
> 	bool hnx['Z'-'A'+1];
> 	dta *nxt['Z'-'A'+1];
> };
> 
> void ptre(dta *root,INT deep=1){
> 	cerr<<(*root).cnt<<endl;
> 	for(INT i=0;i<('Z'-'A'+1);i++){
> 		if((*root).hnx[i]){
> 			INT dpc=deep;
> 			while(dpc--){
> 				cerr<<"|";
> 			}
> 			cerr<<char(i+'A')<<" ";
> 			ptre((*root).nxt[i],deep+1);
> 		}
> 	}
> }
> string str[1000000];
> 
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 	INT t=1;
> 	while(t--){
> 		INT n=read(INT);
> 		dta root;
> 		memset(root.hnx,0,('Z'-'A'+1));
> 
> 		for(INT i=0;i<n;i++){
> 			str[i]=read(string);
> 		}
> 		//solve
> 		for(INT i=0;i<n;i++){
> 			dta *it;
> 			it=&root;
> 			for(char c:str[i]){
> 				(*it).cnt++;
> 				if(!((*it).hnx[c-'A'])){
> 					(*it).nxt[c-'A']=new dta;
> 					memset((*(*it).nxt[c-'A']).hnx,0,('Z'-'A'+1));
> 				}
> 				(*it).hnx[c-'A']=1;
> 				it=(*it).nxt[c-'A'];
> 			}
> 			(*it).cnt++;
> 		}
> 		//cout
> 		for(INT i=0;i<n;i++){
> 			dta *it;
> 			it=&root;
> 			INT ans=0;
> 			for(char c:str[i]){
> 				it=(*it).nxt[c-'A'];
> 				if((*it).cnt>1){
> 					ans+=(*it).cnt-1;
> 				}else{
> 					break;
> 				}
> 			}
> 			cout<<ans<<endl;
> 			DBG{
> 				ptre(&root);
> 				cerr<<endl;
> 			}
> 		}
> 	}
> 	return 0;
> }
> ```
> ### `Tag`  
> ```txt
> trie 字典數
> ```




<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">
