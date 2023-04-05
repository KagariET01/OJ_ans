/*
[Q]https://zerojudge.tw/ShowProblem?problemid=f314
APCS 2020-10-3
[AC]
*/

/*include*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
#define INT long long int
#define UINT unsigned long long int

const UINT maxm=50;
const UINT maxn=1e4;
INT ma[maxm+5][maxn+5];
INT dp[maxm+5][maxn+5];
INT n,m;
INT nowline[maxn+5];
INT goright[maxn+5];
INT goleft[maxn+5];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin>>m>>n;
	for(INT i=1;i<=m;i++){
		for(INT j=1;j<=n;j++){
			cin>>ma[i][j];
		}
	}

	INT ans=0;
	for(INT i=1;i<=m;i++){
		//go down
		for(int j=1;j<=n;j++){
				nowline[j]=dp[i-1][j]+ma[i][j];
		}
		//go right
		for(int j=1;j<=n;j++){
			goright[j]=max(nowline[j],goright[j-1]+ma[i][j]);
		}
		//go left
		for(int j=n;j>=0;j--){
			goleft[j]=max(nowline[j],goleft[j+1]+ma[i][j]);
		}
		//find ans
		//將答案加入dp
		for(int j=1;j<=n;j++){
			dp[i][j]=max(nowline[j],max(goright[j],goleft[j]));
		}
		//清空
		for(int j=1;j<=n;j++){
			nowline[j]=goright[j]=goleft[j]=0;
		}
	}
	//尋找答案
	for(int j=1;j<=n;j++){
		ans=max(ans,dp[m][j]);
	}

	cout<<ans;
	return 0;
}

