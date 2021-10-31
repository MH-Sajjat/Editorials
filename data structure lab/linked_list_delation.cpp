
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
int sz = 0;

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
    sz++;
}

void delAtPosition(int pos) {
    if (sz == 0) {
        cout << "List is empty" << endl;
    } else if (pos > sz or pos < 1) {
        cout << "Index does not exist" << endl;
    } else if (pos == 1) {
        Node* temp = root;
        root = root->next;
        delete(temp);
    } else if (sz == 1) {
        Node* temp = root;
        root = root->next;
        delete(temp);
    } else {
        Node* cur = root;
        Node* pre = NULL;
        while (pos > 1) {
            pre = cur;
            cur = cur->next;
            pos--;
        }
        pre->next = cur->next;
        delete(cur);
    }
}

void printList() {
    cout << "Final list elements:";
    Node* cur = root;
    while (cur != NULL) {
        printf(" %d", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    cout << "Enter number of element: ";
    int n;
    cin >> n;
    cout << "Enter list element: ";
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        add(x);
    }
    int pos;
    cout << "Enter deletion position: ";
    cin >> pos;
    delAtPosition(pos);
    printList();
    return 0;
}
