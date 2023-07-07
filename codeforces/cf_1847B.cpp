/*
[q]https://kagariet01.github.io/swap/?OJ=cf&C=1847&P=B
[bit運算]
[]
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
#define 等於 ==
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
		長整數 數量 設為 讀取(長整數);
		長整數 答案 設為 0;
		長整數 現在 設為 0;
		條件迴圈(數量 減一){
			如果(現在 等於 0){
				現在 設為 讀取(長整數);
				答案 加一;
			}否則{
				現在 設為 現在 算且 讀取(長整數);
			}
		}
		如果 (現在 大於 0)答案 減一;
		如果 (非 答案)答案 設為 1;
		輸出<<答案<<換行;
	}
	回傳 0;
}
//#endif
