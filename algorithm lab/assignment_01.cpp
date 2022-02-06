#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
vector<bool> vis(N, 0);
vector<pair<int, int>> treeEdge, backEdge, forwardEdge, crossEdge;
vector<int> startTime(N, 0), endTime(N, 0);
int Time = 0;

void dfs(int u) {
    vis[u] = 1;
    startTime[u] = ++Time;
    for (auto v : g[u]) {
        if (!vis[v]) {
            treeEdge.push_back({u, v});
            dfs(v);
        }
    }
    endTime[u] = ++Time;
}

void dfs1(int u) {
    vis[u] = 1;
    for (auto v : g[u]) {
        if (vis[v]) {
            if (startTime[u] > startTime[v] and endTime[u] < endTime[v]) backEdge.push_back({u, v});
            else if (startTime[u] < startTime[v] and endTime[u] > endTime[v]) forwardEdge.push_back({u, v});
            else crossEdge.push_back({u, v});
        } else dfs1(v);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    int numNode, numEdge;
    cin >> numNode >> numEdge;
    for (int i = 1; i <= numEdge; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= numNode; ++i) {
        if (!vis[i]) dfs(i);
    }
    vis.assign(N, 0);
    for (int i = 1; i <= numNode; ++i) {
        if (!vis[i]) dfs1(i);
    }
    cout << "Tree Edge: " << endl;
    for (auto x : treeEdge) cout << x.first << " " << x.second << endl;
    cout << "Forward Edge: " << endl;
    for (auto x : forwardEdge) cout << x.first << " " << x.second << endl;
    cout << "Back Edge: " << endl;
    for (auto x : backEdge) cout << x.first << " " << x.second << endl;
    cout << "Cross Edge " << endl;
    for (auto x : crossEdge) cout << x.first << " " << x.second << endl;
    return 0;
}
