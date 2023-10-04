/*
[q]
[Topological sorting]
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
		INT n,k;
		cin>>n>>k;
		INT c[n];
		INT p[k];
		bool inque[n];memset(inque,0,sizeof(inque));
		deque<INT> dq;
		for(INT i=0;i<n;i++){
			cin>>c[i];
		}
		for(INT i=0;i<k;i++){
			cin>>p[i];
			p[i]--;
			c[p[i]]=0;
			dq.push_back(p[i]);
			inque[p[i]]=1;
		}
		vector<INT> vec[n];//可用來和甚麼
		vector<INT> mklist[n];//合成配方
		INT indo[n];//入度
		
		for(INT i=0;i<n;i++){
			cin>>indo[i];
			if(indo[i]){
				for(INT j=0;j<indo[i];j++){
					INT inin=read(INT);
					inin--;
					vec[inin].push_back(i);
					mklist[i].push_back(inin);
				}
			}else if(!inque[i]){
				dq.push_back(i);
				inque[i]=1;
			}
		}
		while(!dq.empty()){
			INT nw=dq.front();
			dq.pop_front();
			INT nwans=0;
			for(INT i:mklist[nw]){
				nwans+=c[i];
				if(nwans>c[nw])break;
			}
			if(mklist[nw].size()==0){
				nwans=c[nw];
			}
			c[nw]=min(c[nw],nwans);
			inque[nw]=1;
			DBG{
				cerr<<"run:"<<nw<<"  ";
				for(INT i=0;i<n;i++){
					cerr<<c[i]<<",";
				}
				cerr<<endl;
			}
			for(INT i:vec[nw]){
				indo[i]--;
				if(indo[i]==0){
					if(!inque[i]){
						dq.push_back(i);
						inque[i]=1;
					}
				}
			}
		}
		for(INT i=0;i<n;i++){
			if(i)cout<<" ";
			cout<<c[i];
		}
		cout<<endl;
	}
	return 0;
}
//#endif
