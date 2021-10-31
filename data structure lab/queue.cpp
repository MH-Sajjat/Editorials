#include <bits/stdc++.h>
using namespace std;

template<typename T> class Queue {
    struct Node {
        T val;
        Node* next;
        Node(int x) {
            val = x;
            next = NULL;
        }
    };
    int sz;
    Node* first;
    Node* last;

public:
    Queue() {
        sz = 0;
        first = last = NULL;
    }

    void push(int val) {
        if (first == NULL) {
            first = new Node(val);
            last = first;
        } else {
            Node* newNode = new Node(val);
            last->next = newNode;
            last = newNode;
        }
        sz++;
    }

    T front() {
        if (sz == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return first->val;
    }

    void pop() {
        if (sz == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = first;
        first = first->next;
        delete(temp);
        sz--;
    }

    bool isEmpty() {
        if (sz == 0) return 0;
        return 1;
    }

    int size() {
        return sz;
    }
};

int main() {
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.pop();
    cout << "Size: " << q.size() << endl;
    if (q.front() != -1)
        cout << "Front element: " << q.front() << endl;
    return 0;
}
