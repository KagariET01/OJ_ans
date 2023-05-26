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
	int t=1;
	string a,b;
	INT k;
	while(cin>>a>>b>>k){
		DBG cerr<<"get DTA"<<endl;
		if(a=="exit")break;
		INT toto[k];
		INT tot_tot=0;
		memset(toto,0,sizeof(toto));
		INT i=0;
		INT sz_a=a.size();
		INT sz_b=b.size();
		INT n=max(sz_a,sz_b);
		INT zerocount=0;
		INT aircount=0;
		for(;i<n;i++){
			INT tot=(a[i]-'0')+(b[i]-'0')+tot_tot;
			if(toto[i%k])aircount--;
			tot_tot-=toto[i%k];
			INT outnum=tot%10;
			if(outnum==0){zerocount++;}
			else{
				if(zerocount)while(zerocount--){
				cout<<"0";
				}
				cout<<outnum;
			}
			tot/=10;
			tot%=10;
			toto[i%k]=tot;
			tot_tot+=tot;
			if(toto[i%k])aircount++;
		}
		while(aircount){
			i%=k;
			INT tot=tot_tot;
			tot_tot-=toto[i%k];
			if(tot==0){
				aircount--;
				i++;
				continue;
			}
			INT outnum=tot%10;
			if(outnum==0){zerocount++;}
			else{
				if(zerocount)while(zerocount--){
					cout<<"0";
				}
				cout<<outnum;
			}
			tot/=10;
			tot%=10;
			toto[i%k]=tot;
			tot_tot+=tot;
			if(toto[i%k])aircount++;
			i++;
		}
		cout<<endl;
	}
	return 0;
}
//#endif

/*
[I1]
456 987 1
456 987 2
456 987 3
[O1]
3441
34521
345321
*/