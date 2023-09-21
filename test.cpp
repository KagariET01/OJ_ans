#include<iostream>
using namespace std;
int main(){
	string str;
	cin>>str;
	if(str.find("小ㄌㄌ")!=string::npos){
		cout<<"ET01"<<endl;
	}else if(str.find("ㄌㄌ")!=string::npos){
		cout<<"ETorz"<<endl;
	}else{
		cout<<"01orz"<<endl;
	}
    return 0;
}