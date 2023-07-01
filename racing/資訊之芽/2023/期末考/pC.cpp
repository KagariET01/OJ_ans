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



struct seg_tree{
	vector<INT> origdta;
	vector<INT> tre;
	vector<INT> land_tre;
	INT sz=0;
	INT mrge(INT a,INT b){
		
	}
	
	INT btn_re

	void init(INT n){
		origdta.resize(n+1);
		tre.resize(n*4+4);
		land_tre.resize(n*4+4);
	}

}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=1;
	while(t--){
		INT n,q;
		cin>>n>>q;

	}
	return 0;
}
//#endif
