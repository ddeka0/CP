#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node *next;
    Node(int value) {
        this->value = value;
        this->next = nullptr;
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
        if(Head == nullptr) {
            Head = new_node;
            Tail = new_node;
        }else {
            Tail->next = new_node;
            Tail = new_node;
        }    
    }
    bool Empty() { return (sz == 0); }
    int Size() { return sz; }
    void Clear() {
        while(Head) {
            Node * t = Head;
            Head = t->next;
            delete(t);
        }
        Head = nullptr;
        Tail = nullptr;
    } 
};

Vector g[10];       // vector of ints

bool visited[10];
int dist[10];
Node Queue[100];
void bfs() {
    Node 
}
int main() {
 
    queue<> cin >> N >> M;
    for(int i = 0;i<M;i++) {
        int x,y;
        cin >> x >> y;
        g[x].PushBack(y);
        g[y].PushBack(x);
    }
    bfs();
}

