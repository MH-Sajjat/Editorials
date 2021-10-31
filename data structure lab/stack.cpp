#include <bits/stdc++.h>
using namespace std;

class Stack {
	struct Node {
		int val;
		Node* next;
		Node(int x) {
			val = x;
			next = NULL;
		}
	};
	Node* topRoot = NULL;
public:
	Stack() {
		topRoot = NULL;
	}

	void push(int x) {
		Node* newNode = new Node(x);
		newNode->next = topRoot;
		topRoot = newNode;
	}

	int top() {
		return topRoot->val;
	}

	void pop() {
		Node* temp = topRoot;
		topRoot = topRoot->next;
		delete(temp);
	}
};

int main() {
	Stack st;
	st.push(5);
	st.push(4);
	st.push(2);
	st.push(55);
	st.pop();
	st.pop();
	cout << st.top() << endl;
	return 0;
}
