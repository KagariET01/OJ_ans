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
	/*
		向量vec
	*/
	struct vec{
		INT x=0,y=0;
		void setv(const INT &a,const INT &b){
			x=a,y=b;
		}
	};
	
	/*
		內積*
		AB內積=A的長度*B的長度*cos(AB夾角)
		內積=0:兩向量垂直
		內積>0 夾角<90度
		內積<0 夾角>90度
	*/
	long long int Dot(const vec &a,const vec &b){
		return a.x*b.x+a.y*b.y;
	}
	long long int operator*(const vec &a,const vec &b){
		return Dot(a,b);
	
	}
	
	/*
		外機^
		AB外積=A的長度*B的長度*sin(AB夾角)
		外積=0:兩向量平行
		外積>0 B 向量在 A 向量的逆時針方向
		外積<0 B 向量在 A 向量的順時針方向
	*/
	long long int cross(const vec &a,const vec &b){
		return a.x*b.y-a.y*b.x;
	}
	long long int operator^(const vec &a,const vec &b){
		return cross(a,b);
	}
};
