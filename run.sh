cpplint main.cpp
echo "### Compiling"
g++-4.8 -std=c++11 main.cpp -o main.out -g
echo "### Running"
./main.out
