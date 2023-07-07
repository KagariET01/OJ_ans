/*
[q]https://kagariet01.github.io/swap/?OJ=cf&C=1847&P=A
[DP 動態規劃]
[AC]
*/
//#ifndef eval
#include<bits/stdc++.h>
#define endl "\n"
#define DBG if(debug)

#define 整數 int
#define 長整數 long long int
#define 無負號 unsigned
#define 布林 bool
#define 小數 float
#define 超級小數 double
#define 換行 endl
#define 輸入 cin
#define 輸出 cout
#define 模板 template
#define 不會超時 cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define 回傳 return
#define 主程式 int main
#define 如果 if
#define 否則如果 else if
#define 否則 else
#define 計數迴圈 for
#define 條件迴圈 while
#define 超級陣列 vector
#define 一對 pair
#define 排隊 queue
#define 堆疊 stack
#define 管子 deque
#define 集合 set
#define 字典 map
#define 自動判斷 auto
#define 型態名 typename
#define 除錯 DBG
#define 啟動 using
#define 名稱空格 namespace
#define 假 false
#define 真 true
#define 設為 =
#define 是否為 ==
#define 小於 <
#define 大於 >
#define 小於等於 <=
#define 大於等於 >=
#define 加 +
#define 減 -
#define 乘 *
#define 除 /
#define 求餘 %
#define 算且 &
#define 算或 |
#define 算亦或 ^
#define 且 &
#define 或 |
#define 亦或 ^
#define 非 !
#define 減一 --
#define 加一 ++
#define 絕對值 abs
#define 記憶體設置 memset
#define 查大小 sizeof
#define 大小 size
#define 新增到最後面 push_back
#define 新增到最前面 push_front
#define 移除最後面 pop_back
#define 移除最前面 pop_front
#define 最後面 back
#define 最前面 front
#define 後指標 end
#define 前指標 begin
#define 下一次迴圈 continue
#define 離開迴圈 break
#define 最小值 min
#define 最大值 max

啟動 名稱空格 std;

#define 讀取(型態) 讀取器<型態>()


模板<型態名 某型態>某型態 讀取器(){
	某型態 想回傳的東西;
	輸入 >> 想回傳的東西;
	回傳 想回傳的東西;
}

主程式(){
	不會超時;
	長整數 計數器 設為 讀取(長整數);
	條件迴圈(計數器 減一){
		長整數 分量,數量;
		輸入>>數量>>分量;
		長整數 清單[數量 加 1];
		長整數 絕對值和[數量 加 1];
		長整數 絕對值和前綴和[數量 加 1];
		計數迴圈(
			長整數 計數器甲 設為 0;
			計數器甲 小於 數量;
			計數器甲 加一
		){
			輸入>>清單[計數器甲];
			如果(計數器甲){
				絕對值和[計數器甲] 設為 絕對值(清單[計數器甲] 減 清單[計數器甲 減 1]);
				絕對值和前綴和[計數器甲] 設為 絕對值和前綴和[計數器甲 減 1] 加 絕對值和[計數器甲];
			}否則{
				絕對值和[計數器甲] 設為 0;
				絕對值和前綴和[計數器甲] 設為 0;
			}
		}
		長整數 動態規劃[分量+1][數量+1];
		記憶體設置(動態規劃,0,查大小(動態規劃));
		計數迴圈(
			長整數 計數器乙 設為 1;
			計數器乙 小於 數量;
			計數器乙 加一
		){
			動態規劃[1][計數器乙] 設為 動態規劃[1][計數器乙 減 1] 加 絕對值和[計數器乙]; 
		}

		計數迴圈(
			長整數 計數器甲 設為 2;
			計數器甲 小於等於 分量;
			計數器甲 加一
		){
			計數迴圈(
				長整數 計數器乙 設為 1;
				計數器乙 小於 數量;
				計數器乙 加一
			){
				動態規劃[計數器甲][計數器乙] 設為 最小值( 動態規劃[計數器甲 減 1][計數器乙 減 1],動態規劃[計數器甲][計數器乙 減 1] 加 絕對值和[計數器乙]); 
			}
		}
		輸出 <<動態規劃[分量][數量 減 1]<< 換行 ;

	}
	回傳 0;
}
//#endif
