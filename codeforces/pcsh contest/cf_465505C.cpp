/*
[q]https://codeforces.com/group/VEc3guEDmO/contest/465505/problem/C
[(雙)指標]
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
	INT t=1;
	while(t--){
		INT n,q;
		cin>>n>>q;
		vector<INT> vec[n+5];
		char c[q+5]={};
		c[0]='0';
		c[q+2]='\n';
		priority_queue<INT> dq;
		dq.push(0);
		char ans[n+5]={};
		bool open[q+5]={};
		open[0]=1;
		memset(ans,'0',sizeof(ans));
		ans[n]='\0';
		for(INT i=1;i<=q;i++){
			INT l,r;
			cin>>l>>r>>c[i];
			l--;r--;
			vec[r].push_back(-i);
			vec[l].push_back(i);
		}
		for(INT i=0;i<n;i++){
			for(INT j:vec[i]){
				if(j>0){
					dq.push(j);
					open[j]=1;
					DBG cerr<<"push "<<j<<endl;
				}/*else{
					open[-j]=0;
				}*/
			}
			DBG{
				cerr<<"add "<<dq.top()<<endl;;
			}
			if(dq.empty())continue;
			ans[i]=c[dq.top()];
			for(INT j:vec[i]){
				if(j<0){
					open[-j]=0;
				}
			}
			while(!dq.empty() && !open[dq.top()]){
				DBG cerr<<"pop "<<dq.top()<<endl;
				dq.pop();
			}
			DBG cerr<<endl;
		}
		DBG cerr<<dq.top()<<endl;
		DBG cerr<<"c="<<c<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
