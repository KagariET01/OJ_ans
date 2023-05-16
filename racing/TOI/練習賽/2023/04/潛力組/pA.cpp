/*
[AC]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
bool debug=0;
template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}

const INT mxn=1e4;
vector<INT> tre[mxn+5];
short flag[mxn+5];
INT nwf[3]={0,0,0};
INT allf[3]={0,0,0};
//INT nwr=0,nwb=0,allr=0,allb=0;
bool sol=1;

void solve(INT n,short f){
	if(!flag[n]){
		nwf[f]++;
	}
	flag[n]=f;
	for(INT i:tre[n]){
		if(flag[i]){
			if(flag[i]==flag[n]){
				sol=0;
				return;
			}
		}else{
			solve(i,3-f);
		}
	}
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=1;
	while(t--){
		for(INT i=0;i<mxn+5;i++){
			tre[i].clear();
		}
		nwf[0]=0;
		nwf[1]=0;
		nwf[2]=0;
		allf[0]=0;
		allf[1]=0;
		allf[2]=0;
		memset(flag,0,sizeof(flag));
		sol=1;

		INT n,m;cin>>n>>m;
		for(INT i=0;i<m;i++){
			INT a,b;cin>>a>>b;
			tre[a].push_back(b);
			tre[b].push_back(a);
		}

		for(INT i=1;i<=n;i++){
			if(!flag[i]){
				solve(i,1);
			}
			if(!sol)break;
			else{
				allf[1]+=max(nwf[1],nwf[2]);
				allf[2]+=min(nwf[1],nwf[2]);
				nwf[0]=0;
				nwf[1]=0;
				nwf[2]=0;
			}
		}

		if(!sol){
			cout<<0<<endl;
		}else{
			cout<<allf[1]<<endl;
		}
	}
	return 0;
}