#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e6 + 6;
vector<int> g[N];
vector<bool> vis(N + 2, 0);

void dfs(int u) {
    if (vis[u]) return;
    cout << u << " ";
    vis[u] = 1;
    for (auto v : g[u]) {
        if (!vis[v]) dfs(v);
    }
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edge: ";
    cin >> m;
    cout << "Enter the edge in form [vertix 1] [vertix 2]: " << endl;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int src;
    cout << "Enter the source vertix: ";
    cin >> src;
    cout << "Graph traversing order: ";
    dfs(src);
    cout << endl;
    return 0;
}
