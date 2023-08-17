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
#define PII pair<INT,INT>
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}

bool vser(PII a,PII b){
	INT aa=a.second-a.first;
	INT bb=b.second-b.first;
	if(aa!=bb)return aa<bb;
	else return a.first<b.first;
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
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
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
	INT t=read(int);
	while(t--){
		INT n;
		cin>>n;
		PII lr[n];
		for(INT i=0;i<n;i++){
			lr[i]={read(INT),read(INT)};
		}
		sort(lr,lr+n,vser);
		DBG{
			for(INT i=0;i<n;i++){
				cerr<<"i:"<<i<<" lr[i]:{"<<lr[i].first<<","<<lr[i].second<<"}"<<endl;
			}
		}
		INT ans=0;
		bool cho[n]={};
		vector<PII> vec;
		for(INT i=0;i<n;i++){
			DBG cerr<<"nwi="<<i<<endl;
			if(cho[i])continue;
			bool ck=0;
			for(PII j:vec){
				INT mxl=max(lr[i].first,j.first);
				INT mnr=min(lr[i].second,j.second);
				if(mxl<=mnr){
					ck=1;
					ans++;
					break;
				}
			}
			if(ck)continue;
			bool nwc=0;
			INT j=i+1;
			for(j=0;j<n;j++){
				if(i==j)continue;
				if(cho[j])continue;
				if(lr[i].second<lr[j].first){
					continue;
				}
				bool ck=0;
				for(PII k:vec){
					INT mxl=max(lr[j].first,k.first);
					INT mnr=min(lr[j].second,k.second);
					DBG cerr<<"k:{"<<k.first<<","<<k.second<<"}"<<endl;
					if(mxl<=mnr){
						ck=1;
						break;
					}
				}
				if(ck)continue;
				INT lin=max(lr[i].first,lr[j].first);
				INT rin=min(lr[i].second,lr[j].second);
				if(lin<=rin){
					cho[i]=cho[j]=1;
					nwc=1;
					break;
				}
			}
			DBG{
				cerr<<"i:{"<<lr[i].first<<","<<lr[i].second<<"}";
				cerr<<" j:{"<<lr[j].first<<","<<lr[j].second<<"}"<<endl;
				cerr<<"ans="<<ans<<endl;
			}
			if(!nwc)ans++;
			else{
				INT mnl=min(lr[i].first,lr[j].first);
				INT mxr=max(lr[i].second,lr[j].second);
				vec.push_back({mnl,mxr});
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
