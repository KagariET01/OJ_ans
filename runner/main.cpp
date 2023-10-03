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

INT mod=998244353;

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
	DBG{
		cout<<"Temp by KagariET01"<<endl;
		cout<<"My Webpage: https://kagariet01.github.io/about"<<endl;
		cout<<"===DBG mod on==="<<endl;
		cout<<"Here's your CFG"<<endl;
		for(int i=0;i<argc;i++){
			string nwstr=argv[i];
			cout<<'['<<nwstr<<']'<<endl;
		}
		cout<<"===Code start==="<<endl;
	}
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

	auto solve=[](INT casenum){
		INT n,k;
		cin>>n>>k;
		DBG cout<<n<<" "<<k<<endl;
		INT l[k+1],r[k+1];
		bool cen[k+1];
		for(INT i=1;i<=k;i++){
			l[i]=k/2-(k%2==0?1:0);
			r[i]=k/2;
			cen[i]=0;
		}
		while(n--){
			INT inin=read(INT);
			INT nwbt=k/2+1,nwup=k/2+1;
			bool ans=0;
			while(true){
				if(0<nwbt){
					if(!cen[nwbt]){
						ans=1;
						cen[nwbt]=1;
						INT ansl=k/2-(inin/2)+1;
						INT ansr=k/2+((inin-1)/2)+1;
						l[nwbt]-=(inin/2);
						r[nwbt]-=((inin-1)/2);
						cout<<nwbt<<" "<<ansl<<" "<<ansr<<endl;
						break;
					}else if(l[nwbt]>=inin){
						ans=1;
						l[nwbt]-=inin;
						INT ansl=l[nwbt]+1;
						INT ansr=l[nwbt]+inin;
						cout<<nwbt<<" "<<ansl<<" "<<ansr<<endl;
						break;
					}else if(r[nwbt]>=inin){
						ans=1;
						r[nwbt]-=inin;
						INT ansr=k-r[nwbt];
						INT ansl=ansr-inin+1;
						cout<<nwbt<<" "<<ansl<<" "<<ansr<<endl;
						break;
					}
				}
				if(nwup<=k){
					if(!cen[nwup]){
						ans=1;
						cen[nwup]=1;
						INT ansl=k/2-(inin/2)+1;
						INT ansr=k/2+((inin-1)/2)+1;
						l[nwup]-=(inin/2);
						r[nwup]-=((inin-1)/2);
						cout<<nwup<<" "<<ansl<<" "<<ansr<<endl;
						break;
					}else if(l[nwup]>=inin){
						ans=1;
						l[nwup]-=inin;
						INT ansl=l[nwup]+1;
						INT ansr=l[nwup]+inin;
						cout<<nwup<<" "<<ansl<<" "<<ansr<<endl;
						break;
					}else if(r[nwup]>=inin){
						ans=1;
						r[nwup]-=inin;
						INT ansr=k-r[nwup];
						INT ansl=ansr-inin+1;
						cout<<nwup<<" "<<ansl<<" "<<ansr<<endl;
						break;
					}
				}
				nwbt--;
				nwup++;
				DBG cout<<"nwbt="<<nwbt<<" nwup="<<nwup<<" k="<<k<<endl;
				if(nwbt<=0 && k<nwup)break;
			}
			if(!ans){
				cout<<-1<<endl;
			}
		}
		return 0;
	};
	bool one_case=1;
	bool ynans=0;
	bool eof=0;
	string yes="yes";
	string no="no";
	INT t=(one_case?1:read(int));
	for(INT i=0;eof || i<t;i++){
		if(!ynans){
			if(solve(i)==-1)return 0;
		}else{
			if(solve(i)==1){
				cout<<yes<<endl;
			}else if(solve(i)==0){
				cout<<no<<endl;
			}else{
				return 0;
			}
		}
	}
	return 0;
}
