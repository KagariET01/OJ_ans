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
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}
const INT mxn=2e5;
INT xx[mxn+5];
vector<INT> oddlst;
void oddbuild(INT n){
	oddlst.clear();memset(xx,0,sizeof(xx));
	oddlst.push_back(2);
	xx[4]=2;
	for(INT i=3;i<=n;i++){
		if(xx[i]==0){
			oddlst.push_back(i);
		}
		for(INT j:oddlst){
			if(j*i>n)break;
			xx[j*i]=j;
			if(xx[i]==j)break;
		}
	}
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	oddbuild(100);
	/*DBG{
		for(INT i:oddlst){
			cerr<<i<<endl;
		}
	}*/
	while(t--){
		INT n;cin>>n;
		if(n==1){
			cout<<1<<endl;
			continue;
		}else if(n==2){
			cout<<"2 1"<<endl;
			continue;
		}else if(n==3){
			cout<<"2 1 3"<<endl;
			continue;
		}
		INT re[n];
		INT wc=0;
		bool nmw[n+1];memset(nmw,0,sizeof(nmw));
		memset(re,0,sizeof(re));
		re[(n-1)/2]=1;wc++;nmw[1]=1;
		re[0]=3;wc++;nmw[3]=1;
		re[n-1]=2;wc++;nmw[2]=1;

		INT i=1;
		INT j=4;
		for(;i<n;i++){
			if(re[i])continue;
			while(nmw[j]){
				j++;
			}
			re[i]=j;
			j++;
		}
		for(INT i=0;i<n;i++){if(i)cout<<" ";cout<<re[i];}
		cout<<endl;
	}
	return 0;
}
//#endif
