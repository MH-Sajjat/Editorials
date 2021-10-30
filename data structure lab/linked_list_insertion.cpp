
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

void addBegin(int val) {
    Node* xNode = new Node(val);
    xNode->next = root;
    root = xNode;
}

void addEnd(int val) {
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

void addAfterPosition(int pos, int val) {
    Node* cur = root;
    while (pos > 1) {
        pos--;
        cur = cur->next;
    }
    Node* xNode = new Node(val);
    xNode->next = cur->next;
    cur->next = xNode;
}

void printList() {
    Node* cur = root;
    while (cur != NULL) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    addBegin(1);
    addBegin(2);
    addBegin(3);
    addEnd(5);
    addEnd(55);
    addAfterPosition(2, 100);
    printList();
    return 0;
}
