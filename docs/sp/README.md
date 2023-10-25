<link id="style_css" rel="stylesheet" type="text/css" href="/OJ_ans/style.css">

[`back`](../)


# `PCSH Mid-2023-01` PCSH Midterm Exam Contest #007
> ## [`PCSH Mid-2023-01 PD`]<br>好想跟鄭國手一樣強(User333 Orz)
> [`PCSH Mid-2023-01 PD`]: https://codeforces.com/group/VEc3guEDmO/contest/477514/problem/D
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
> const INT mxn=500000;
> function<
> 	void(
> 		vector<INT>::iterator,
> 		vector<INT>::iterator,
> 		INT*
> 	)
> > mrgesort;
> int main(int argc,char** argv){
> 	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
> 
> 	function<int(INT)> solve=[](INT casenum){
> 		INT n;
> 		if(!(cin>>n))return -1;
> 		vector<INT> lst;
> 		lst.reserve(n);
> 		INT ans=0;
> 		for(INT i=0;i<n;i++){
> 			lst.push_back(read(INT));
> 		}
> 		mrgesort=[](
> 			vector<INT>::iterator l,
> 			vector<INT>::iterator r,
> 			INT *ans
> 		){
> 			DBG{
> 				for(INT i=0;i<(r-l);i++){
> 					cout<<*(l+i)<<" ";
> 				}
> 				cout<<endl;
> 			}
> 			if(l==r)return;
> 			if(r-l<=1)return;
> 			vector<INT> vec;
> 			vec.reserve(r-l);
> 			INT ltt=0;
> 			INT lpt=0;
> 			vector<INT>::iterator mnt=(r-l)/2+l;
> 			mrgesort(l,mnt,ans);
> 			mrgesort(mnt,r,ans);
> 			for(vector<INT>::iterator it=l;it<mnt;it++){
> 				ltt+=*it;
> 				lpt+=(*it)*(*it);
> 			}
> 			vector<INT>::iterator lit=l;
> 			for(vector<INT>::iterator rit=mnt;rit<r;rit++){
> 				while(lit<mnt && *lit<=*rit){
> 					ltt-=*lit;
> 					lpt-=(*lit)*(*lit);
> 					vec.push_back(*lit);
> 					lit++;
> 				}
> 				*ans+=(mnt-lit)*(*rit)*(*rit)+2*(*rit)*ltt+lpt;
> 				vec.push_back(*rit);
> 			}
> 			while(lit<mnt){
> 				vec.push_back(*lit);
> 				lit++;
> 			}
> 			vector<INT>::iterator it=l;
> 			for(INT i:vec){
> 				*l=i;
> 				l++;
> 			}
> 			DBG{
> 				cout<<"to==>";
> 				for(INT i:vec){
> 					cout<<" "<<i;
> 				}
> 				cout<<" Ans="<<*ans<<endl;
> 			}
> 		};
> 		mrgesort(lst.begin(),lst.end(),&ans);
> 		cout<<ans<<endl;
> 		return 0;
> 	};
> 	bool one_case=1;
> 	bool ynans=0;
> 	bool eof=1;
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


# `Meta 2023-1` Meta Hacker Cup 2023 Round 1

> ## `Meta 2023-1 PB1`<br>Sum 41 (Chapter 1)
>
> ### [`OUTPUT`](./Meta_2023-1_PB1_output)
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
>
> ### `Tag`
>
> ```txt
> 家庭暴力防治法
> ```
