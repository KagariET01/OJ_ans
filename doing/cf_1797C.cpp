/*
[Q]
[]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT n,m;
		cin>>n>>m;
		PII q1,q2,q3;
		INT q1a,q2a,q3a;

		q1={(n+1)/2,(m+1)/2};
		cout<<"? "<<q1.first<<" "<<q1.second<<endl;
		cin>>q1a;
		if(q1a==0){
			cout<<"! "<<q1.first<<" "<<q1.second<<endl;
			continue;
		}

		q2={q1.first+q1a,q1.second+q1a};
		cout<<"? "<<q2.first<<" "<<q2.second<<endl;
		cin>>q2a;
		if(q2a==0){
			cout<<"! "<<q1.first<<" "<<q1.second<<endl;
			continue;
		}
	}
	return 0;
}