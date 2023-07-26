# AT abc311E Defect-free Squares 題解
DP解：  
設$DP_{i,j}$為以$(i,j)$為正方形右下角，最大正方形可以到多大  
那要如何以$O(1)$的方式計算一個$DP_{i,j}$?  
我們已知$DP_{i-1,j-1}$的值，我們能確保$(i-DP_{i-1,j-1},j-DP_{i-1,j-1})$到$(i-1,j-1)$是空的  
代表左上方框是空的  
同理，我們可以用$DP_{i,j-1}$檢查左方框是空的...  
再加上自己這一格是空的  
答案就出來了：
$$
DP_{i,j}=
\begin{cases}
min(DP_{i-1,j},DP_{i,j-1},DP_{i-1,j-1}) & \quad mp_{i,j}=1 \\
0 & \quad mp_{i,j}=0
\end{cases}
$$
