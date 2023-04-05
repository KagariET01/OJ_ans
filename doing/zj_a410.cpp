/*
[Q]
[]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int

struct sc{
	INT up=0;
	INT dn=0;
	void fix(){
		bool u=false;
		if(up<0 && dn<0){
			up=-up;
			dn=-dn;
		}else if((up<0 && dn>0)||(up>0 && dn<0)){
			u=true;
			up=abs(up);
			dn=abs(dn);
		}
		INT udgcd=__gcd(up,dn);
		up/=udgcd;
		dn/=udgcd;
		if(u)up=-up;
	}
	double gt(){
		fix();
		double re=up;
		return re/dn;
	}
};

sc getsc(INT a,INT b){
	sc re;
	re.up=a;
	re.dn=b;
	re.fix();
	return re;
}

bool operator==(sc a,sc b){
	return (a.up==b.up && a.dn==b.dn);
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(2);
	INT a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	/*solve*/
	/*
		[a,b,c]
		[d,e,f]
	*/
	sc aa,bb,cc;
	aa=getsc(a,d);
	bb=getsc(b,e);
	cc=getsc(c,f);
	if(aa==bb){
		if(aa==cc){
			cout<<"Too many"<<endl;
		}else{
			cout<<"No answer"<<endl;
		}
	}else{
		double ansy;
		{
			INT lst[2][3]={
				{a,b,c},
				{d,e,f}
			};
			INT adgcd=__gcd(a,d);
			INT upxx=d/adgcd;
			INT dnxx=a/adgcd;
			lst[0][0]*=upxx;
			lst[0][1]*=upxx;
			lst[0][2]*=upxx;
			
			lst[1][0]*=dnxx;
			lst[1][1]*=dnxx;
			lst[1][2]*=dnxx;
			sc yy;
			yy.dn=lst[0][1]-lst[1][1];
			yy.up=lst[0][2]-lst[1][2];
			yy.fix();
			ansy=yy.gt();
		}
		double ansx;
		{
			INT lst[2][3]={
				{b,a,c},
				{e,d,f}
			};
			INT adgcd=__gcd(a,d);
			INT upxx=d/adgcd;
			INT dnxx=a/adgcd;
			lst[0][0]*=upxx;
			lst[0][1]*=upxx;
			lst[0][2]*=upxx;
			
			lst[1][0]*=dnxx;
			lst[1][1]*=dnxx;
			lst[1][2]*=dnxx;
			sc xx;
			xx.dn=lst[0][1]-lst[1][1];
			xx.up=lst[0][2]-lst[1][2];
			xx.fix();
			ansx=xx.gt();
		}
		cout<<"x="<<ansx<<endl;
		cout<<"y="<<ansy<<endl;
	}



	return 0;
}

//ax+by=c
//ax=c-by