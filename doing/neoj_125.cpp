/*
[Q]https://neoj.sprout.tw/problem/125/
[MLE]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT unsigned int
#define endl "\n"

INT ans=0;
vector<INT> vec;
bool debug=1;

template<typename TPE>INT solve(TPE a,TPE b){
	if(a==b)return 0;
	else{
		TPE mnt=a+(b-a)/2;
		INT re=0;
		re+=solve(a,mnt+1);
		re+=solve(mnt,b);

		vector<INT> nwvec;
		TPE l=a,r=mnt+1;
		while(l!=mnt+1 && r!=b){
			if(*l>*r){
				re+=*l+*r;
				nwvec.push_back(*r);
				r++;
			}else{
				nwvec.push_back(*l);
				l++;
			}
		}
		while(l!=mnt+1){
			nwvec.push_back(*l);
			l++;
		}
		while(r!=b){
			nwvec.push_back(*r);
			r++;
		}

		TPE it=a;
		for(INT i:nwvec){
			*a=i;
			a++;
		}
		return re;
	}
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT n;
	while(cin>>n){
		vec.resize(n);
		for(INT i=0;i<n;i++){
			cin>>vec[i];
		}
		cout<<solve(vec.begin(),vec.end());

	}
	return 0;
}