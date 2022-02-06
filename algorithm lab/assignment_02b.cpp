#include <bits/stdc++.h>
using namespace std;

const int N = (int) 2e5 + 5;
vector<pair<int, int>> g[N];
vector<bool> vis(N, 0);

int mstPrims(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    int cost = 0;
    while (!pq.empty()) {
        int u = pq.top().second, w = pq.top().first;
        pq.pop();
        if (vis[u]) continue;
        cost += w;
        vis[u] = 1;
        for (auto x : g[u]) {
            int v = x.second, wt = x.first;
            if (!vis[v]) pq.push({wt, v});
        }
    }
    return cost;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int numNode, numEdge;
    cin >> numNode >> numEdge;
    for (int i = 1; i <= numEdge; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
    cout << "Cost: " << mstPrims(1) << endl;
    return 0;
}
