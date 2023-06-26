/*
[Q]https://zerojudge.tw/ShowProblem?problemid=h026
[AC]
[模擬]
*/
#include<iostream>
#include<algorithm>
using namespace std;
#define INT int

int wl(int a,int b){
	if(a==0){
		if(b==0){
			return 0;
		}else if(b==2){
			return 1;
		}else{
			return -1;
		}
	}else if(a==2){
		if(b==0){
			return -1;
		}else if(b==2){
			return 0;
		}else{
			return 1;
		}
	}else{
		if(b==0){
			return 1;
		}else if(b==2){
			return -1;
		}else{
			return 0;
		}
	}
}
int iwantwin(int a){
	if(a==0){
		return 5;
	}else if(a==2){
		return 0;
	}else{
		return 2;
	}
}
/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	INT f,n;
	cin>>f>>n;
	INT y[n+1];
	y[0]=100;
	for(int i=1;i<=n;i++){
		cin>>y[i];
		cout<<f<<" ";
		int thiswl=wl(f,y[i]);
		if(thiswl==1){
			cout<<": Won at round "<<i;
			break;
		}else if(thiswl==-1){
			cout<<": Lost at round "<<i;
			break;
		}else if(i!=n){
			if(y[i-1]==y[i]){
				f=iwantwin(y[i]);
			}else{
				f=y[i];
			}
		}else{
			cout<<": Drew at round "<<n;

		}
	}
	return 0;
}
