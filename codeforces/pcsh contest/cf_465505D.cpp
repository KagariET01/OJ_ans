/*
[q]https://codeforces.com/group/VEc3guEDmO/contest/465505/problem/D
[55/100]
[SubTask1 AC 15/15]
[SubTask2 AC 15/15]
[SubTask3 AC 25/25]
[SubTask4 WA 0/45]
*/
//#ifndef eval
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}
 
INT allu[]={19,23,29,41,43,47,53,59,61,67,83,89};
INT canu[]={13*31,17*71,37*73,79*97};
INT addcanu[8]={
			13,31,
			17,71,
			37,73,
			79,97
		};
vector<INT> vec;
int main(int argc,char** argv){
	for(int i=0;i<argc;i++){
		string nwstr=argv[i];
		if(nwstr=="-Dev"){
			debug=1;
			noTLE=0;
		}else if(nwstr=="-TLE"){
			noTLE=0;
		}
	}
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	DBG{
		cout<<"Temp by KagariET01"<<endl;
		cout<<"My Webpage: https://kagariet01.github.io/about"<<endl;
		cout<<"===DBG mod on==="<<endl;
		cout<<"Here's your CFG"<<endl;
		for(int i=0;i<argc;i++){
			string nwstr=argv[i];
			cout<<'['<<nwstr<<']'<<endl;
		}
		cout<<"===Code start==="<<endl;
	}
	INT t=read(int);
	while(t--){
		INT k=read(INT);
		INT ans=1;
		bool canub[4]={0,0,0,0};
		vec.clear();
		for(INT i=0;i<4;i++){
			if(!(k%(canu[i]))){
				while(!(k%(canu[i]))){
					k/=canu[i];
					canub[i]=1;
				}
			}else{
				vec.push_back(addcanu[i*2]);
				vec.push_back(addcanu[i*2+1]);
				DBG cerr<<"asdf"<<i<<endl;
			}
		}
		DBG cerr<<k<<endl;
		for(INT i=0;i<20-8;i++){
			
			if(!(k%(allu[i]))){
				ans=0;
				break;
			}
		}
		for(INT i:vec){
			if(!(k%i)){
				ans=0;break;
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
//#endif
