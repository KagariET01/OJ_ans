/*
[q]
[]
*/
//#ifndef eval
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
bool debug=0;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT n,m,k,x,y;
	cin>>n>>m>>k>>x>>y;
	cout<<m*2*x+n*y<<endl;
	return 0;
}
//#endif
