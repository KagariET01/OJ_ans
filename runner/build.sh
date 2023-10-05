echo ""
echo ""
echo ""
echo ""
echo ""
rm run
rm 01.out
g++ -o run main.cpp
./run < 01.in > 01.out
echo "=====input================="
strings -n 1 "01.in"
echo "=====output================"
strings -n 1 "01.out"
echo "=====ans==================="
strings -n 1 "01.ans"
#echo "=====time=================="
#date +"start time: %y/%m/%d %T"
#date +"end time:   %y/%m/%d %T"
#echo "=====checker==============="
#./checker 01.out 01.ans
echo "==========================="



