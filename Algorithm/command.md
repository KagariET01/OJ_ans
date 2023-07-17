#git
> gh auth login		//set github

# CMD(powershell)
vim <file path>   //use vim open file path  
vim . <file_path_list> //use vim open file path  
Remove-Item '<file_path>	//remove file

# CMD(ubuntu)
> #檔案操作
> mkdir <new folder>		//create new folder
> rm <file_path>		//del file
> rm -v <file_path>		//del file ***FOREVER***
> touch <file_name>		//new file
> mv <path1> <path2>		//rename(or move) path1 to path2
> #磁碟空間
> df -H	[folder_path]		//check space of disk
> duf [path]			//check space of disk(sudo apt install duf)
> #用戶管理
> usermod -l <new_usrname> <old_usrname>	//change username
> groupmod -n <new_groupnme> <old_groupnme>	//change groupname
> groupadd <groupname>				//new group
> groupadd -g <group id> <groupname>		//new group && set group id

# vim
> i //插入模式
>> [esc]//退出
> v //選取模式  
>> y //複製
>> d //剪下
>>
> p //在游標後面貼上
> P //在游標前面貼上
> : //命令模式
>> w //寫入
>> q //退出
>> wq //寫入並退出
>> split //水平分割視窗
>> sp		//同上
>> vsplit //垂直分割視窗
>> close //關閉此視窗
>> only //關閉其他視窗 同[Ctrl]+[w] [o]
>> qall //關閉所有視窗 非退出
>> wall //儲存所有視窗的檔案
>> wqall //儲存並關閉所有視窗 非退出
>> tabe //新頁籤
>> tabs //查看所有頁籤
>> tabn //下一個頁籤 or [g] [t]
>> tabp //上一個頁籤 or [g] [T]
>>
> [Ctrl]+[w] //分割視窗管理
>> hjkl //將游標移動到左、下、上、右的分割視窗
>> [Ctrl]+[w] //切換分割視窗
>> + //增加高度
>> - //減少高度
>> > //增加寬度
>> < //減少寬度
>> o //關閉其他視窗 同[:] [only]



# vim初見
> [i]		//插入模式
> [esc]		//退出目前模式
> [x][x]	//(初始模式)刪除該行
> :{num}	//跳到第{num}行
> u		//上一步
> :>		//縮排1排
> ## 選取
> [v]		//選取模式
>> [y]		//複製
>> [d]		//剪下
> [p]		//在游標後面貼上
> [P]		//在游標前面貼上
> ## 存檔
> :w		//寫入
> :q		//退出
> :wq		//寫入並退出
> wall		//儲存所有檔案
> qall		//關閉所有檔案，非退出
> ## 頁籤
> :tabe //建立新頁籤
> :tabs //查看所有頁籤
> :tabn //下一個頁籤
> [g][t] //下一個頁籤
> :tabp //上一個頁籤
> [g][T] //上一個頁籤
> ## 分割畫面
> :split //水平分割畫面
> :sp		//同上
> :vsplit //垂直分割畫面
> :vsp		//同上
> [Ctrl]+[w] [Ctrl]+[w] //切換分割視窗
> [Ctrl]+[w] [hjkl] //切換分割視窗
> [Ctrl]+[w] [+-] //調整分割視窗高度
> [Ctrl]+[w] [><] //調整分割視窗寬度
> ## 顯示
> :set nu!		//顯示行數(只在此顯示)
> ## 檔案總管
> :Explore	//開啟檔案總管
> [F1]		//幫助
> i		//切換檢視模式
> d		//新建目錄
> %		//新建文件
> D		//刪除
> R		//重新命名
> t		//在新分頁中開啟
> p		//預覽文件
> qf		//顯示文件信息
> mb		//將當前目錄加入書籤
> mB		//取消書籤
> 

# vim settings
> ~/_vimrc	//此為檔案路徑
> syntax on	//語法凸顯
> set t_Co=256	//設定256色 
> set number	//顯示行數
> set background=dark		//終端機顏色(dark/light)
> set ts=2	//縮排=2
> set expandtab			//tab替換成space
> set smartindent		//自動縮排(autoindent / smartindent / cindent)
> set backspace=indent,eol,start  //退格行為(一定要設，這樣按[backspace]才能刪除換行)


# c++
> string
>> find()	//尋找
>> substr()	//取得子字串
>> string::npos	//當find沒找到東西時會回傳這個東東 
