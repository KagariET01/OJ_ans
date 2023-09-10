/*
[q]
[]
*/
//#ifndef eval
#include<string>
#include<iostream>
#include<fstream>
#include<cstring>
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

const INT mxn=20;
const INT pwn=mxn*mxn;

bool row[pwn+5][pwn+5],column[pwn+5][pwn+5];//-,|
bool block[mxn+5][mxn+5][pwn+5];

INT mp[pwn+5][pwn+5];
bool lc[pwn+5][pwn+5];

string inname="";
string outname="";

ofstream file;
ifstream infile;
/*
bool find(INT x,INT y,INT n){
	if(x>=n*n){
		for(INT i=0;i<(n*n);i++){
			for(INT j=0;j<(n*n);j++){
				if(j)file<<" ";
				file<<mp[i][j];
			}
			file<<endl;
		}
		return 1;
	}
	if(y>=n*n)return find(x+1,y-n*n,n);
	if(mp[x][y]){
		return find(x,y+1,n);
	}
	for(INT i=1;i<=n*n;i++){
		if(!row[x][i] && !column[y][i] && !block[(x/n)][(y/n)][i]){
			mp[x][y]=i;
			row[x][i]=1;
			column[y][i]=1;
			block[(x/n)][(y/n)][i]=1;
			if(find(x,y+1,n))return 1;
			row[x][i]=0;
			column[y][i]=0;
			block[(x/n)][(y/n)][i]=0;
		}
	}
	return 0;
}
*/
bool find(INT x,INT y,INT n){
	while(true){
		if(x>=n*n)break;
		else if(y<0){
			x-=1;
			y+=n*n;
		}
		else if(y>=n*n){
			x+=1;
			y-=n*n;
			DBG cerr<<endl;
		}
		else if(lc[x][y]){
			DBG cerr<<mp[x][y]/100<<(mp[x][y]%100)/10<<mp[x][y]%10<<" ";
			y++;
		}else{
			row[x][mp[x][y]]=column[y][mp[x][y]]=block[(x/n)][(y/n)][mp[x][y]]=0;
			do{
				mp[x][y]=(x/20+20*((x%20==0?20:x%20)-1)+y)%400;
				mp[x][y]=(mp[x][y]==0?400:mp[x][y]);
			}while(row[x][mp[x][y]] || column[y][mp[x][y]] || block[(x/n)][(y/n)][mp[x][y]]);
			if(mp[x][y]>n*n){
				mp[x][y]=0;
				do{
					DBG cerr<<"\b\b\b\b    \b\b\b\b";
					y--;
					if(y<0){
						x-=1;
						y+=n*n;
						cerr<<"\b";
					}
				}while(lc[x][y]);
			}else{
				row[x][mp[x][y]]=column[y][mp[x][y]]=block[(x/n)][(y/n)][mp[x][y]]=1;
				DBG cerr<<mp[x][y]/100<<(mp[x][y]%100)/10<<mp[x][y]%10<<" ";
				y++;
			}
		}
	}
	for(INT i=0;i<(n*n);i++){
		for(INT j=0;j<(n*n);j++){
			if(j)file<<" ";
			file<<mp[i][j];
		}
		file<<endl;
	}
	return 1;
}

int main(int argc,char** argv){
	for(int i=0;i<argc;i++){
		string nwstr=argv[i];
		if(nwstr=="-Dev"){
			debug=1;
			noTLE=0;
		}else if(nwstr=="-TLE"){
			noTLE=0;
		}
	}
	if(noTLE && !debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
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
	INT t=5;
	for(INT nwcase=5;nwcase<=t;nwcase++){
		string nwf="pDout/";
		nwf+=('0'+(nwcase>=10?1:0));
		nwf+=('0'+(nwcase%10));
		string onwf=nwf+".out";
		file.open(onwf);
		string inwf=nwf+".in";
		infile.open(inwf);
		DBG{
			cerr<<"read file:"<<inwf<<endl;
		}
		memset(row,0,sizeof(row));
		memset(column,0,sizeof(column));
		memset(block,0,sizeof(block));
		memset(mp,0,sizeof(mp));
		INT n;
		infile>>n;
		for(INT i=0;i<n*n;i++){
			for(INT j=0;j<n*n;j++){
				infile>>mp[i][j];
				row[i][mp[i][j]]=1;
				column[j][mp[i][j]]=1;
				block[(i/n)][j/n][mp[i][j]]=1;
				lc[i][j]=mp[i][j];
			}
		}
		DBG cerr<<"write file:"<<onwf<<endl;
		DBG cerr<<"now:"<<endl;
		find(0,0,n);
		DBG cerr<<endl;
		file.close();
		infile.close();
		DBG cerr<<"task id:"<<nwcase<<" complete."<<endl;
	}
	return 0;
}
//#endif
