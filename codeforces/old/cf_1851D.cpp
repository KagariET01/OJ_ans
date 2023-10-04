/*
[q]
[想法]
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
		INT n;
		cin>>n;
		INT a[n+1];
		a[0]=0;
		INT ntt=n;
		for(INT i=1;i<n;i++){
			cin>>a[i];
			ntt+=i;
		}
		a[n]=ntt;
		if(a[n-1]>ntt){
			cout<<"no"<<endl;
			continue;
		}
		INT b[n];
		for(INT i=0;i<n;i++){
			b[i]=a[i+1]-a[i];
		}
		//sort(b,b+n-1);
		DBG{
			for(INT i=0;i<n;i++){
				cout<<b[i]<<" ";
			}
			cout<<endl;
		}
		bool ans=1;
		bool c[n+1];memset(c,0,sizeof(c));
		vector<INT> lost;
		vector<INT> more;
		for(INT i=0;i<n;i++){
			if(b[i]==0)continue;
			if(b[i]>n || c[b[i]]){
				more.push_back(b[i]);
			}else{
				c[b[i]]=1;
			}
		}
		for(INT i=1;i<=n;i++){
			if(!c[i])lost.push_back(i);
		}
		INT lostall=0;
		for(INT i:lost){
			lostall+=i;
			DBG cerr<<"lost:"<<i<<endl;
		}
		INT moreall=0;
		for(INT i:more){
			moreall+=i;
			DBG cerr<<"more:"<<i<<endl;
		}
		if(more.size()>1)ans=0;
		if(lostall!=moreall)ans=0;
		

		

		if(ans){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
	}
	return 0;
}
//#endif
