/*
[q]
[TLE]
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
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

const INT mxn=1e5;
INT n;
INT lst[mxn+5];
INT BIT[mxn+1];
INT low_bit(INT x){
	return x&(-x);
}

INT getsum(INT x){//求1~x的值
	INT re=0;
	while(x>0){
		re+=BIT[x];
		x-=low_bit(x);
	}
	return re;
}

void update(INT x){//單點加1
	while(x<=n){
		BIT[x]+=1;
		x+=low_bit(x);
	}
}

vector<PII> flst;

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	while(t--){
		INT m;
		cin>>n>>m;
		flst.clear();memset(lst,0,sizeof(lst));memset(BIT,0,sizeof(BIT));
		for(INT i=0;i<m;i++){
			flst.push_back({read(INT),read(INT)});
		}
		INT q=read(INT);
		INT ans=0;
		for(INT i=1;i<=q;i++){
			INT inin=read(INT);
			if(ans)continue;
			if(lst[inin])continue;
			lst[inin]=1;
			update(inin);
			for(PII j:flst){
				INT l=j.first,r=j.second;
				INT len=r-l+1;
				INT tt=getsum(r)-getsum(l-1);
				INT ott=len-tt;
				if(tt>ott){
					ans=i;
					break;
				}
			}
		}
		if(!ans)ans=-1;
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
/*
[I1]
6
5 5
1 2
4 5
1 5
1 3
2 4
5
5
3
1
2
4
4 2
1 1
4 4
2
2
3
5 2
1 5
1 5
4
2
1
3
4
5 2
1 5
1 3
5
4
1
2
3
5
5 5
1 5
1 5
1 5
1 5
1 4
3
1
4
3
3 2
2 2
1 3
3
2
3
1
*/
