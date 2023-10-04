rm run
rm 01.out
g++ -o run main.cpp
echo "輸入檔================="
strings -n 1 "01.in"
echo "輸出檔================="
./run -Dev < 01.in
./run -Dev < 01.in > 01.out
echo "======================"