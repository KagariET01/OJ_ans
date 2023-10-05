#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
bool debug=0;
bool noTLE=1;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
}
INT mp[9][9];
bool row[9][10],column[9][10],box[3][3][10];
INT ans=0;
void solve(INT x=0,INT y=0){
	if(x==0 && y==0){
		memset(row,0,sizeof(row));
		memset(column,0,sizeof(column));
		memset(box,0,sizeof(box));
		debug=1;
		for(INT i=0;i<9;i++){
			for(INT j=0;j<9;j++){
				cin>>mp[i][j];
				row[i][mp[i][j]]=1;
				column[j][mp[i][j]]=1;
				box[i/3][j/3][mp[i][j]]=1;
			}
		}
	}
	if(y==9){solve(x+1,0);}
	else if(x==9){
		for(INT i=0;i<9;i++){
			for(INT j=0;j<9;j++){
				if(j)cout<<" ";
				cout<<mp[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
		ans++;
	}
	else if(mp[x][y])solve(x,y+1);
	else{
		for(INT i=1;i<=9;i++){
			if(row[x][i] || column[y][i] || box[x/3][y/3][i])continue;
			row[x][i] = column[y][i] = box[x/3][y/3][i] = 1;
			mp[x][y]=i;
			solve(x,y+1);
			row[x][mp[x][y]] = column[y][mp[x][y]] = box[x/3][y/3][mp[x][y]] = 0;
			mp[x][y]=0;
		}
		mp[x][y]=0;
	}
	
	if(x==0 && y==0){
		cout<<"there are a total of "<<ans<<" solution(s)."<<endl;
	}
}
int main(int argc,char** argv){
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	solve();
	return 0;
}
