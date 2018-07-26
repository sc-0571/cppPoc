rm -f ./test
gcc ktransaction.cpp -o test -lstdc++ -std=c++11
if [ $? == 0 ] 
then 
  ./test
fi
