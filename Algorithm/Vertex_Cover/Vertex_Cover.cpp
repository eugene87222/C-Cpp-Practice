#include <iostream>
#include <vector>

using namespace std;

int N = 7;
vector<vector<int>> G(N);

void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

void vertex_cover() {
    vector<bool> visited(N, false);
    for(int u = 0; u < N; u++) {
        if(!visited[u]) {
            for(vector<int>::iterator i = G[u].begin(); i != G[u].end(); i++) {
                if(!visited[*i]) {
                    visited[u] = true;
                    visited[*i] = true;
                    cout << "(" << u << ", " << *i << ")\n";
                    break;
                }
            }
        }
    }
}

int main() {
    add_edge(0, 1); 
    add_edge(0, 2); 
    add_edge(1, 3); 
    add_edge(3, 4); 
    add_edge(4, 5); 
    add_edge(5, 6); 
    vertex_cover();
    return 0;
}