/*
[Q]https://neoj.sprout.tw/problem/124/
[AC]
*/
#include<bits/stdc++.h>
using namespace std;

void solve(int,int,int);
void goodsolve(int,int,int,int,int,int);

//void Report(int,int,int,int,int,int);




void solve(int N,int X,int Y){
	goodsolve(0,N-1,0,N-1,X-1,Y-1);
}

void goodsolve(int lx,int rx,int ly,int ry,int airx,int airy){
	if(rx==lx){
		return;
	}else{
		pair<int,int> a,b,c,d;
		int Ax=(lx+rx)/2;
		int Ay=(ly+ry)/2;
		a={Ax,Ay};
		b={a.first+1,a.second+0};
		c={a.first+0,a.second+1};
		d={a.first+1,a.second+1};
		if(airx <= Ax && airy <= Ay){
			goodsolve(lx,Ax,ly,Ay,airx,airy);
			goodsolve(Ax+1,rx,ly,Ay,Ax+1,Ay);
			goodsolve(lx,Ax,Ay+1,ry,Ax,Ay+1);
			goodsolve(Ax+1,rx,Ay+1,ry,Ax+1,Ay+1);
			Report(b.first+1,b.second+1,c.first+1,c.second+1,d.first+1,d.second+1);
		}else if(airx>Ax && airy<=Ay){
			goodsolve(lx,Ax,ly,Ay,Ax,Ay);
			goodsolve(Ax+1,rx,ly,Ay,airx,airy);
			goodsolve(lx,Ax,Ay+1,ry,Ax,Ay+1);
			goodsolve(Ax+1,rx,Ay+1,ry,Ax+1,Ay+1);
			Report(a.first+1,a.second+1,c.first+1,c.second+1,d.first+1,d.second+1);
		}else if(airx<=Ax && airy>Ay){
			goodsolve(lx,Ax,ly,Ay,Ax,Ay);
			goodsolve(Ax+1,rx,ly,Ay,Ax+1,Ay);
			goodsolve(lx,Ax,Ay+1,ry,airx,airy);
			goodsolve(Ax+1,rx,Ay+1,ry,Ax+1,Ay+1);
			Report(a.first+1,a.second+1,b.first+1,b.second+1,d.first+1,d.second+1);
		}else{
			goodsolve(lx,Ax,ly,Ay,Ax,Ay);
			goodsolve(Ax+1,rx,ly,Ay,Ax+1,Ay);
			goodsolve(lx,Ax,Ay+1,ry,Ax,Ay+1);
			goodsolve(Ax+1,rx,Ay+1,ry,airx,airy);
			Report(a.first+1,a.second+1,b.first+1,b.second+1,c.first+1,c.second+1);
		}
	}
}


/*
void Report(int a,int b,int c,int d,int e,int f){
	cout<<"Report("<<a<<","<<b<<","<<c<<","<<d<<","<<e<<","<<f<<");"<<endl;
}

int main(){
	int n,x,y;
	cin>>n>>x>>y;
	solve(n,x,y);
	return 0;
}
*/