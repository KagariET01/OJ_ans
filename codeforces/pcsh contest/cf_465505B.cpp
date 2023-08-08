/*
[q]https://codeforces.com/group/VEc3guEDmO/contest/465505/problem/B
[water]
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
		string str=read(string);INT n=str.size();vector<INT> vec;for(INT i=0;i<n-2;i++){if(str[i]=='s' && str[i+1]=='t' && str[i+2]=='o' && str[i+3]=='r' && str[i+4]=='z'){vec.push_back(0);i+=4;}else if(str[i]=='o' && str[i+1]=='r' && str[i+2]=='z'){vec.push_back(-1);i+=2;}else if(str[i]=='s' && str[i+1]=='t' && str[i+2]=='o'){vec.push_back(1);i+=2;}}
		n=vec.size();INT ans=0;for(INT i=0;i<n;i++){if(vec[i]==-1){ans+=i;}else if(vec[i]==0){ans+=max(i,n-1-i);}else{ans+=n-1-i;}}cout<<ans<<endl;
	}
	return 0;
}
//#endif
