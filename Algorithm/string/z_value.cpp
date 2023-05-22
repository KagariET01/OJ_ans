/*
[q]
[]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define dbg if(debug)
bool debug=0;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

vector<INT> z_value(string s){
	INT n=s.size();
	INT l=0,r=0;
	vector<INT> z(n);
	for(INT i=1;i<n;i++){
		if(i<=r){
			z[i]=min(z[i-l],r-i+1);
		}
		while(
			i+z[i]<n &&
			s[z[i]]==s[i+z[i]]
		)z[i]++;
		if(i+z[i]-1>r){
			l=i,r=z[i]+i-1;
		}
	}
	return z;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	int t=read(int);
	while(t--){
		string str=read(string);
		vector<INT> z=z_value(str);
		for(INT i:z){
			cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}
