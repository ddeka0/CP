#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Node {
public:
	int value;
	Node *next;
	Node *prev;
	Node(int value) {
		this->value = value;
		this->next = nullptr;
		this->prev = nullptr;
	}
};
class Vector {
public:
	Node *Head;
	Node *Tail;
	int sz;
	Vector() {      // Other possible variants // Vector(N) // Vector(N,0)
		this->Head = nullptr;
		this->Tail = nullptr;
		this->sz = 0;
	}
	void PushBack(int value) {
		Node * new_node = new Node(value);
		if (Head == nullptr) {
			Head = new_node;
			Tail = new_node;
		}
		else {
			Tail->next = new_node;
			Tail = new_node;
		}
	}
	bool Empty() { return (sz == 0); }
	int Size() { return sz; }
	void Clear() {
		while (Head) {
			Node * t = Head;
			Head = t->next;
            //cout << t->value <<" deleted "<<endl;
			delete(t);
		}
		Head = nullptr;
		Tail = nullptr;
	}
    ~Vector() {
        Clear();
    }
};

class Queue {
public:
	Node *Head;
	Node *Tail;
	int sz;
	Queue() {
		this->Head = nullptr;
		this->Tail = nullptr;
		this->sz = 0;
	}
	void Push(int value) {
		Node * new_node = new Node(value);
		if (Head == nullptr) {
			Head = new_node;
			Tail = new_node;
			new_node->prev = nullptr;
		}
		else {
			new_node->prev = Tail;
			Tail->next = new_node;
			Tail = new_node;
		}
		sz++;
	}
	void Pop() {
		if ((this->sz == 0) || (Head == nullptr)) {
			return;
		}else {
			Node *del_node = Head;
			Head = Head->next;
			if (Head != nullptr) {
				Head->prev = nullptr;
				del_node->next = nullptr;
				delete del_node;
			}else {
				Head = nullptr;
				Tail = nullptr;
			}
			this->sz = this->sz - 1;
		}
	}
	Node Front() {
		return *Head;
	}
	bool Empty() { return (sz == 0); }
	int Size() { return sz; }
	void Clear() {
		while (Head) {
			Node * t = Head;
			Head = t->next;
			delete(t);
		}
		Head = nullptr;
		Tail = nullptr;
	}
};

Vector g[100];
int N, M;
int visited[100];
int dist[100];

void bfs(int u) {
	Queue Q;
	Q.Push(u);
	dist[u] = 0;
	visited[u] = 1;
	while (!Q.Empty()) {
		Node obj = Q.Front();
		Q.Pop();
		int node = obj.value;
		Node *iter = g[node].Head;
		while (iter) {
			if (!visited[iter->value]) {
				visited[iter->value] = 1;
				if (dist[iter->value] > dist[node] + 1) {
					dist[iter->value] = dist[node] + 1;
					Q.Push(iter->value);
				}
			}
			iter = iter->next;
		}
	}
	Q.Clear();
}
int main() {
    ifstream fin("in.txt");
	ofstream fout("out.txt");
	fin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		fin >> x >> y;
		g[x].PushBack(y);
		g[y].PushBack(x);
	}
	fin.close();
	for (int node = 1; node <= N; node++) {
		dist[node] = 1e9;
	}
	for (int node = 1; node <= N; node++) {
		if (!visited[node]) {
			cout << node << " invoked" << endl;
			bfs(node);
		}
	}
    cout <<"bfs over !! "<<endl;
	for (int node = 1; node <= N; node++) {
		fout << "distance of node" << node << " : " << dist[node] << endl;
	}
	fout.close();
}