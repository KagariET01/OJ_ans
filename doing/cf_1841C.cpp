/*
[q]https://kagariet01.github.io/swap/?OJ=cf&C=1841&P=C
[WA]
*/
//#ifndef eval
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
bool debug=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}
INT swaper[]={1,10,100,1000,10000};
string str;
INT strs;
INT getV(){
	INT re=0;
	INT xx=1;
	for(INT i=strs-1;i>=0;i--){
		if(i==strs-1){
			re=swaper[str[i]-'A'];
		}else{
			if(str[i]<str[i+1]){xx=-1;}
			else if(str[i]>str[i+1]){xx=1;}
			re+=swaper[str[i]-'A']*xx;
		}
	}
	return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	while(t--){
		cin>>str;
		strs=str.size();
		INT ans=-1e9;
		for(INT i=4;i>=0;i--){
			INT cnt=5;
			for(INT j=strs-1;j>=0 && cnt;j--){
				char nwc=str[j];
				if(str[j]-'A'==i){
					cnt--;
					for(INT l=0;l<5;l++){
						str[j]='A'+l;
						ans=max(ans,getV());
					}
				}
				str[j]=nwc;
				DBG cerr<<"DBG "<<str<<endl;
			}
			cnt=5;
			for(INT j=0;j<strs && cnt;j++){
				char nwc=str[j];
				if(str[j]-'A'==i){
					cnt--;
					for(INT l=0;l<5;l++){
						str[j]='A'+l;
						ans=max(ans,getV());
					}
				}
				str[j]=nwc;
				DBG cerr<<"DBG "<<str<<endl;
			}

		}
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
