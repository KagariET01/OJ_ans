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


bool lc[pwn+5][pwn+5];

string inname="";
string outname="";

ifstream file;
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
	INT t=read(INT);
	for(INT nwcase=t;nwcase<=t;nwcase++){
		string nwf="pDout/";
		nwf+=('0'+(nwcase>=10?1:0));
		nwf+=('0'+(nwcase%10));
		string inwf=nwf+".out";
		string outwf=nwf+".in";
		infile.open(inwf);
		file.open(outwf);
		DBG{
			cerr<<"checking file:"<<inwf<<endl;
		}
		INT n;
		file>>n;
		DBG cerr<<"now point:000 000";
		bool AC=true;
		INT i=0,j=0;
		bool row[pwn+5][pwn+5]={},column[pwn+5][pwn+5]={};//-,|
		bool block[mxn+5][mxn+5][pwn+5]={};

		INT mp[pwn+5][pwn+5]={};
		for(;i<n*n && AC;i++){
			for(;j<n*n && AC;j++){
				DBG{
					cerr<<"\b\b\b\b\b\b\b";
					cerr<<i/100<<(i%100)/10<<i%10<<" ";
				}
				infile>>mp[i][j];
				if(
					row[i][mp[i][j]] ||
					column[j][mp[i][j]] ||
					block[(i/n)][j/n][mp[i][j]] 
				){
					AC=0;
					break;
				}
				row[i][mp[i][j]]=1;
				column[j][mp[i][j]]=1;
				block[(i/n)][j/n][mp[i][j]]=1;
				
			}
		}
		DBG cerr<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                 \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		if(AC){
			cout<<"file:"<<nwf<<" AC"<<endl;
		}else{
			cout<<"file:"<<nwf<<" WA at point"<<i<<" "<<j<<endl;
		}
	}
	return 0;
}
//#endif
