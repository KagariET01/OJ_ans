/*
[Q]https://neoj.sprout.tw/problem/789/
[AC]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT unsigned int
#define endl "\n"
#define DBG if(debug)

bool debug=0;

INT n;
vector<INT> vec;

void solve(INT l,INT r){
	if(r==l)return;
	{
		INT lst[r-l+1];
		INT it=0;
		for(INT i=l;i<=r;i+=2){
			lst[it]=vec[i];
			it++;
		}
		for(INT i=l+1;i<=r;i+=2){
			lst[it]=vec[i];
			it++;
		}
		for(INT i=0;i<=r-l;i++){
			vec[i+l]=lst[i];
		}
		DBG{
			for(INT i=0;i<n;i++){
				if(i)cout<<" ";
				cout<<vec[i];
			}
			cout<<endl;
		}
	}
	INT mnt=(l+r)/2;
	solve(l,mnt);
	solve(mnt+1,r);
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	while(cin>>n){
		vec.resize(n);
		for(INT i=0;i<n;i++){
			vec[i]=i+1;
		}
		solve(0,n-1);
		for(INT i=0;i<n;i++){
			if(i)cout<<" ";
			cout<<vec[i];
		}
		cout<<endl;
	}
	return 0;
}