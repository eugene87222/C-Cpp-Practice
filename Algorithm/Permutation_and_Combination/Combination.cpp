#include <iostream>
using namespace std;

int Cnm(int n, int m) {
    if(m == 0 || m == n) {
        return 1;
    } else {
        return Cnm(n - 1, m) + Cnm(n - 1, m - 1);
    }
}

int main() {
    cout << "C(n, m)\nInput n, m: ";
    int n, m;
    cin >> n >> m;
    cout << Cnm(n, m) << endl;
    return 0;
}