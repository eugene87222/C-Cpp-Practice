#include <climits>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
/*
 	F(y) + m = n
 	F(y + 1) >= n + 1
	(F(y) <= n + 1)
 	x = y - 1
 	(n = length of array)
*/

void CreateFibonacci(vector<int>& Fib, int length) {
    Fib[0] = 0;
    Fib[1] = 1;
    for(int i = 2; i < length; i++) {
        Fib[i] = Fib[i - 1] + Fib[i - 2];
    }
}

int FindY(const vector<int>& Fib, int n) {
    int i = 0;
    while(Fib[i] <= n) i++;
    i--;
    return i;
}

int FibonacciSearch(vector<int>& number, int length, int find) {
    vector<int> fib(length, INT_MIN);
    CreateFibonacci(fib, length); 
    int y = FindY(fib, length + 1);
    int m = length - fib[y];
    int x = y - 1;
    int i = x;
    if(number[i] < find)
        i += m;
    int result = -1;
    while(fib[x] > 0) { 
        if(number[i] < find) 
            i += fib[--x]; 
        else if(number[i] > find) 
            i -= fib[--x];
        else {
            result = i;
            break;
        }
    }
    return result;
}

int main(int argc, char const *argv[]) {
    /* test.in
    5 <- length of array
    1 3 5 7 9 <- each element
    7 <- searching target
    */
    int length;
    int find;

    ifstream input_file;
    input_file.open("test.in", fstream::in);
    input_file >> length;
    vector<int> number(length);
    for(int i = 0; i < length; i++) 
        input_file >> number[i];
    input_file >> find;
    int idx = FibonacciSearch(number, length, find);
    if(idx >= 0) {
        cout << "index: " << idx << endl;
    }
    else {
        cout << "cannot find the number" << endl;
    }
	return 0;
}
