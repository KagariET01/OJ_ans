/*
[q]
[模擬]
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

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	while(t--){
		INT n,k;
		cin>>n>>k;
		INT clen[k+1][2];memset(clen,0,sizeof(clen));
		INT lastc[k+1];memset(lastc,0,sizeof(lastc));
		for(INT i=1;i<=n;i++){
			INT nwc=read(INT);
			INT nwlen=i-lastc[nwc]-1;
			lastc[nwc]=i;

			if(clen[nwc][1]<nwlen){
				clen[nwc][0]=clen[nwc][1];
				clen[nwc][1]=nwlen;
			}else if(clen[nwc][0]<nwlen){
				clen[nwc][0]=nwlen;
			}
		}
		INT i=n+1;
		for(INT nwc=0;nwc<=k;nwc++){
			INT nwlen=i-lastc[nwc]-1;
			lastc[nwc]=i;

			if(clen[nwc][1]<nwlen){
				clen[nwc][0]=clen[nwc][1];
				clen[nwc][1]=nwlen;
			}else if(clen[nwc][0]<nwlen){
				clen[nwc][0]=nwlen;
			}
		}
		INT ans=n;
		for(INT nwc=0;nwc<=k;nwc++){
			ans=min(
				ans,
				max(clen[nwc][0],clen[nwc][1]/2)
			);
		}
		cout<<ans<<endl;
		
	}
	return 0;
}
//#endif
