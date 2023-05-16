/*
[Q]https://neoj.sprout.tw/problem/136/
[20%]
*/

#include<bits/stdc++.h>
void solve(int N,long long K,long long A[]){
	if(N>10){
		Report(-1);
		return;
	}
	long long n=1<<N;
	for(long long i=0;i<n;i++){
		long long tt=0;
		for(long long j=0;j<N;j++){
			if(i&(1<<j)){
				tt+=A[j];
			}
		}
		if(tt==K){
			for(long long j=0;j<N;j++){
				if(i&(1<<j)){
					Report(j+1);
				}
			}
			Report(-1);
			return;
		}
	}
	Report(-1);
	return;
}