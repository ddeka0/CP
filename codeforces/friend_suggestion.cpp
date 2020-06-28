#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    explicit Node(int val):next(nullptr),prev(nullptr),val(val) {}
};

const int Max_nodes = 10010;
int N;
Node* roots[Max_nodes + 10];

// nodes[1] -> x -> y ->  z
// nodes[2] -> x -> y ->  z
void init(int N) {
    ::N = N;
    for(int i = 0;i<N;i++) {
        roots[i] = nullptr;
    }
}
void add(int id,int F, int ids[]) {
    // Node * tail = 
    Node * tail = nullptr;
    if(roots[id] != nullptr) {
        tail = roots[id]->prev;
    }
    for(int i = 0;i<F;i++) {
        Node * node  = new Node(ids[i]);
        if(tail == nullptr) {
            roots[id] = node;
            node->prev = node;
            tail = node;
            continue;
        }
        tail->next = node;
        tail = node;
    }
    roots[id]->prev = tail; // finally roots[id]->prev will store tail
}

// there will not be invalid del operation
void del(int id1,int id2) {
    // delete id2 from id1 list
    Node* ptr = nullptr;
    Node* prev = nullptr;
    ptr = roots[id1];
    prev = roots[id1];
    while(ptr != nullptr) {
        if(ptr->val == id2) {
            prev->next = ptr->next;
            if(ptr->next)
                ptr->next->prev = prev;
            else
                roots[id1]->prev = prev; // required
            // ptr->prev = nullptr;
            // ptr->next = nullptr;
            delete(ptr);
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    // do the same for deleting id1 from id2's list
    ptr = roots[id2];
    prev = roots[id2];
    while(true) {
        if(ptr->val == id2) {
            prev->next = ptr->next;
            if(ptr->next)
                ptr->next->prev = prev;
            else
                roots[id1]->prev = prev; // required
            // ptr->prev = nullptr;
            // ptr->next = nullptr;
            delete(ptr);
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
}

bool visited[Max_nodes + 10];
int cnt[Max_nodes + 10];

int recommend(int id,int list[]) {
    int _list[5]; int cnt[5];
    for(int i = 0;i<5;i++) {
        _list[i] = 0;
    }
    for(int i = 0;i<5;i++) {
        cnt[i] = 0;
    }
    if(roots[id] == nullptr) {
        return 0;
    }
    for(int i = 0;i<min(N,Max_nodes);i++) {
        cnt[i] = 0;
        visited[i] = false;
    }
    // iterate over all the neighbour of id node
    for(Node* u = roots[id];u != nullptr;u = u->next) {
        if(roots[u->val] == nullptr) continue;
        for(Node *v = roots[u->val];v != nullptr;v = v->next) {
            ++cnt[v->val];
        }
        visited[u->val] = true;
    }
    for(int i = 0;i<min(N,Max_nodes);i++) {
        if(!visited[i] && cnt[i] > 0 && _list[4] < cnt[i]) {
            // insertion sort 5^5 = 25 ops max
            for(int j = 0;j<5;j++) {
                if(_list[j] < cnt[i]) {
                    for(int k = 4;k>j;k--) {
                        list[k] = list[k - 1];
                        _list[k] = _list[k - 1];
                    }
                    _list[j] = cnt[i];
                    list[j] = i;
                    break;
                }
            }
        }
    }
    int ret = 0;
    int i = 0;
    while(i < 5 && _list[i] > 0) {
        ret++;
    }
    return ret;
}
int main() {

}