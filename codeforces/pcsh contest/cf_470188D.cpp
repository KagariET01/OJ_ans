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
bool noTLE=0;
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
		INT n=read(INT);
		INT l=1,r=n;
		cout<<"? "<<l<<" "<<r<<endl;
		INT all=read(INT);
		while(r>l){
			if(l+1==r || (r-l+1)==all*2){
				cout<<"! "<<l<<" "<<r<<endl;
				break;
			}
			INT mnt=(r-l)/2+l;
			cout<<"? "<<l<<" "<<mnt<<endl;
			INT lcnt=read(INT);
			INT rcnt=all-lcnt;
			DBG{
				cerr<<"mnt-l+1="<<mnt-l+1<<" lcnt="<<lcnt<<" r-mnt="<<r-mnt<<" rcnt="<<rcnt<<endl;
			}
			if((lcnt==(mnt-l+1) && rcnt==0) || lcnt==0 && rcnt==(r-mnt)){
				cout<<"! "<<mnt<<" "<<mnt+1<<endl;
				break;
			}else{
				if(lcnt==(mnt-l+1) || lcnt==0){
					l=mnt+1;
					all=rcnt;
				}else if(rcnt==(r-mnt) || rcnt==0){
					r=mnt;
					all=lcnt;
				}else{
					INT lcc=abs((r-l)-lcnt*4);
					INT rcc=abs((r-l)-rcnt*4);
					if(lcc<rcc){
						l=mnt+1;
						all=rcnt;
					}else{
						r=mnt;
						all=lcnt;
					}
				}
			}
		}
	}
	return 0;
}
//#endif
