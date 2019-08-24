#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstdio>
using namespace std;

int BinarySearch(vector<int>& vec, int target, int left, int right) {
    if(left <= right) {
        int mid = (left + right) / 2;
        if(target < vec[mid]) return BinarySearch(vec, target, left, mid - 1);
        if(target > vec[mid]) return BinarySearch(vec, target, mid + 1, right);
        if(target == vec[mid]) return mid;
    }
    return -1 ;
}

void PrintVec(vector<int>& vec) {
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");
}

int main() {
    /* test.in
    10 <- number of elements
    1 5 6 8 2 4 6 9 2 3 <- each elements
    1 5 3 ... <- searching targets
    */
    ifstream input_file;
    int length, target;
    vector<int> vec;

    input_file.open("test.in", ifstream::in);
    input_file >> length;
    vec = vector<int>(length);

    for(int i = 0; i < length; i++) {
        input_file >> vec[i];
    }
    sort(vec.begin(), vec.end());
    PrintVec(vec);
    while(input_file >> target) {
        printf("The index of %d is at %d.\n", 
            target, BinarySearch(vec, target, 0, length - 1));
    }
    return 0;
}
