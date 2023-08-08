//#ifndef eval
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
bool debug=0;
template<typename tpe>tpe reader(){
	tpe re;cin>>re;return re;
	}

	string c1[]={
		"+",
			"-",
				"*",
					"/"
					};
					INT c1s=4;

					INT maxa=100;//設定a的最大值
					INT mina=0;//設定a的最小值

					int main(){
						cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
							srand( time(NULL) );//初始化RANDOM
								INT sf=0;
									INT f=10;//檔案數量
										for(INT i=sf;i<f;i++){
												INT t=5;//t筆測資
														string fname;
																fname="I_";//檔案名
																		fname+=char((i/10) +'0');
																				fname+=char((i%10)+'0');
																						fname+=".in";
																								cout<<"filename:"<<fname<<endl;//輸出檔案名
																										ofstream nwF(fname);//打開檔案

																												nwF<<t<<endl;
																														cout<<t<<endl;
																																while(t--){
																																			INT a=rand()%maxa+mina;
																																						INT b=rand()%maxa+mina;
																																									nwF<<a<<" "<<b<<endl;//寫入檔案
																																												cout<<a<<" "<<b<<endl;
																																														}
																																																
																																																		nwF.close();//關閉檔案
																																																				cout<<endl<<endl;
																																																					}
																																																						return 0;
																																																						}
																																																						//#endif

