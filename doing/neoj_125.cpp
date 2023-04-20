/*
[Q]https://neoj.sprout.tw/problem/125/
[WA][RE]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT unsigned long long int
#define endl "\n"
#define DBG if(debug)

vector<INT> vec;
vector<INT> vecadd;

bool debug=0;
INT mod=10000019;

INT re=0;

void solve(INT l,INT r){
	DBG cerr<<"l="<<l<<" r="<<r<<endl;
	if(r-l<=1)return;
	INT mnt=(l+r)/2;//l區的右界(不包含)，r區的左界(包含)
	/*
	re+=solve(l,mnt);
	re%=mod;
	re+=solve(mnt,r);
	re%=mod;
	*/

	INT lit=l,rit=mnt,ind=0,temp[r-l];
	//nl=左指標,nr=右指標,ind=目前temp的.endl(),temp為排序後的list
	for(;lit<mnt;lit++){//move lit
		while(rit<r && vec[rit]<vec[lit]){
			INT tme=mnt-lit;//除了自己之外，l區裡面比自己大的(在自己右邊的)都要算
			re+=vecadd[mnt-1]-vecadd[lit-1];//每次+逆序數對，都要加自己一次
			re%=mod;
			re+=vec[rit]*tme%mod;
			re%=mod;
			temp[ind]=vec[rit];
			ind++;
			rit++;
		}
		temp[ind]=vec[lit];
		ind++;
	}
	while(rit<r){
		temp[ind]=vec[rit];
		rit++;
		ind++;
	}

	for(int i=0;i<r-l;i++){
		vec[i+l]=temp[i];
	}
	re%=mod;
	//return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT n;
	cin>>n;
	INT rt=1;
	while(rt--){
		vec.resize(n+1);
		vecadd.resize(n+1);
		vecadd[0]=0;
		for(INT i=1;i<=n;i++){
			cin>>vec[i];
			vecadd[i]=vecadd[i-1]+vec[i];//前綴和
		}
		solve(1,n+1);
		cout<<re%mod<<endl;
	}
	return 0;
}

/*
參考資料
https://peienwu.com/sprout6-1/


這很明顯是分治題
~~因為這堂課上分治
*/