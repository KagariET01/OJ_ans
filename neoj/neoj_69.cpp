/*
[Q]https://neoj.sprout.tw/problem/69/
*/
#include<iostream>
#include<algorithm>
using namespace std;
#define INT long long int

INT a[10000],b[10000],c[10000],ab[10000];
INT k,n;
//a為自己馬的速度,b為成長值,c為對手馬的速度,ab為自己馬+成長值的速度

bool WL(INT t){
	INT it=0,w=0;//it為目前配對的敵人編號,w為目前勝場數
	for(INT i=0;i<n;i++){
		ab[i]=a[i]+b[i]*t;
	}
	sort(ab,ab+n);
	for(INT i=0;i<n;i++){
		if(ab[i]>c[it]){
			w++;
			it++;
			if(w>=k)return true;
		}
	}
	return (w>=k);
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT r=100000000,l=0;
		cin>>n>>k;
		for(INT i=0;i<n;i++){
			cin>>a[i]>>b[i];
		}
		for(INT i=0;i<n;i++){
			cin>>c[i];
		}
		sort(c,c+n);
		if(!WL(r)){
			cout<<-1<<endl;
			continue;
		}else if(WL(0)){
			cout<<0<<endl;
			continue;
		}else{
			while(l<r){
				INT mid=(r+l)/2;
				if(WL(mid)){
					r=mid;
				}else{
					l=mid+1;
				}
			}
		}
		cout<<r<<endl;
	}
	return 0;
}
/*
[I1]
1
3 2
1 2
2 1
3 2
0
3
4
[O1]
1
[I2]
1
1 1
1 0
2
[O2]
-1

[I3]
2 3 2 1 2 2 1 3 2 0 3 4 1 1 1 0 2
[O3]
1
-1
*/
/*
log(100000000)*NlogN
*/