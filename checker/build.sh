echo "輸入檔產生中"
g++ -o run cin.cpp
./run > 01.in
echo "輸出檔產生中"
g++ -o run cout.cpp
./run < 01.in > 01.out
echo "答案產生中"
g++ -o run ans.cpp
./run < 01.in > 01.ans
echo "執行成功"