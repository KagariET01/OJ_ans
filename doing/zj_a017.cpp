/*
[q]https://kagariet01.github.io/swap/?OJ=zj&P=a017
[math][遞迴]
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

string str;
INT i=0;
INT n=0;
INT solve(bool st=true){
	if(st){
		i=0;
		n=str.size();
	}
	INT nw=0;//先乘除
	INT re=0;//後加減
	INT num=0;//目前取到的數
	char bef='+';
	while(i<n){
		//DBG cerr<<"i:"<<i<<" ";
		char c=str[i];
		if(c==' '){
			i++;continue;
		}
		else if('0'<=c && c<='9'){
			num*=10;
			num+=c-'0';
			DBG cerr<<"i:"<<i<<" c="<<c<<" num:"<<num<<endl;
		}else if(c=='('){
			i++;
			num=solve(false);
		}else{
			if(bef=='+'){
				re+=nw;
				nw=num;
				num=0;
			}else if(bef=='-'){
				re+=nw;
				nw=-num;
				num=0;
			}else if(bef=='*'){
				nw*=num;
				num=0;
			}else if(bef == '/'){
				nw/=num;
				num=0;
			}
			DBG cerr<<"i:"<<i<<" c="<<c<<" nw:"<<nw<<" re:"<<re<<endl;

			if(c=='e' || c==')'){
				re+=nw;
				return re;
			}else{
				bef=c;
			}
		}
		i++;
	}
	return re;
}


int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	while(getline(cin,str)){
		str+="e";
		DBG cerr<<str<<endl;
		cout<<solve()<<endl;
	}
	return 0;
}
//#endif
