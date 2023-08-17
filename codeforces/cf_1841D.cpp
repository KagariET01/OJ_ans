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
	if(a.second!=b.second)return a.second<b.second;
	else return a.first>b.first;
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
			cin>>lr[i].first>>lr[i].second;
		}
		vector<PII> vec;
		for(INT i=0;i<n;i++){
			for(INT j=i+1;j<n;j++){
				INT ll=max(lr[i].first,lr[j].first);
				INT rr=min(lr[i].second,lr[j].second);
				if(ll<=rr){
					vec.push_back({
						min(lr[i].first,lr[j].first),
						max(lr[i].second,lr[j].second)
					});
				}
			}
		}
		sort(vec.begin(),vec.end(),vser);
		INT ans=n;
		INT mxr=-1;
		for(PII i:vec){
			if(mxr<i.first){
				ans-=2;
				mxr=i.second;
			}
			if(ans<=1)break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//#endif
