/*
[q]
[TLE]
[矩陣乘法]
[hash]
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

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=1;
	while(t--){
	    INT n,m,k;cin>>n>>m>>k;
	    INT a[n][m];
	    INT b[m][k];
	    INT c[n][k];
	    for(INT i=0;i<n;i++){
		for(INT j=0;j<m;j++){
		    cin>>a[i][j];
		}
	    }
	    for(INT i=0;i<m;i++){
		for(INT j=0;j<k;j++){
		    cin>>b[i][j];
		}
	    }

	    /*for(INT i=0;i<n;i++){
		for(INT j=0;j<k;j++){
		    for(INT fk=0;fk<m;fk++){
			if(fk==0)
			    c[i][j]=0;
			c[i][j]+=a[i][fk]*a[fk][j];
		    }
		}
	    }*/

	    string ans="Yes";
	    bool bans=1;
	    for(INT i=0;i<n && bans;i++){
		for(INT j=0;j<k && bans;j++){
		    for(INT fk=0;fk<m;fk++){
			if(fk==0)
			    c[i][j]=0;
			c[i][j]+=a[i][fk]*b[fk][j];
		    }
		    DBG cerr<<"axb="<<c[i][j]<<endl;
		    if(read(INT)!=c[i][j]){
			ans="No";
			bans=0;
			break;
		    }   
		}
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
//#endif
