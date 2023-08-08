/*
[q]
[WA]
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
		INT a[n]={};
		for(INT i=0;i<n;i++){
			cin>>a[i];
		}
		INT ans=0;
		INT adda[n]={};
		for(INT i=n-1;i>=0;i--){
			if(i<n-1){
				INT mxadd=max((INT)0,min(a[i-1],a[i+1]+1)-a[i]);
				mxadd=min(k,mxadd);
				k-=mxadd;
				adda[i]=mxadd;
				a[i]+=mxadd;
			}

			INT j=i-1;

			for(j=i-1;j>=0;j--){
				INT mxadd=max((INT)0,((a[j+1]+1)-a[j]));
				k-=mxadd;
				if(k<0){
					k+=mxadd;
					break;
				}
				adda[j]=mxadd;
				a[j]+=mxadd;
			}
			DBG cerr<<"i:"<<i<<" a[j+1]:"<<a[j+1]<<endl;
			ans=max(ans,a[j+1]);
			for(j=j+1;j<n;j++){
				a[j]-=adda[j];
				k+=adda[j];
				adda[j]=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
