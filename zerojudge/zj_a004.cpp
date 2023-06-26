/*
[Q]https://kagariet01.github.io/swap/?OJ=zj&P=a004
[AC]
[while,巢狀if]
*/
#include<iostream>
using namespace std;
int main(){
	int year;
	while(cin>>year){
		if(year%4==0){
			if(year%100==0){
				if(year%400==0){
					cout<<"閏年"<<'\n';
				}else{
					cout<<"平年"<<'\n';
				}
			}else{
				cout<<"閏年"<<'\n';
			}
		}else{
			cout<<"平年"<<'\n';
		}
	}
	return 0;
}