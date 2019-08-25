#include <bits/stdc++.h>
using namespace std;

#define MAX 20

void generate(int *set, int idx, int len){
    if(idx == len) {
        cout << "[";
        for(int i = 0; i < len; i++) {
            if(set[i]) {
                if(i) cout << " ";
                cout << i + 1;
            }
        }
        cout << "]" << endl;
        return;
    }
    else{
        set[idx] = 0;
        generate(set, idx + 1, len);
        set[idx] = 1;
        generate(set, idx + 1, len);
    }
}

int main(int argc, char const *argv[]) {
    int n, set[MAX];
    cin >> n;
    generate(set, 0, n);
    return 0; 
}