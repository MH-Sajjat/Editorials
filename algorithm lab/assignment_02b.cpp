#include <bits/stdc++.h>
using namespace std;

const int N = (int) 2e5 + 5;
vector<int> g[N];
vector<bool> vis(N, 0);

map<pair<int, int>, bool> m;

bool isNotCycle(int u, int par = -1) {
    vis[u] = true;
    for (auto& v : g[u]) {
        if (v == par or v == -1) continue;
        else if (vis[v]) {
            m[{u, v}] = 0;
            v = -1;
            return false;
        } else {
            if (!isNotCycle(v, u)) return false;
        }
    }
    return true;
}


int main() {
    // freopen("input.txt", "r", stdin);
    int numNode, numEdge;
    cin >> numNode >> numEdge;
    vector<pair<int, int>> edge;
    for (int i = 1; i <= numEdge; ++i) {
        int u, v;
        cin >> u >> v;
        m[{u, v}] = 1;
        edge.push_back({u, v});
        g[u].push_back(v);
        g[v].push_back(u);
    }

    while (1) {
        if (isNotCycle(1)) break;
        vis.assign(N, 0);
    }

    cout << "Spanning Tree Edges: " << endl;
    
    for (auto x : edge) {
        if (m[x] == true) cout << x.first << " <-> " << x.second << endl;
    }

    return 0;
}
