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

template<typename TPE> struct ETmath{
	/*
		向量Vec
	*/
	struct Vec{
		TPE x=0,y=0;
		void setv(const TPE &a,const TPE &b){
			x=a,y=b;
		}
	};
	Vec make_Vec(const TPE &a,const TPE &b){
		Vec re;
		re.x=a,re.y=b;
		return re;
	}

	/*
		點Pnt
	*/
	struct Pnt{
		TPE x=0,y=0;
		void setv(const TPE &a,const TPE &b){
			x=a,y=b;
		}
	};
	Pnt make_Pnt(const TPE &a,const TPE &b){
		Pnt re;
		re.x=a,re.y=b;
		return re;
	}

	/*
		點連成向量
	*/
	Vec Pnt_Vec(const Pnt &a,const Pnt &b){

	}

	/*
		內積*
		AB內積=A的長度*B的長度*cos(AB夾角)
		內積=0:兩向量垂直
		內積>0 夾角<90度
		內積<0 夾角>90度
	*/
	TPE Dot(const Vec &a,const Vec &b){
		return a.x*b.x+a.y*b.y;
	}
	TPE operator*(const Vec &a,const Vec &b){
		return Dot(a,b);
	
	}
	
	/*
		外機^
		AB外積=A的長度*B的長度*sin(AB夾角)
		外積=0:兩向量平行
		外積>0 B 向量在 A 向量的逆時針方向
		外積<0 B 向量在 A 向量的順時針方向
	*/
	TPE cross(const Vec &a,const Vec &b){
		return a.x*b.y-a.y*b.x;
	}
	TPE operator^(const Vec &a,const Vec &b){
		return cross(a,b);
	}
};
