
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

void delBegin() {
    Node* temp = root;
    root = root->next;
    delete(temp);
}

void delEnd() {
    if (root->next == NULL) {
        Node* temp = root;
        root = NULL;
        delete(temp);
    } else {
        Node* cur = root;
        Node* pre;
        while (cur->next != NULL) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = NULL;
        delete(cur);
    }
}

void delatPos(int pos) {
    if (pos == 1) {
        Node* temp = root;
        root = root->next;
        delete(temp);
    }
    Node* cur = root;
    while (pos > 2) {
        cur = cur->next;
        pos--;
    }
    Node* temp = cur->next;
    cur->next = cur->next->next;
    delete(temp);
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
    add(1);
    add(2);
    add(3);
    add(4);
    add(5);
    delatPos(5);
    printList();
    return 0;
}
