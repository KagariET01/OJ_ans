/*
[Q]
[]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()

template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT n=read(INT);
	INT ch[n+1];
	INT mh[n+1];
	for(INT i=1;i<=n;i++){
		cin>>ch[i];
	}
	for(INT i=1;i<=n;i++){
		cin>>mh[i];
	}
	bool dnthve=1;
	for(INT i=1;i<=n;i++){
		if(ch[i]>mh[i]){
			if(!dnthve){
				cout<<" ";
			}
			dnthve=0;
			cout<<i;
		}
	}
	if(dnthve){
		cout<<-1;
	}
	cout<<endl;

	dnthve=1;
	for(INT i=1;i<=n;i++){
		if(ch[i]<mh[i]){
			if(!dnthve){
				cout<<" ";
			}
			dnthve=0;
			cout<<i;
		}
	}
	if(dnthve){
		cout<<-1;
	}
	cout<<endl;
	return 0;
}