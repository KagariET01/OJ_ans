/*
[q]
[HACK][WA]
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
	INT t=1;
	while(t--){
		string str;
		cin>>str;
		INT nw=0;
		INT n=str.size();
		for(INT i=0;i<n;i++){
			for(INT j=i+1;j<n;j++){
				if(str[i]=='1' && str[j]=='0')nw++;
				else if(str[i]=='0' && str[j]=='1')nw--;
			}
		}
		INT ans=0;
		while(nw){
			DBG cerr<<"nw="<<nw<<endl;
			PII doit={0,0};
			INT ch=nw;
			for(INT i=0;i<n;i++){
				for(INT j=i+1;j<n;j++){
					if(str[i]==str[j])continue;
					INT ad=0;
					if(str[i]=='1'){
						ad=-1;
					}else{
						ad=1;
					}
					ad*=j-i;
					ad*=2;
					INT nwc=nw+ad;
					if(abs(nwc)<abs(ch)){
						ch=nwc;
						doit={i,j};
					}
				}
			}
			swap(str[doit.first],str[doit.second]);
			nw=ch;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//#endif

/*
	一個10就+1
	一個01就-1
*/
