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

struct trie{
	trie* c[26];
	INT cnt;
	trie(): cnt(0){
		memset(c,0,sizeof(c));
	}
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	int t=read(int);
	while(t--){
	}
	return 0;
}
