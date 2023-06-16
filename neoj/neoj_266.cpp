/*
[q]https://neoj.sprout.tw/problem/266/
[AC]
[String]
[Trie]
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

INT c_i(char c){
    return c-'a';
}

struct tre{
    INT v=0;
    tre *nxt[30];
    void reset(){
	for(INT i=0;i<30;i++){
	    nxt[i]=NULL;
	}
    }
};


void insert(string str,tre *root){
    for(char c:str){
	if(c==0)break;
	if(root->nxt[c_i(c)]==NULL){
	    root->nxt[c_i(c)]=new(tre);
	    root->nxt[c_i(c)]->reset();
	}
	root=root->nxt[c_i(c)];
    }
    root->v++;
}
INT find(string str,tre *root){
    for(char c:str){
	if(c==0)break;
	if(root->nxt[c_i(c)]==NULL){
	    return 0;
	}
	root=root->nxt[c_i(c)];
    }
    return root->v;

}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=1;
	while(t--){
	   INT n,m;cin>>n>>m;
	   tre *root;
	   root=new(tre);
	   root->reset();
	   while(n--){
		insert(read(string),root);
	   }
	   while(m--){
		cout<<find(read(string),root)<<endl;;
	   }
	}
	return 0;
}
//#endif
