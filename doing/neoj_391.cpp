/*
[q]
[]
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
	INT t=read(int);
	while(t--){
		INT N,M,S,E,F;
		/*
		N=城市數
		M=運輸方案
		S=工廠位置
		E=目的地
		F=購買數量
		*/
		cin>>N>>M>>S>>E>>F;
		INT mp[N+5][N+5];//do 最短路
		for(INT i=0;i<=N;i++){
			for(INT j=0;j<=N;j++){
				mp[i][j]=1e9;
			}
		}
		DBG cerr<<mp[1][1]<<endl;
		for(INT i=0;i<M;i++){
			INT A,B,C,D,C2;
			cin>>A>>B>>C>>D>>C2;
			INT V=min(F,D)*C+max((INT)0,F-D)*C2;
			mp[A][B]=V;
		}
		for(INT k=1;k<=N;k++){
			for(INT i=1;i<=N;i++){
				for(INT j=1;j<=N;j++){
					mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);	
				}
			}
		}
		cout<<mp[S][E]<<endl;
	}
	return 0;
}
//#endif

/*
[I1]
3

4 4 1 4 1
1 2 1 1 1
2 4 5 1 3
1 3 1 1 1
3 4 6 1 1

4 4 1 4 2
1 2 1 1 1
2 4 5 1 3
1 3 1 1 1
3 4 6 1 1

2 1 1 2 999999999
1 2 50216 1000 50216

[O1]
6
9
50215999949784
*/
