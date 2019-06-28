#include <iostream>
using namespace std;

int ext_euclidean(int a,int b,int& x,int& y) {
	/* a * x + b * y = gcd(a, b) */
	cout << "== CALL ==\n";
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int r = ext_euclidean(b, a % b, y, x);
    int t = x;
    y = y - a / b * t;
    return r;
}

int main(int argc, char const *argv[]) {
	int a, b, x, y;
	cin >> a >> b;
	int gcd = ext_euclidean(a, b, x, y);
	printf("(%d) * %d + (%d) * %d = %d\n", x, a, y, b, gcd);
	return 0;
}
