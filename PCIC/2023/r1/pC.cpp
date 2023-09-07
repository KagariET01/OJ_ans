#include "Minesweeper.h"

//----do not modify above----
void defuse_mines(int N){
	int mx[]={1,1,1,0,0,0,-1,-1,-1};
	int my[]={1,0,-1,1,0,-1,1,0,-1};
	int asdfqwer[N+1][N+1];//表周圍有幾顆地雷
	int bomb[N+5][N+5];//-1表保證沒地雷，1保證有地雷
	for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				asdfqwer[i][j]=bomb[i][j]=0;
			}
	}
	for(int i=1;i<=N;i++){
		bomb[i][1]=-1;
		bomb[1][i]=-1;
		bomb[i][N]=-1;
		bomb[N][i]=-1;
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			asdfqwer[i][j]=detect(i,j);
		}
	}
	for(int k=0;k<10;k++){
		//標註保證枚地雷
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(asdfqwer[i][j]==0){//卻認為0
					for(int mm=0;mm<9;mm++){
						int nwx=i+mx[mm];
						int nwy=j+my[mm];
						if(
							1<=nwx && nwx<=N &&
							1<=nwy && nwy<=N
						){
							bomb[nwx][nwy]=-1;
						}
					}
				}
			}
		}
		//拆除確認有地雷的
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(asdfqwer[i][j]==0)continue;
				int nwair=0;//找出不確定的格子數
				//asdfqwer
				for(int mm=0;mm<9;mm++){
					int nwx=i+mx[mm];
					int nwy=j+my[mm];
					if(
						1<=nwx && nwx<=N &&
						1<=nwy && nwy<=N &&
						bomb[nwx][nwy]==0
					){
						nwair++;
					}
				}
				if(asdfqwer[i][j]==nwair){//如果目前地雷偵測器==不確定格子數，娜些格子一定是地雷
					//拆雷
					for(int mm=0;mm<9;mm++){
						int nwx=i+mx[mm];
						int nwy=j+my[mm];
						if(
							1<=nwx && nwx<=N &&
							1<=nwy && nwy<=N &&
							bomb[nwx][nwy]==0
						){
							defuse(nwx,nwy);
							bomb[nwx][nwy]==-1;
							//拆除地雷，附近的徵測器也會影響
							for(int mmmm=0;mmmm<9;mmmm++){
								int nwnwx=nwx+mx[mmmm];
								int nwnwy=nwy+my[mmmm];
								if(
									1<=nwnwx && nwnwx<=N &&
									1<=nwnwy && nwnwy<=N
								){
									asdfqwer[nwnwx][nwnwy]--;
									
								}
							}
						}
					}
				}
			}
		}
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

int main() {
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
