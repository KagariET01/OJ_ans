/*
[Q]https://neoj.sprout.tw/problem/125/
[WA][RE]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT unsigned int
#define endl "\n"

vector<INT> vec;
bool debug=1;
const INT mod=10000019;

INT solve(INT l,INT r){
	if(l==r)return 0;
	INT mnt=l+(r-l)/2;
	INT re=0;
	re+=solve(l,mnt);
	re=re%10000019;
	re+=solve(mnt+1,r);
	re=re%10000019;
	INT lst[r-l+1];
	INT nwit=0,lit=l,rit=mnt+1;
	INT rtt=0;
	for(INT i=l;i<=mnt;i++){
		while(rit<=r && lst[rit]<lst[i]){
			rtt+=lst[rit];
			rit++;
		}
		re+=rtt;
		re=re%10000019;
		re+=lst[i]*(rit-(mnt+1));
		re=re%10000019;
	}





	rit=mnt+1;
	//sort
	while(lit<=mnt && rit<=r){
		if(vec[lit]>vec[rit]){
			lst[nwit]=vec[rit];
			nwit++;
			rit++;
		}else{
			lst[nwit]=vec[lit];
			nwit++;
			lit++;
		}
	}
	while(rit<=r){
		lst[nwit]=vec[rit];
		nwit++;
		rit++;
	}
	while(lit<=mnt){
		re+=vec[lit]+rtt;
		lst[nwit]=vec[lit];
		nwit++;
		lit++;
	}

	nwit=0;
	for(INT i=l;i<=r;i++,nwit++){
		vec[i]=lst[nwit];
	}


	return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT n;
	while(cin>>n){
		vec.resize(n);
		for(INT i=0;i<n;i++){
			cin>>vec[i];
		}
		cout<<solve(0,n-1);
	}
	return 0;
}