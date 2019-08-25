#include <bits/stdc++.h>
using namespace std;

/* Permutation and Combination (lexicographic) */
int N = 4;

void copy(int *from, int *to) {
    int i;
    for(i = 0; i < N; i++)
        to[i] = from[i];
}

void rotate(int *num, int i, int j) {
    int tmp = num[j];
    for(int k = j; k > i; k--)
        num[k] = num[k - 1];
    num[i] = tmp;
}

void print(int *num) {
    int i;
    for(i = 0; i < N; i++)
    	cout << num[i] << " "; 
    cout << endl;
}

void perm(int *num, int i) {
    if(i < N) {
        for(int j = i; j < N; j++) {
            int to[N];
            copy(num, to);
            rotate(to, i, j);
            perm(to, i + 1); 
        } 
    }
    else print(num);
}

int main(int argc, char const *argv[]) {
	int num[N];
	for(int i = 0; i < N; i++)
		num[i] = i + 1;
    perm(num, 0);
    return 0;
}