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
		string l,r;
		cin>>l>>r;
		INT ans=0;
		if(l.size()!=r.size()){
			INT n=max(l.size(),r.size())-1;
			ans+=n*9;
			if(l.size()>r.size()){
				ans+=l[0]-'0';
			}else{
				ans+=r[0]-'0';
			}
		}else{
			INT i=0;
			INT n=l.size();
			while(i<n && l[i]==r[i])i++;
			DBG cerr<<"i="<<i<<endl;
			if(i==n)ans=0;
			else{
				ans+=abs(l[i]-r[i]);
				ans+=9*(n-i-1);
			}
		}
		cout<<ans<<endl;
		
	}
	return 0;
}
//#endif
