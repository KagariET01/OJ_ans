/*
[Q]https://zerojudge.tw/ShowProblem?problemid=c291
*/
#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int int_list_friend[n]={0};
	for(int i=0;i<n;i++){
		cin>>int_list_friend[i];
	}
	int nextfind=0,counter=0;
	for(int i=0;i<n;i++){
		if(int_list_friend[i]<n){
			nextfind=int_list_friend[i];
			/*cout<<i;*/
			while(int_list_friend[i]!=int_list_friend[nextfind]){
				int j=nextfind;
				nextfind=int_list_friend[nextfind];
				int_list_friend[j]=n+1;
			}
			int_list_friend[nextfind]=n+1;
			counter++;
		}
	}
	cout<<counter;
	return 0;
}