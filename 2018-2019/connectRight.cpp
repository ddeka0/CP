#include <bits/stdc++.h>
using namespace std;
struct Node {
	int value;
	Node *left;
	Node *right;
	Node *nextRight;
	Node(int x) : value(x), left(nullptr), right(nullptr), nextRight(nullptr){}
};
void connect(Node *root) {
	queue<Node*> Q;
	Q.push(root);
	Q.push(nullptr);
	while(!Q.empty()) {
		Node * p = Q.front();
		Q.pop();
		if (p != nullptr) {
			p->nextRight = Q.front();
			if (Q.front() != nullptr) {
				cout << p->value << " is connected to " << Q.front()->value << endl;
			}
			else {
				cout << p->value << " is connected to null"<< endl;
			}
			if (p->left != nullptr)
				Q.push(p->left);
			if (p->right != nullptr)
				Q.push(p->right);
		}
		else if (!Q.empty()) {
			Q.push(nullptr);
		}
	}
}
int main() {
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	connect(root);
}