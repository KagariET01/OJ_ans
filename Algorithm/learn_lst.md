# Algorithm 學習資料庫

這邊主要會放一些奇奇怪怪的演算法<br>
[目次]

> [std 模板](#std)

> ## std
>
> > [tuple](#tuple)

### tuple

知不知道 pair?來個 pair 的 ex<br>
[code]

```c++
#include<bits/stdc++.h>
using namespace std;
int main(){
	pair<int,int> a;
	a.first=1;
	a.second=1;
	return 0;
}
```

pair 可以一次儲存兩個數值，你甚至可以用 pair 進行比大小
但對，你只能存兩個值。
tuple 就要來解決這件事啦！<br>
[code]

```c++
#include <tuple>
#include <iostream>
#include <string>
#include <stdexcept>

std::tuple<double, char, std::string> get_student(int id)//類似cin，但這邊用fn來代替
{
	if (id == 0) return std::make_tuple(3.8, 'A', "Lisa Simpson");
	if (id == 1) return std::make_tuple(2.9, 'C', "Milhouse Van Houten");
	if (id == 2) return std::make_tuple(1.7, 'D', "Ralph Wiggum");
	throw std::invalid_argument("id");
}

int main()
{
	auto student0 = get_student(0);
	std::cout << "ID: 0, "
						<< "GPA: " << std::get<0>(student0) << ", "//std::get<i>(n) 取tuple n第i個值
						<< "grade: " << std::get<1>(student0) << ", "
						<< "name: " << std::get<2>(student0) << '\n';

	double gpa1;
	char grade1;
	std::string name1;
	std::tie(gpa1, grade1, name1) = get_student(1);
	std::cout << "ID: 1, "
						<< "GPA: " << gpa1 << ", "
						<< "grade: " << grade1 << ", "
						<< "name: " << name1 << '\n';
}
```

tuple 一次可以存 3+個值，也可以互相比大小
