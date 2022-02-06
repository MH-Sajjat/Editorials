#include <bits/stdc++.h>
using namespace std;

vector<pair<int, pair<int, int>>> edge;
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

int mstKruskal(int n) {
    sort(edge.begin(), edge.end());
    int cost = 0;
    for (auto x : edge) {
        int w = x.first, u = x.second.first, v = x.second.second;
        if (merge(u, v)) cost += w;
    }
    return cost;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int numNode, numEdge;
    cin >> numNode >> numEdge;
    precal(numNode);
    for (int i = 1; i <= numEdge; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({w, {u, v}});
    }
    cout << "Cost: " << mstKruskal(numEdge) << endl;
    return 0;
}
