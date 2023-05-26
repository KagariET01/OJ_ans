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
#define dbg if(debug)
bool debug=0;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	int t=1;
	while(t--){
	    bool checker1=1;
	    bool checker2=1;
	    int n=read(int);
	    if(n%9==0 && 9<=n && n<=81){
		checker1=1;
	    }else{
		checker1=0;
	    }
	    string str;
	    char anss=0;
	    for(int i=9;i>=0;i--){
		str=read(string);
		if(i==9)anss=str[9];
		else if(i==0)continue;
		else{
		    if(anss!=str[i])checker2=0;
		}
	    }
	    if(read(char)!=anss){
		checker2=0;
	    }
	    if(checker1 && checker2){
		cout<<"AC"<<endl;
	    }else if(!checker1 && !checker2){
		cout<<"CE"<<endl;
	    }else if(checker1){
		cout<<"WA"<<endl;
	    }else{
		cout<<"RE"<<endl;
	    }
	}
	return 0;
}
//#endif
