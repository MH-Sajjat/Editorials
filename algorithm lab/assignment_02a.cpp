#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> edge, spanEdge;
vector<int> par, rnk;

void precal(int n) {
    edge.clear();
    par.assign(n + 2, 0);
    rnk.assign(n + 2, 0);
    for (int i = 0; i < (n + 2); ++i) {
        par[i] = i;
    }
}

int root(int u) {
    return par[u] = par[u] == u ? u : root(par[u]);
}

bool merge(int a, int b) {
    int x = root(a), y = root(b);
    if (x == y) return 0;
    if (rnk[x] < rnk[y]) swap(x, y);
    par[y] = x;
    rnk[x] += rnk[y];
    return 1;
}

void spanningTree() {
    for (auto x : edge) {
        int u = x.first, v = x.second;
        if (merge(u, v)) {
            spanEdge.push_back({u, v});
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    int numNode, numEdge;
    cin >> numNode >> numEdge;
    precal(numNode);
    for (int i = 1; i <= numEdge; ++i) {
        int u, v;
        cin >> u >> v;
        edge.push_back({u, v});
    }
    spanningTree();
    cout << "Spanning Tree Edges: " << endl;
    for (auto x : spanEdge) cout << x.first << " <-> " << x.second << endl;
    return 0;
}
