#include <bits/stdc++.h>
using namespace std;

/* Permutation and Combination (lexicographic) */
int N = 4;
vector<int> seq;

void perm(int idx) {
    if(idx == N) {
        for(int i = 0; i < N; i++) {
            cout << seq[i] << " ";
        }
        cout << "\n";
    } else {
        for(int i = idx; i < N; i++) {
            swap(seq[idx], seq[i]);
            perm(idx + 1);
            swap(seq[idx], seq[i]);
        }
    }
}

int main(int argc, char const *argv[]) {
    for(int i = 0; i < N; i++) {
        seq.push_back(i + 1);
    }
    perm(0);
    return 0;
}