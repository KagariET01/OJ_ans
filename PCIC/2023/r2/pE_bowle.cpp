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
	INT t=1;
	while(t--){
		INT n;
		cin>>n;
		INT lst[n];
		for(INT i=0;i<n;i++){
			cin>>lst[i];
		}
		bool filp=0;
		INT q;
		cin>>q;
		while(q--){
			INT ask;
			cin>>ask;
			if(ask==1){
				INT cpy[n];
                for(INT i=0;i<n;i++){
                    cpy[i]=lst[i];
                }
				for(INT i=0;i<n;i++){
					lst[i]=cpy[n-i-1];
				}
			}
			else if(ask==2){
				INT cpy[n];
                for(INT i=0;i<n;i++){
                    cpy[i]=lst[i];
                }
				for(INT i=0;i<n;i++){
					lst[i]=n-cpy[i]+1;
				}
			}
			else{
				INT cpy[n];
                for(INT i=0;i<n;i++){
                    cpy[i]=lst[i];
                }
				for(INT i=0;i<n;i++){
					lst[cpy[i]-1]=i+1;
				}
			}
			DBG{
				for(INT i=0;i<n;i++){
					if(i)cerr<<" ";
					cerr<<lst[i];
				}
				cerr<<endl;
			}
		}
		for(INT i=0;i<n;i++){
			if(i)cout<<" ";
			cout<<lst[i];
		}
		cout<<endl;
	}
	return 0;
}


/*
3 3 1 2 2 1 3
> 2 1 3
5 1 2 3 4 5 4 1 2 3 1
> 5 4 3 2 1
15 8 6 9 1 5 13 3 7 15 10 12 14 11 4 2 10 2 1 3 2 3 1 3 2 1 2
> 12 1 9 2 11 14 8 15 13 6 3 5 10 4 7
*/
