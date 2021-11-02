#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e6 + 6;
vector<int> g[N];
vector<bool> vis(N + 2, 0);
vector<int> dis(N + 2, 0);

void bfs(int src) {
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = 1;
                dis[v] = dis[u] + 1;
            }
        }
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
    bfs(src);
    cout << "Distance from source to others vertices:" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << "source to " << i << " = " << dis[i] << endl;
    }
    return 0;
}
