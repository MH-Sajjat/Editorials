#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    } else if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* search(Node* root, int val) {
    if (root == NULL or root->val == val) return root;
    else if (val < root->val) return search(root->left, val);
    else return search(root->right, val);
}

vector<int> res;
void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    res.push_back(root->val);
    inOrder(root->right);
}

int main() {
    int n;
    cout << "Enter the number of element: ";
    cin >> n;
    Node* root = NULL;
    cout << "Enter the elements: ";
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    int findVal;
    cout << "Enter the search key: ";
    cin >> findVal;
    Node* find = search(root, findVal);
    if (find == NULL) {
        cout << "Search value not found." << endl;
    } else {
        cout << "Search value found." << endl;
    }

    inOrder(root);
    cout << "In-order traversal list: ";
    for (int i = 0; i < res.size(); ++i) cout << " " << res[i];
    cout << endl;
    return 0;
}
