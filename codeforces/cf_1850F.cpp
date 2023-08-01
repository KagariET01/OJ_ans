/*
[q]
[AC]
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
	INT t=read(int);
	while(t--){
		INT n=read(INT);
		INT a[n+1];//有a[i]隻青蛙一次跳i單位
		memset(a,0,sizeof(a));
		for(INT i=0;i<n;i++){
			INT inin=read(INT);
			if(inin<=n)a[inin]++;
		}
		INT ans=0;
		for(INT i=1;i<=n;i++){//枚舉陷阱的位置
			vector<INT> vec;//i的因數表
			for(INT j=1;j<=i;j++){
				if(j>i/j)break;
				if(i%j)continue;
				vec.push_back(j);
				if(j!=i/j){
					vec.push_back(i/j);
				}
			}
			INT nw=0;
			for(INT j:vec){
				nw+=a[j];
			}
			/*
				陷阱擺在i
				所有跳躍長度為[i的因數]都會被抓到
			*/
			ans=max(ans,nw);
		}
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
