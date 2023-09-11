/*
[WA]
+[AC 000/000]
-[WA 000/004]
-[WA 000/027]
+[AC 013/013]
-[WA 000/024]
-[WA 000/032]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

struct superfloat{
	INT up;
	INT dn;
	void fix(){
		INT xx=__gcd(up,dn);
		up/=xx;
		dn/=xx;
	}
};
bool operator<(superfloat a,superfloat b){
	INT xx=__gcd(a.dn,b.dn);
	INT ax=b.dn/xx;
	INT bx=a.dn/xx;
	a.up*=ax;
	b.up*=bx;
	return ax<bx;
}

bool operator==(superfloat a,superfloat b){
	return a.up==b.up && a.dn==b.dn;
}

int main(int argc,char** argv){
	for(int i=0;i<argc;i++){
		string nwstr=argv[i];
		if(nwstr=="-Dev"){
			debug=1;
			noTLE=0;
		}else if(nwstr=="-TLE"){
			noTLE=0;
		}
	}
	if(noTLE && !debug){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
	DBG cerr<<"=====DBG mod====="<<endl;
	INT n=read(INT);
    INT lst[n];
	for(INT i=0;i<n;i++){
		cin>>lst[i];
	}
    sort(lst,lst+n);
	INT ans=0;
	INT xx=0;
	for(INT i=n-1;i>=0;i--){
		xx++;
		if(!(lst[i]==lst[i-1])){
			ans+=i*xx;
			xx=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}



