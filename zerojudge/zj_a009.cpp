/*
[Q]https://kagariet01.github.io/swap/?OJ=zj&P=a009
[AC]
[基本語法]
*/
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
    /*-7*/
    string str1;
    getline(cin,str1);
    int str1_length=str1.length();
    for(int i=0;i<=str1_length;i++){
       str1[i]=str1[i]-7;
    }
    cout<<str1;
    return 0;
}