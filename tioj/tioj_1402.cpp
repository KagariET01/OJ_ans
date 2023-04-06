/*
[Q]
[]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define PIII pair<INT,pair<INT,INT>>
INT mx[4]={0,1,0,-1};
INT my[4]={1,0,-1,0};


int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT n,m;
	while(cin>>n>>m){
		INT mp[n][m];
		bool runmp[n][m];
		priority_queue<PIII,vector<PIII>,greater<PIII>> que;
		for(INT i=0;i<n;i++){
			for(INT j=0;j<m;j++){
				cin>>mp[i][j];
				runmp[i][j]=false;
				if(i==0 || j==0 || i==n-1 || j==m-1){
					que.push({mp[i][j],{i,j}});
					runmp[i][j]=1;
				}
			}
		}
		INT ans=0;
		while(!que.empty()){
			PIII nw=que.top();
			que.pop();
			INT nh=nw.first;
			INT x=nw.second.first;
			INT y=nw.second.second;
			for(INT i=0;i<4;i++){
				INT nx=x+mx[i];
				INT ny=y+my[i];
				if(0<=nx && nx<n && 0<=ny && ny<m && !runmp[nx][ny]){//如果那邊沒有跑過，且未出格，就跑過去
					if(mp[nx][ny]<nh){//如果該高度比現在低(可以加水
						ans+=nh-mp[nx][ny];
						mp[nx][ny]=nh;
					}
					que.push({mp[nx][ny],{nx,ny}});
					runmp[nx][ny]=1;
				}else continue;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}