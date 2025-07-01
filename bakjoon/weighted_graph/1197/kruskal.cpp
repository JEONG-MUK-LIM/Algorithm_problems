#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    parent[y] = x;
    return true;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<Edge> edges(e);
    parent.resize(v + 1);
    for (int i = 0; i <= v; ++i) parent[i] = i;

    for (int i = 0; i < e; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges.begin(), edges.end());

    int mst_weight = 0, count = 0;
    for (const auto& edge : edges) {
        if (unite(edge.u, edge.v)) {
            mst_weight += edge.w;
            count++;
            if (count == v - 1) break;
        }
    }
    cout << mst_weight << '\n';
    return 0;
}