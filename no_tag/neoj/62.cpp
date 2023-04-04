/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/ [ID]
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid= [ID]
[cses]			[Q]https://cses.fi/problemset/task/ [ID]
[AtCoder]		[Q]https://atcoder.jp/contests/ [ID] /tasks/ [ID] _ [PID]
[CF]				[Q]
[ioic_2023]	[Q]https://judge.ioicamp.org/problems/ [ID]
[neoj]			[Q]https://neoj.sprout.tw/problem/ [ID]

[]

[result]		[AC]
[time]			[0]
[mem]				[5616]
[challenge]	[241166]
[sub time]	[2023/04/03 16:00:06]
*/


/*include*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")
//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define what_the_fuck cin.tie(0);cout.tie(0);ios::sync_with_stdio(false)
#define INT long long int
#define set0(n) memset(n,0,sizeof(n))

int mp[9][9];
bool rower[9][10];//rower[i][j]代表第i直行是否有j
bool liner[9][10];
bool boxer[3][3][10];

bool solve(int x,int y){
	if(x>=9)return true;
	if(y>=9)return solve(x+1,0);
	if(mp[x][y]>0)return solve(x,y+1);
	for(int i=1;i<=9;i++){
		if(rower[y][i] || liner[x][i] || boxer[x/3][y/3][i])continue;
		rower[y][i]=liner[x][i]=boxer[x/3][y/3][i]=true;
		mp[x][y]=i;
		if(solve(x,y+1))return true;
		else{
			rower[y][i]=liner[x][i]=boxer[x/3][y/3][i]=false;
			mp[x][y]=-1;
		}
	}
	return false;
}


/*main*/
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	srand(time(NULL));
	INT t;
	cin>>t;
	while(t--){
		/*re0*/
		set0(mp);
		set0(rower);
		set0(liner);
		set0(boxer);
		/*CIN*/
		string str;
		cin>>str;
		bool noans=false;
		for(INT i=0;i<9;i++){
			if(noans)break;
			for(INT j=0;j<9;j++){
				char &nw=str[i*9+j];
				if(nw=='.'){
					mp[i][j]=-1;
				}else{
					INT nwnm=nw-'0';
					if(rower[j][nwnm] || liner[i][nwnm] || boxer[i/3][j/3][nwnm]){
						noans=true;
						break;
					}
					mp[i][j]=nwnm;
					rower[j][nwnm]=liner[i][nwnm]=boxer[i/3][j/3][nwnm]=true;
				}
			}
		}
		/*solve*/
		if((!noans) && solve(0,0)){
			for(INT i=0;i<9;i++){
				for(INT j=0;j<9;j++){
					cout<<mp[i][j];
				}
			}
		}else{
			cout<<"No solution.";
		}
		cout<<endl;
	}
	return 0;
}
