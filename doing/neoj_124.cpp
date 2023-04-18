/*
[Q]
[]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT int
#define PII pair<INT,INT>
#define endl "\n"

bool operator==(PII a,PII b){
	return (a.first==b.first && a.second==b.second);
}

void Report(int x1,int y1,int x2,int y2,int x3,int y3);





void pairre(PII a,PII b,PII c){
	Report(a.first,a.second,b.first,b.second,c.first,c.second);
}

void goodsolve(int lx,int rx,int ly,int ry,int airx,int airy){
	//cerr<<"dbg "<<lx<<" "<<rx<<" "<<ly<<" "<<ry<<" "<<airx<<" "<<airy<<endl;
	if(rx==lx+1){
		PII a,b,c,d;
		a={lx,ry};
		b={rx,ry};
		c={lx,ly};
		d={rx,ly};
		PII nw={airx,airy};
		if(a==nw){
			pairre(b,c,d);
		}else if(b==nw){
			pairre(a,c,d);
		}else if(c==nw){
			pairre(a,b,d);
		}else{
			pairre(a,b,c);
		}
	}else{
		PII a,b,c,d;
		INT Ax=(lx+rx)/2;
		INT Ay=(lx+rx)/2;
		a={Ax,Ay};
		b={a.first+1,a.second+0};
		c={a.first+0,a.second+1};
		d={a.first+1,a.second+1};
		if(airx <= Ax && airy <= Ay){//<^
			goodsolve(lx,Ax,ly,Ay,airx,airy);
			goodsolve(Ax+1,rx,ly,Ay,Ax+1,Ay);
			goodsolve(lx,Ax,Ay+1,ry,Ax,Ay+1);
			goodsolve(Ax+1,rx,Ay+1,ry,Ax+1,Ay+1);
			pairre(b,c,d);
		}else if(airx>Ax && airy<=Ay){//>^
			goodsolve(lx,Ax,ly,Ay,Ax,Ay);
			goodsolve(Ax+1,rx,ly,Ay,airx,airy);
			goodsolve(lx,Ax,Ay+1,ry,Ax,Ay+1);
			goodsolve(Ax+1,rx,Ay+1,ry,Ax+1,Ay+1);
			pairre(a,c,d);
		}else if(airx<=Ax && airy>Ay){//<V
			goodsolve(lx,Ax,ly,Ay,Ax,Ay);
			goodsolve(Ax+1,rx,ly,Ay,Ax+1,Ay);
			goodsolve(lx,Ax,Ay+1,ry,airx,airy);
			goodsolve(Ax+1,rx,Ay+1,ry,Ax+1,Ay+1);
			pairre(a,b,d);
		}else{
			goodsolve(lx,Ax,ly,Ay,Ax,Ay);
			goodsolve(Ax+1,rx,ly,Ay,Ax+1,Ay);
			goodsolve(lx,Ax,Ay+1,ry,Ax,Ay+1);
			goodsolve(Ax+1,rx,Ay+1,ry,airx,airy);
			pairre(a,b,c);
		}

	}
}
void solve(int N,int X,int Y){
	goodsolve(0,N-1,0,N-1,X-1,Y-1);
}

int main(){return 0;}
void Report(int x1,int y1,int x2,int y2,int x3,int y3){}

/*



int main(){
	int n,x,y;
	cin>>n>>x>>y;
	solve(n,x,y);
	return 0;
}
void Report(int x1,int y1,int x2,int y2,int x3,int y3){
	cout<<x1+1<<" "<<y1+1<<" "<<x2+1<<" "<<y2+1<<" "<<x3+1<<" "<<y3+1<<endl;
}


/*



/*
+---+---+
|   |   |
| A | B |
|   |   |
+---+---+
|   |   |
| C | D |
|   |   |
+---+---+
*/