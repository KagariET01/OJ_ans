rm run
rm 01.out
g++ -o run main.cpp
echo "輸入檔================="
strings "01.in"
echo "輸出檔================="
./run < 01.in
echo "======================"