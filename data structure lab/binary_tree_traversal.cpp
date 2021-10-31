#include <bits/stdc++.h>
using namespace std;

const int N = (int) 2e5 + 5;

pair<int, int> g[N];
vector<int> res;

void preOrder(int root) {
    if (root == -1) return;
    res.push_back(root);
    preOrder(g[root].first);
    preOrder(g[root].second);
}

void postOrder(int root) {
    if (root == -1) return;
    postOrder(g[root].first);
    postOrder(g[root].second);
    res.push_back(root);
}

void InOrder(int root) {
    if (root == -1) return;
    InOrder(g[root].first);
    res.push_back(root);
    InOrder(g[root].second);
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the child of a node in format [left child] [right child] in order of 1, 2, 3.." << endl;
    cout << "For no child enter -1" << endl;
    for (int i = 1; i <= n; ++i) {
        int l, r;
        cin >> l >> r;
        g[i] = {l, r};
    }
    int root;
    cout << "Enter the root: ";
    cin >> root;
    
    preOrder(root);
    cout << "Pre-Order: " << res[0];
    for (int i = 1; i < res.size(); ++i) {
        cout << " -> " << res[i];
    }
    cout << endl;
    res.clear();

    postOrder(root);
    cout << "Post-Order: " << res[0];
    for (int i = 1; i < res.size(); ++i) {
        cout << " -> " << res[i];
    }
    cout << endl;
    res.clear();

    InOrder(root);
    cout << "In-Order: " << res[0];
    for (int i = 1; i < res.size(); ++i) {
        cout << " -> " << res[i];
    }
    cout << endl;

    return 0;
}
