/*
[q]https://codeforces.com/group/VEc3guEDmO/contest/465505/problem/E
[36/100]
[SubTask1 AC 11/11]
[SubTask2 WA,TLE 0/17]
[SubTask3 AC 25/25]
[SubTask4 WA 0/21]
[SubTask% 0/26]
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
	INT t=1;
	while(t--){
		INT n,m;
		cin>>n>>m;
		INT a[n];
		for(INT i=0;i<n;i++){
			a[i]=read(INT);
		}
		INT al=1<<n;
		INT ans=0;
		for(INT i=0;i<al;i++){
			INT nwans=0;
			INT nw=i;
			for(INT j=0;j<n;j++){
				if(nw&1){
					nwans+=a[j];
					nwans%=m;
				}
				nw>>=1;
			}
			ans=max(ans,nwans);
		}
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
