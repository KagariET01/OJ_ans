/*
[Q]
[]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
bool debug=0;
template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}

const INT mxn=2e5;
const INT mxxy=2e5;
INT n,s,t;
INT c[mxn+1];
INT x[mxn+1];
INT y[mxn+1];
INT step[mxn+1];

bool ans=0;

vector<INT> xrow[mxxy+1];//xrow[i]代表在x=i的那條線上有那些點(記錄點編號)
vector<INT> yrow[mxxy+1];
vector<INT> ul_rdrow[mxxy*2+1];
vector<INT> ur_ldrow[mxxy*2+1];

bool xvser(INT a,INT b){
	return x[a]<x[b];
}
bool yvser(INT a,INT b){
	return y[a]<y[b];
}
bool ulrdurld(INT a,INT b){
	return c[a]<c[b];
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=1;
	while(t--){
		cin>>n>>s>>t;

		for(INT i=0;i<n;i++){
			cin>>x[i]>>y[i]>>c[i];
			xrow[x[i]].push_back(i);
			yrow[y[i]].push_back(i);
			ul_rdrow[x[i]+y[i]].push_back(i);
			ur_ldrow[x[i]-y[i]+mxxy].push_back(i);
		}

		for(INT i=0;i<sizeof(xrow);i++)sort(xrow[i].begin(),xrow[i].end(),xvser);
		for(INT i=0;i<sizeof(yrow);i++)sort(yrow[i].begin(),yrow[i].end(),xvser);
		for(INT i=0;i<sizeof(ul_rdrow);i++)sort(ul_rdrow[i].begin(),ul_rdrow[i].end(),ulrdurld);
		for(INT i=0;i<sizeof(ur_ldrow);i++)sort(ur_ldrow[i].begin(),ur_ldrow[i].end(),ulrdurld);
		
		deque<INT> dq;//做bfs，紀錄點編號
		dq.push_back(s-1);
		while(!ans && !dq.empty()){
			INT nw=dq.front();
			dq.pop_front();
			
			//x
			vector<INT>::iterator xit=lower_bound(xrow[nw].begin(),xrow[nw].end(),);
			for(INT i:xrow[x[nw]]){
				if(step[i] || i==s)continue;//已經走過or這裡是開始之地
				step[i]=step[nw]+1;//走過去
				if(i==t){//如果該地為目的地
					ans=1;
					break;
				}
				dq.push_back(i);
			}
			if(ans)break;
			//y
			for(INT i:yrow[y[nw]]){
				if(step[i] || i==s)continue;//已經走過or這裡是開始之地
				step[i]=step[nw]+1;//走過去
				if(i==t){//如果該地為目的地
					ans=1;
					break;
				}
				dq.push_back(i);
			}
			//ul_rd

			if(ans)break;
			//ur_ld

			if(ans)break;
		}
	}
	return 0;
}