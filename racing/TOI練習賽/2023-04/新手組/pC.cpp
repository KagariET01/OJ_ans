/*
[Q]
[]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()

const INT mxk=10000;
INT lst[mxk+1];

template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT n,s,f;
	cin>>n>>s>>f;
	INT counter=0;
	for(INT i=0;i<n;i++){
		INT inin=read(INT);
		if(lst[inin]){
			lst[inin]=0;
			continue;
		}
		counter++;
		lst[inin]=1;
		if(f==inin)s-=2;
		if(s<=0)break;
	}
	cout<<counter<<endl;
	return 0;
}