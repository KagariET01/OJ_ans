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
		INT a[n];
		INT mx=0,mn=0;
		INT mxid=0,mnid=0;
		INT bgc=0,sml=0;
		for(INT i=0;i<n;i++){
			cin>>a[i];
			if(a[i]>mx){
				mxid=i;
				mx=a[i];
			}else if(a[i]<mn){
				mnid=i;
				mn=a[i];
			}
			mx=max(mx,a[i]);
			mn=min(mn,a[i]);
			if(a[i]>0)bgc++;
			else if(a[i]<0)sml++;
		}
		if(mx==0){//全部已是負數
			cout<<n-1<<endl;
			for(INT i=n-2;i>=0;i--){
				cout<<i+1<<" "<<i+2<<endl;
			}
		}else if(mn==0){//全部已是正數
			cout<<n-1<<endl;
			for(INT i=0;i<n-1;i++){
				cout<<i+2<<" "<<i+1<<endl;
			}
		}else{
			mn=-mn;
			INT lans=sml;
			INT ltst=mx;
			while(ltst && ltst<mn){
				DBG cerr<<"now ltst="<<ltst<<endl;
				lans++;
				ltst+=ltst;
			}
			if(ltst==0)lans=1000;
			INT rans=bgc;
			INT rtst=mn;
			while(rtst && rtst<mx){
				DBG cerr<<"now rtst="<<rtst<<endl;
				rans++;
				rtst+=rtst;
			}
			if(rtst==0)rans=1000;
			DBG{
				cerr<<"lans="<<lans<<" ltst="<<ltst<<" rans="<<rans<<" rtst="<<rtst<<endl;
				cerr<<"mx="<<mx<<" bgc="<<bgc<<" mn="<<mn<<" sml="<<sml<<endl;
			}
			if(lans<rans){//做全正數，前綴和
				cout<<n-1+lans<<endl;
				INT ltst=mx;
				while(ltst<mn){
					ltst+=ltst;
					cout<<mxid+1<<" "<<mxid+1<<endl;
				}
				for(INT i=0;i<n;i++){
					if(a[i]<0){
						cout<<i+1<<" "<<mxid+1<<endl;
					}
				}
				for(INT i=0;i<n-1;i++){
					cout<<i+2<<" "<<i+1<<endl;
				}
			}else{//做全負數，後墜河
				cout<<n-1+rans<<endl;
				INT rtst=mn;
				while(rtst<mx){
					rtst+=rtst;
					cout<<mnid+1<<" "<<mnid+1<<endl;
				}
				for(INT i=0;i<n;i++){
					if(a[i]>0){
						cout<<i+1<<" "<<mnid+1<<endl;
					}
				}
				for(INT i=n-2;i>=0;i--){
					cout<<i+1<<" "<<i+2<<endl;
				}
			}
		}
		

	}
	return 0;
}
//#endif
