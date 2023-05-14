/*
[Q]
[]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()

bool debug=0;

struct ETmath{
	struct vec{
		INT x=0,y=0;
		void setv(const INT &a,const INT &b){
			x=a,y=b;
		}
	};
	long long int Dot_Product(vec a,vec b){
		return a.x*b.x+a.y*b.y;
	}
	long long int operator*(vec a,vec b){
		return Dot_Product(vec a,vec b);
	}
};
