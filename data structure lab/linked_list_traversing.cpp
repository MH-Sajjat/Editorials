
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        next = NULL;
    }
} *root = NULL;

void add(int val) {
    if (root == NULL) {
        root = new Node(val);
    } else {
        Node* cur = root;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        Node* xNode = new Node(val);
        cur->next = xNode;
    }
}


bool search(int val) {
    Node* cur = root;
    while (cur != NULL) {
        if (cur->val == val) return 1;
        cur = cur->next;
    }
    return 0;
}

int main() {
    int n;
    cout << "Enter number of element: ";
    cin >> n;
    cout << "Enter list elements: ";
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        add(x);
    }
    int val;
    cout << "Enter search value: ";
    cin >> val;
    if (search(val)) cout << "Found" << endl;
    else cout << "Not Found" << endl;
    return 0;
}
