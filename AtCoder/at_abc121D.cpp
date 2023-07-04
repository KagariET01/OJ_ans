/*
[Q]https://kagariet01.github.io/swap/?OJ=at&C=abc121&P=D
[math][bit]
[AC]
*/
#include<iostream>
#include<cmath>
using namespace std;
#define ulli unsigned long long int
ulli solve(ulli a){
	switch(a%4){
		case 0:
			return a;
		break;
		case 1:
			return 1;
		break;
		case 2:
			return a+1;
		break;
		case 3:
			return 0;
		break;
	}
}
int main(){
	ulli fir,las;
	cin>>fir>>las;
	cout<<(solve(fir-1)^solve(las))<<"\n";
	return 0;
}
/*
類似於前綴和
T(A,B)=T(0,B)-T(0,A-1)
F(A,B)=F(0,B)^F(0,A-1)=F(0,A-1)^F(0,B)
用前綴和的思維去思考，就能證明他是對的
我懶得打解釋了
可以證明最後的cout是對的
那我們就要來求如何快速找到F(0,n)
下面有兩個個非常重要的性質
n^n=0
任意偶數n n^(n+1)=1



設n=7=(a*4+3)
我們可以得到
0^1^2^3^4^5^6^7
=(0^1)^(2^3)^(4^5)^(6^7)
=[(0^1)^(2^3)]^[(4^5)^(6^7)]
=[1^1]^[1^1]
=0^0=0

設n=8=(a*4)
0^1^2^3^4^5^6^7^8
=0^8=8

n=9=(a*4+1)
[0^1^2^3^4^5^6^7]^8^9
=0^8^9
=0^(8^9)
=0^1=1

n=10=(a*4+2)
[0^1^2^3^4^5^6^7]^8^9^10
=0^(8^9)^10
=0^1^10
=1^10
=11=10+1

n=11(a*4+3)(loop)
[0^1^2^3^4^5^6^7]^8^9^10^11
=0^[8^9]^[10^11]
=0^1^1
=0

上述可以證明函數solve(a)是對的


*/