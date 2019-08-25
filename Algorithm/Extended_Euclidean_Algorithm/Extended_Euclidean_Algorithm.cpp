#include <iostream>
#include <fstream>
using namespace std;

int ExtEuclidean(int a,int b,int& x,int& y) {
	/* a * x + b * y = gcd(a, b) */
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int r = ExtEuclidean(b, a % b, y, x);
    int t = x;
    y = y - a / b * t;
    return r;
}

int main(int argc, char const *argv[]) {
	int a, b, x, y;
    ifstream input_file;
    input_file.open("test.in", fstream::in);
	input_file >> a >> b;
	int gcd = ExtEuclidean(a, b, x, y);
	printf("(%d) * %d + (%d) * %d = %d\n", x, a, y, b, gcd);
	return 0;
}
