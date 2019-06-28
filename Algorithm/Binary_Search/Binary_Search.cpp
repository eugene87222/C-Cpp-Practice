#include <bits/stdc++.h>
using namespace std;
#define N 10

int BinarySearch(int *A, int x, int left, int right) {
    if(left <= right) {
        int middle = (left + right) / 2;
        if(x < A[middle]) return BinarySearch(A, x, left, middle - 1);
        if(x > A[middle]) return BinarySearch(A, x, middle + 1, right);
        if(x == A[middle]) return middle;
    }
    return -1 ;
}

int main() {
    int index, n1, DATA[N];
   	cout << "Input 10 integers:" << endl;
    for(n1 = 0; n1 < N; n1++)
        cin >> DATA[n1];
    sort(DATA, DATA+N);
    cout << "After sort: ";
    for(n1 = 0; n1 < N; n1++)
        cout << DATA[n1] << ' ';
    cout << endl;
    cout << "Input the searched element: ";
    cin >> n1;
    index = BinarySearch(DATA, n1, 0, N - 1);
    printf("The index of the searched element x is at %d.", index);

    return 0;
}
