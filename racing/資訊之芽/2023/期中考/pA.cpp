/*
[Q]
[]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
bool debug=1;
template<typename TPE>TPE reader(){
	TPE re;cin>>re;return re;
}

const INT mxn=2e5;
const INT mxxy=2e5;
INT n,s,t;
INT c[mxn+1];
INT x[mxn+1];
INT y[mxn+1];
INT step[mxn+1];

bool ans=0;

struct str{
	INT x=0,y=0,c=0;
	INT id=0;
};
bool xvs(str a,str b){
	if(a.x==b.x)return a.y<b.y;
	else return a.x<b.x;
}
bool yvs(str a,str b){
	if(a.y==b.y)return a.x<b.x;
	else return a.y<b.y;
}
bool ul_rdvs(str a,str b){
	if(a.c==b.c)return (a.x+a.y)<(b.x+b.y);
	else return a.c<b.c;
}
bool ur_ldvs(str a,str b){
	if(a.c==b.c)return (a.x-a.y)<(b.x-b.y);
	else return a.c<b.c;
}

vector<str> xlst;
vector<str> ylst;
vector<str> ul_rdlst;
vector<str> ur_ldlst;

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT runt=1;
	while(runt--){
		cin>>n>>s>>t;
		s--;t--;
		xlst.reserve(n);
		ylst.reserve(n);
		ul_rdlst.reserve(n);
		ur_ldlst.reserve(n);
		for(INT i=0;i<n;i++){
			str nw;
			cin>>x[i]>>y[i]>>c[i];
			nw.x=x[i];
			nw.y=y[i];
			nw.c=c[i];
			nw.id=i;
			xlst.push_back(nw);
			ylst.push_back(nw);
			ul_rdlst.push_back(nw);
			ur_ldlst.push_back(nw);
		}

		sort(xlst.begin(),xlst.end(),xvs);
		sort(ylst.begin(),ylst.end(),yvs);
		sort(ul_rdlst.begin(),ul_rdlst.end(),ul_rdvs);
		sort(ur_ldlst.begin(),ur_ldlst.end(),ur_ldvs);
		
		deque<INT> dq;//做bfs，紀錄點編號
		dq.push_back(s);
		while(!ans && !dq.empty()){
			INT nw=dq.front();
			dq.pop_front();
			INT nx=x[nw];
			INT ny=y[nw];
			INT nc=c[nw];
			DBG cerr<<"nw="<<nw<<" nx="<<nx<<" ny="<<ny<<" nc="<<nc<<endl;
			if(ans) continue;
			{//x
				INT nwxit=0;
				{//二分搜出nwxit
					INT xlit=0,xrit=n;
					{//尋找第一個x=nx
						INT l=0,r=n;
						while(r>l){
							INT mnt=(l+r)/2;
							if(xlst[mnt].x<nx)l=mnt+1;
							else r=mnt;
						}
						xlit=r;
					}
					{//尋找最後一個x=nx
						INT l=0,r=n;
						while(r>l){
							INT mnt=(l+r)/2;
							if(xlst[mnt].x<=nx)l=mnt+1;
							else r=mnt;
						}
						xrit=r;
					}
					{//在裡面二分搜出自己的位置
						INT l=xlit,r=xrit;
						while(r>l){
							INT mnt=(l+r)/2;
							if(xlst[mnt].y<ny)l=mnt+1;
							else r=mnt;
						}
						nwxit=r;
					}
				}
				{
					INT nextx=xlst[nwxit-1].x;
					INT nexty=xlst[nwxit-1].y;
					INT nextid=xlst[nwxit-1].id;
					if(nextx==nx){
						if(step[nextid]==0 && nextid!=s){
							step[nextid]=step[nw]+1;
							dq.push_back(nextid);
						}
					}
				}
				{
					INT nextx=xlst[nwxit+1].x;
					INT nexty=xlst[nwxit+1].y;
					INT nextid=xlst[nwxit+1].id;
					if(nextx==nx){
						if(step[nextid]==0 && nextid!=s){
							step[nextid]=step[nw]+1;
							dq.push_back(nextid);
						}
					}
				}
			}
			{//y
				INT nwyit=0;
				{//二分搜出nwxit
					INT ylit=0,yrit=n;
					{//尋找第一個x=nx
						INT l=0,r=n;
						while(r>l){
							INT mnt=(l+r)/2;
							if(ylst[mnt].y<ny)l=mnt+1;
							else r=mnt;
						}
						ylit=r;
					}
					{//尋找最後一個x=nx
						INT l=0,r=n;
						while(r>l){
							INT mnt=(l+r)/2;
							if(ylst[mnt].y<=ny)l=mnt+1;
							else r=mnt;
						}
						yrit=r;
					}
					{//在裡面二分搜出自己的位置
						INT l=ylit,r=yrit;
						while(r>l){
							INT mnt=(l+r)/2;
							if(ylst[mnt].x<nx)l=mnt+1;
							else r=mnt;
						}
						nwyit=r;
					}
				}
				{
					INT nextx=xlst[nwyit-1].x;
					INT nexty=xlst[nwyit-1].y;
					INT nextid=xlst[nwyit-1].id;
					if(nexty==ny){
						if(step[nextid]==0 && nextid!=s){
							step[nextid]=step[nw]+1;
							dq.push_back(nextid);
						}
					}
				}
				{
					INT nextx=xlst[nwyit+1].x;
					INT nexty=xlst[nwyit+1].y;
					INT nextid=xlst[nwyit+1].id;
					if(nexty==ny){
						if(step[nextid]==0 && nextid!=s){
							step[nextid]=step[nw]+1;
							dq.push_back(nextid);
						}
					}
				}
			}
			{//ul_rd
				INT nwaitl=0,nwaitr=0;
				{//二分搜出nwxit
					INT alit=0,arit=n;
					{//尋找第一個x=nx
						INT l=0,r=n;
						while(r>l){
							INT mnt=(l+r)/2;
							if(ul_rdlst[mnt].c<nc)l=mnt+1;
							else r=mnt;
						}
						alit=r;
					}
					{//尋找最後一個x=nx
						INT l=0,r=n;
						while(r>l){
							INT mnt=(l+r)/2;
							if(ul_rdlst[mnt].c<=nc)l=mnt+1;
							else r=mnt;
						}
						arit=r;
					}
					{//在裡面二分搜出自己的位置
						INT l=alit,r=arit;
						while(r>l){
							INT mnt=(l+r)/2;
							if((ul_rdlst[mnt].x+ul_rdlst[mnt].y)<(nx+ny))l=mnt+1;
							else r=mnt;
						}
						nwaitl=r;
					}
					{//在裡面二分搜出自己的位置
						INT l=alit,r=arit;
						while(r>l){
							INT mnt=(l+r)/2;
							if((ul_rdlst[mnt].x+ul_rdlst[mnt].y)<=(nx+ny))l=mnt+1;
							else r=mnt;
						}
						nwaitr=r;
					}
				}
				for(INT nexti=nwaitl;nexti<nwaitr;nexti++){
					INT nextx=xlst[nexti].x;
					INT nexty=xlst[nexti].y;
					INT nextid=xlst[nexti].id;
					INT nextc=xlst[nexti].c;
					if(nextc==nc){
						if(step[nextid]==0 && nextid!=s){
							step[nextid]=step[nw]+1;
							dq.push_back(nextid);
						}
					}
				}
			}
			{//ur_ld
				INT nwaitl=0,nwaitr=0;
				{//二分搜出nwxit
					INT alit=0,arit=n;
					{//尋找第一個x=nx
						INT l=0,r=n;
						while(r>l){
							INT mnt=(l+r)/2;
							if(ur_ldlst[mnt].c<nc)l=mnt+1;
							else r=mnt;
						}
						alit=r;
					}
					{//尋找最後一個x=nx
						INT l=0,r=n;
						while(r>l){
							INT mnt=(l+r)/2;
							if(ur_ldlst[mnt].c<=nc)l=mnt+1;
							else r=mnt;
						}
						arit=r;
					}
					{//在裡面二分搜出自己的位置
						INT l=alit,r=arit;
						while(r>l){
							INT mnt=(l+r)/2;
							if((ur_ldlst[mnt].x-ur_ldlst[mnt].y)<(nx-ny))l=mnt+1;
							else r=mnt;
						}
						nwaitl=r;
					}
					{//在裡面二分搜出自己的位置
						INT l=alit,r=arit;
						while(r>l){
							INT mnt=(l+r)/2;
							if((ur_ldlst[mnt].x-ur_ldlst[mnt].y)<=(nx-ny))l=mnt+1;
							else r=mnt;
						}
						nwaitr=r;
					}
				}
				for(INT nexti=nwaitl;nexti<nwaitr;nexti++){
					INT nextx=xlst[nexti].x;
					INT nexty=xlst[nexti].y;
					INT nextid=xlst[nexti].id;
					INT nextc=xlst[nexti].c;
					if(nextc==nc){
						if(step[nextid]==0 && nextid!=s){
							step[nextid]=step[nw]+1;
							dq.push_back(nextid);
						}
					}
				}
			}

			if(step[t]){
				ans=1;
			}
		}
		if(ans){
			cout<<step[t]<<endl;
			if(!debug)break;
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}