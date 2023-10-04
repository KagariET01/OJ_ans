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
string clst="abcde";
INT mnk=1,mnn=1,mxn=5;
string wf="cf_1864B.in";

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
	ofstream F(wf);
	for(INT k=mnk;k<mxn;k++){
		for(INT n=max(k+1,mnn);n<mxn;n++){
			INT si[n];
			for(INT i=0;i<n;i++){
				si[i]=0;
			}
			bool running=1;
			while(running){
				cout<<n<<" "<<k<<endl;
				F<<n<<" "<<k<<endl;
				for(INT i=0;i<n;i++){
					cout<<clst[si[i]];
					F<<clst[si[i]];
				}
				cout<<endl;
				F<<endl;
				si[n-1]++;
				for(INT i=n-1;i>=0;i--){
					if(si[i]>=clst.size()){
						if(i==0){
							running=0;
							break;
						}
						si[i-1]+=si[i]/clst.size();
						si[i]%=clst.size();
					}
				}
			}
		}
	}
	F.close();
	return 0;
}
//#endif
