#include <bits/stdc++.h>
using namespace std;

const int N = (int) 2e5 + 5;
vector<int> g[N];
vector<int> height(N, 0);

void dfs(int u, int h, int par = -1) {
    height[u] = h;
    for (auto v : g[u]) {
        if (v == par) continue;
        dfs(v, h + 1, u);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    int numNode;
    cin >> numNode;
    for (int i = 1; i < numNode; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int src;
    cin >> src;
    dfs(src, 0);
    for (int i = 1; i <= numNode; ++i) {
        cout << "Height of node " << i << " is " << height[i] << endl; 
    }
    return 0;
}
