#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > g;
vector<int> parent;

bool BFS(int s, int t) {
    vector<int> visit(6, 0);
    parent = vector<int>(6, -1);
    visit[s] = 1;
    queue<int> q;
    q.push(s);
    while(q.size()) {
        int u = q.front();
        q.pop();
        for(int i=0; i<6; ++i) {
            if(g[u][i] != 0 && !visit[i]) {
                q.push(i);
                visit[i] = 1;
                parent[i] = u;
            }
        }
    }
    return visit[t] == 1;
}

int min_c(int t) {
    int _min = 10000;
    for(int i=t; parent[i]!=-1; i=parent[i]) {
        if(g[parent[i]][i] < _min) {
            _min = g[parent[i]][i];
        }
    }
    return _min;
}

void ford_fulkerson(int s, int t) {
    int max_flow = 0;
    while(BFS(s, t)) {
        int _min = min_c(t);
        max_flow += _min;
        for(int i=t; i!=s; i=parent[i]) {
            g[parent[i]][i] -= _min;
            g[i][parent[i]] += _min;
        }
    }
    cout << max_flow << endl;
}

void add_edge(int u, int v, int c) {
    g[u][v] = c;
}

int main() {
    g = vector<vector<int> >(6, vector<int>(6, 0));

    add_edge(0, 1, 9);
    add_edge(0, 3, 9);
    add_edge(1, 2, 3);
    add_edge(1, 3, 8);
    add_edge(2, 4, 2);
    add_edge(2, 5, 9);
    add_edge(3, 2, 7);
    add_edge(3, 4, 7);
    add_edge(4, 2, 4);
    add_edge(4, 5, 8);

    ford_fulkerson(0, 5);

    return 0;
}