#include "Minesweeper.h"
#include<bits/stdc++.h>
using namespace std;
#define DBG if(debug)
bool debug=0;
//----do not modify above----
void defuse_mines(int N){
	int mx[]={-1,-1,-1,0,0,0,1,1,1};
	int my[]={-1,0,1,-1,0,1,-1,0,1};
	int mp[N+1][N+1];//表周圍有幾顆地雷
	bool ask[N+1][N+1];
	int bomb[N+5][N+5];//1保證有地雷
	int rembomb=0;//紀錄已拆除的地雷數量
	pair<int,int> ans[N];
	for(int i=1;i<=N;i++){//初始化
			for(int j=1;j<=N;j++){
				mp[i][j]=ask[i][j]=0;
				bomb[i][j]=-1;
			}
	}
	for(int i=1;i<=N;i++){//最邊邊一定沒有地雷
		bomb[i][1]=0;
		bomb[1][i]=0;
		bomb[i][N]=0;
		bomb[N][i]=0;
	}
	for(int i=3;i<=N;i++){//拆雷
		if(i%3 && i!=N)continue;
		if(rembomb>=N)break;
		for(int j=3;j<=N;j++){
			if(j%3 && j!=N)continue;
			if(rembomb>=N)break;
			if(!ask[i][j])
				mp[i][j]=detect(i,j);
			if(mp[i][j]==0){//周圍沒地雷
				for(int k=0;k<9;k++){
					int nx=i+mx[k];
					int ny=j+my[k];
					if(1<=nx && nx<=N &&
						1<=ny && ny<=N
					){
						bomb[i][1]=1;
					}
				}
			}else{//周圍有地雷
				int cx=i-1;
				int cy=j-1;
				int nwbmb=mp[i][j];
				for(int k=0;k<9;k++){//九宮格搜尋
					if(!nwbmb){
						bomb[nx+1][ny+1]=0;
					}
					int nx=cx+mx[k];
					int ny=cy+my[k];
					if(1<=nx && nx<=N &&
						1<=ny && ny<=N
						){
						if(!ask[nx][ny])
							mp[nx][ny]=detect(nx,ny);
						int nwfnd=mp[nx][ny];
						for(int ii=0;ii<9;ii++){
							int ax=nx+mx[ii];
							int ay=ny+my[ii];
							if(1<=ax && ax<=N &&
								1<=ay && ay<=N &&
								bomb[ax][ay]==1;
							){
								nwfnd-=1;
							}
						}
						DBG cerr<<"{"<<nx<<","<<ny<<"} nwfnd="<<nwfnd<<endl;
						if(nwfnd==0){
							bomb[nx+1][ny+1]=0;
						}else{
							bomb[nx+1][ny+1]=1;
							ans[rembomb]={nx+1,ny+1};
							rembomb++;
							nwbmb--;
						}
					}
				}
			}
		}
	}
	DBG cerr<<"out"<<endl;
	for(pair<int,int> i:ans){
		defuse(i.first,i.second);
		DBG cerr<<i.first<<","<<i.second<<endl;
	}
	DBG{
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				cout<<mp[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				cout<<bomb[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
}

//----do not modify below----

#ifndef EVAL
#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

namespace {
	int N,x,y;
	std::vector<std::pair<int,int>> mines;
	int arr[510][510];
	bool vis[510][510];
	int count1,count2,correct;
	void wa(const char* msg) {
		printf("Wrong Answer: %s\n", msg);
		exit(0);
	}
}

int detect(int x,int y){
	++count1;
	if(x<1||y<1||x>N||y>N)
		wa("invalid detect query");
	return arr[x][y];
}

void defuse(int x,int y){
	++count2;
	if(count2 > N)
		wa("too many defuse operations");
	if(x<2||y<2||x>N-1||y>N-1)
		wa("invalid defuse operation");
	if(!vis[x][y]){
		vis[x][y] = 1;
		for(auto i:mines){
			if(i==std::make_pair(x,y)){
				correct++;
			}
		}
	}
}

int main(int argc,char** argv) {
	for(int i=0;i<argc;i++){
		string nwstr=argv[i];
		if(nwstr=="-Dev"){
			debug=1;
		}else if(nwstr=="-TLE"){
		}
	}
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
	assert(1 == scanf("%d", &N));
	for(int i=1;i<=N;i++){
		assert(2 == scanf("%d %d", &x, &y));
		mines.push_back(std::make_pair(x,y));
	}
	for(int i=0;i<N;i++){
		x = mines[i].first;
		y = mines[i].second;
		for(int j=-1;j<=1;j++){
			for(int k=-1;k<=1;k++){
				arr[x+j][y+k]++;
			}
		}
	}
	defuse_mines(N);
	printf("Accepted: %d %d %d %d\n", N, count1, count2, correct);
}
#endif // EVAL

/*
6
2 2
3 3
3 4
4 2
4 5
5 3
*/