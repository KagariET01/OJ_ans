# NEOJ 125 逆序數對 題解
這題很明顯是分治，~~因為這禮拜就是教分治~~<br>
基礎原理這邊就不詳解了，看code先

```c++
void solve(INT l,INT r){
	//區塊1
	DBG cerr<<"l="<<l<<" r="<<r<<endl;
	if(r-l<=1)return;
	INT mnt=(l+r)/2;//l區的右界(不包含)，r區的左界(包含)
	solve(l,mnt);
	solve(mnt,r);
	//區塊2
	for(INT i=l;i<r;i++){//前綴和
		vecadd[i]=vecadd[i-1]+vec[i];
	}
	//區塊3
	INT lit=l,rit=mnt,ind=0,temp[r-l];
	//nl=左指標,nr=右指標,ind=目前temp的.endl(),temp為排序後的list
	for(;lit<mnt;lit++){//move lit
		while(rit<r && vec[rit]<vec[lit]){
			INT tme=mnt-lit;
			re+=vecadd[mnt-1]-vecadd[lit-1];
			re%=mod;
			re+=vec[rit]*tme%mod;
			re%=mod;
			temp[ind]=vec[rit];
			ind++;
			rit++;
		}
		temp[ind]=vec[lit];
		ind++;
	}
	while(rit<r){
		temp[ind]=vec[rit];
		rit++;
		ind++;
	}
	//區塊4
	for(int i=0;i<r-l;i++){
		vec[i+l]=temp[i];
	}
	re%=mod;
}
```
為了加快大家的查閱速度，這邊給一個傳送門<br>

> [區塊1](#區塊1)\
> [區塊2](#區塊2)\
> [區塊3](#區塊3)\
> [區塊4](#區塊4)

## 區塊1
```c++
//區塊1
DBG cerr<<"l="<<l<<" r="<<r<<endl;
if(r-l<=1)return;
INT mnt=(l+r)/2;//l區的右界(不包含)，r區的左界(包含)
solve(l,mnt);
solve(mnt,r);
```
這邊很明顯是進行dfs(?)<br>
小的先做，再做大的

## 區塊2
```c++
//區塊2
for(INT i=l;i<r;i++){//前綴和
	vecadd[i]=vecadd[i-1]+vec[i];
}
```
這邊再重新計算前綴和<br>
為甚麼不一開始就先算ㄋ?<br>
因為我每次跑solve時，vec都會被我們重新排列一次<br>
當然的，前綴和也要重算一次<br>
這部份很重要歐，因為我就被這東東吃了很多挖

## 區塊3
```c++
//區塊3
INT lit=l,rit=mnt,ind=0,temp[r-l];
//nl=左指標,nr=右指標,ind=目前temp的.endl(),temp為排序後的list
for(;lit<mnt;lit++){//move lit
	while(rit<r && vec[rit]<vec[lit]){
		INT tme=mnt-lit;
		re+=vecadd[mnt-1]-vecadd[lit-1];
		re%=mod;
		re+=vec[rit]*tme%mod;
		re%=mod;
		temp[ind]=vec[rit];
		ind++;
		rit++;
	}
	temp[ind]=vec[lit];
	ind++;
}
while(rit<r){
	temp[ind]=vec[rit];
	rit++;
	ind++;
}
```
這邊應該就是分治的精隨了<br>
先給荔枝
**2** 4 6 8,**1** 3 5 7
粗體字為目前lit和rit所在位置<br>
我們可以發現，除了2，左子集中的4,6,8也可以和1做逆序數對<br>
那照道理，我們是不是要把2,4,6,8全部加起來<br>
這時候就要用到剛剛的前綴和了<br>
那答案就是這行code拉：`re+=vecadd[mnt-1]-vecadd[lit-1];`<br>
既然2,4,6,8都可以和1配，那1是不是也要+4次<br>
正確，code在此：```INT tme=mnt-lit;```和```re+=vec[rit]*tme%mod;```<br>
然後剩下的code就是迭代器，sort，...

## 區塊4
```c++
for(int i=0;i<r-l;i++){
	vec[i+l]=temp[i];
}
re%=mod;
```
也沒什麼好講的，就是把剛剛merge好的東西推入vec裡罷了

這是我第一次打這種題解，有任何問題歡迎到issues發問