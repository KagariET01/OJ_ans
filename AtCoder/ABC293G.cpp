/*
[Q]
[]
*/
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define PPIII pair<pair<INT,INT>,INT>

INT zip;
bool vser(PPIII a,PPIII b){
		INT al=a.first.first;
	INT ar=a.first.second;
		INT bl=b.first.first;
	INT br=b.first.second;
		INT alz=al/zip;
	INT arz=ar/zip;
		INT blz=bl/zip;
	INT brz=br/zip;
	if(alz==blz)return al<bl;
	else return 
}


int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	return 0;
}