#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class edge {
public:
    int u, v, w;
    edge(): u(0), v(0), w(0) {}
    edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}
};

class cmp {
public:
    bool operator ()(edge& a, edge& b) {
        return a.w > b.w;
    }
};

priority_queue<edge, vector<edge>, cmp> g;
vector<int> group;
vector<edge> edges;
int edge_cnt;

void add_edge(int u, int v, int w) {
    g.push(edge(u, v, w));
}

int find_group(int u) {
    if(group[u] != u) {
        group[u] = find_group(group[u]);
    }
    return group[u];
}

void union_group(int u, int v) {
    int g_u = find_group(u);
    int g_v = find_group(v);
    if(g_u != g_v) {
        group[v] = g_u;
    }
}

void Kruskal() {
    while(edge_cnt < 6 && g.size()) {
        int u = g.top().u;
        int v = g.top().v;
        int w = g.top().w;
        int g_u = find_group(u);
        int g_v = find_group(v);
        g.pop();
        if(g_u != g_v) {
            union_group(u, v);
            edges.push_back(edge(u, v, w));
            ++edge_cnt;
        }
    }
}

int main() {
    group = vector<int>(6);
    for(int i=0; i<6; ++i) {
        group[i] = i;
    }

    add_edge(0, 1, 1);
    add_edge(0, 2, 5);
    add_edge(0, 4, 5);
    add_edge(0, 5, 4);
    add_edge(1, 2, 7);
    add_edge(1, 3, 5);
    add_edge(1, 5, 3);
    add_edge(2, 3, 6);
    add_edge(2, 4, 2);

    edge_cnt = 0;

    Kruskal();

    // for(int i=0; i<6; ++i) {
    //     cout << i << ": " << group[i] << endl;
    // }
    // cout << endl;
    for(int i=0; i<edges.size(); ++i) {
        cout << edges[i].u << " " << edges[i].v << " " <<edges[i].w << endl;
    }

    return 0;
}