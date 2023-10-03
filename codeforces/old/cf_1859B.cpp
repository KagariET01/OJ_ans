/*
[q]
[]
*/
//#ifndef eval
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
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
		INT n;cin>>n;
		INT lst[n][3]={};
		for(INT i=0;i<n;i++){
			for(INT j=0;j<3;j++){
				lst[i][j]=1e9+7;
			}
		}
		INT ans=0;
		for(INT i=0;i<n;i++){
			INT m=read(INT);
			for(INT j=0;j<m;j++){
				cin>>lst[i][2];
				if(lst[i][1]>lst[i][2]){
					swap(lst[i][1],lst[i][2]);
				}
				if(lst[i][0]>lst[i][1]){
					swap(lst[i][0],lst[i][1]);
				}
			}
		}
		INT mn1=1e9+7;
		for(INT j=0;j<n;j++){
			mn1=min(mn1,lst[j][0]);
		}
		ans+=mn1;
		INT mn2=1e9+7;
		for(INT i=0;i<n;i++){
			mn2=min(mn2,lst[i][1]);
			ans+=lst[i][1];
		}
		cout<<ans+-mn2<<endl;
	}
	return 0;
}
//#endif
