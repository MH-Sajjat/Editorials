#include <bits/stdc++.h>
using namespace std;

template <typename T> class Stack {
    struct Node {
        T val;
        Node* next;
        Node(T x) {
            val = x;
            next = NULL;
        }
    };
    Node* topRoot = NULL;
    int sz = 0;

public:
    Stack() {
        topRoot = NULL;
    }

    void push(T x) {
        Node* newNode = new Node(x);
        newNode->next = topRoot;
        topRoot = newNode;
        sz++;
    }

    bool isEmpty() {
        if (sz) return 1;
        return 0;
    }

    T top() {
        if (sz == 0) {
            cout << "stack is empty" << endl;
            return -1;
        }
        return topRoot->val;
    }

    void pop() {
        if (sz == 0) {
            cout << "stack is empty" << endl;
            return;
        }
        Node* temp = topRoot;
        topRoot = topRoot->next;
        delete(temp);
        sz--;
    }
};

int main() {
    Stack<int> st;
    st.push(5);
    st.push(4);
    st.push(2);
    st.push(55);
    st.pop();
    st.pop();
    cout << st.top() << endl;
    return 0;
}
