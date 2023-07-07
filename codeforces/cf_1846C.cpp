/*
[q]https://codeforces.com/contest/1846/problem/C
[AC]
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
#define PIII pair<INT,pair<INT,INT>>

struct dta{
	INT id=0;
	INT ac=0;
	INT pen=0;
};

bool vser(dta a,dta b){
	if(a.ac != b.ac){
		return a.ac>b.ac;
	}else if(a.pen != b.pen){
		return a.pen<b.pen;
	}else{
		return a.id<b.id;
	}
	
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t=read(int);
	DBG cerr<<"t="<<t<<endl;
	while(t--){
		INT n,m,h;
		cin>>n>>m>>h;
		DBG cerr<<n<<" "<<m<<" "<<h<<endl;

		vector< dta > rk;
		rk.reserve(n);
		for(INT i=0;i<n;i++){
			vector<INT> alst;
			alst.reserve(m);
			for(INT j=0;j<m;j++){
				alst.push_back(read(INT));
			}
			sort(alst.begin(),alst.end());
			INT nwh=h;
			INT pttime=0;
			dta nw;
			nw.id=i+1;
			for(INT j:alst){
				if((nwh-j)<0)break;
				nw.ac++;
				nwh-=j;
				pttime+=j;
				nw.pen+=pttime;
			}
			rk.push_back(nw);
		}
		DBG{
			for(dta i:rk){
				cerr<<"id:"<<i.id<<" ac:"<<i.ac<<" pen:"<<i.pen<<endl;
			}
		}
		sort(rk.begin(),rk.end(),vser);
		INT ans=1;
		for(dta i:rk){
			if(i.id==1)break;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
/*
5
3 3 120
20 15 110
90 90 100
40 40 40

2 1 120
30
30

1 3 120
10 20 30

3 2 27
8 9
10 7
10 8

3 3 15
7 2 6
7 5 4
1 9 8

*/