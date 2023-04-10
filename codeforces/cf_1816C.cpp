/*

[Q]

[]

*/

#include<bits/stdc++.h>

using namespace std;

#define INT long long int

#define endl "\n"

int main(){

	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);	INT t;cin>>t;

	while(t--){

		INT n;cin>>n;

		INT a[n];

		INT b[n];

		for(INT i=0;i<n;i++){cin>>a[i];b[i]=a[i];}

		if(n%2){//可以證明n是奇數時一定有解

			cout<<"Yes"<<endl;

			continue;

		}else if(n==2){

			if(a[0]>a[1]){

				cout<<"no"<<endl;

				continue;

			}else{

				cout<<"yes"<<endl;

				continue;

			}

		}else{

			for(INT i=2;i<n;i+=2){

				if(a[i-2]==a[i-1])continue;//    -

				if(a[i-2]<a[i-1]){//     /

					a[i]-=(a[i-1]-a[i-2]);

				}else{//     

					a[i]+=(a[i-2]-a[i-1]);

				}

			}

			if(a[n-2]>a[n-1]){

				cout<<"no"<<endl;

				continue;

			}else{

				cout<<"yes"<<endl;

				continue;

			}

		}

	}

	return 0;

}
