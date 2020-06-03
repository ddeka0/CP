#include <bits/stdc++.h>
using namespace std;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#define debug(stuff) cout << #stuff << ": " << stuff <<endl
#define debugc(stuff) cout << #stuff << ": "; for(auto x: stuff) cout << x << " "; cout << endl;



//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == nullptr) return;
        // 4->5->6->1
        // lets suppose node->val == 5
        // then copy 6 into 5
        // copy 1 into 6
        // erase 1 && set prevNode ptr to null also
        ListNode *prevNode = nullptr;
        while(true) {
            auto nextNode = node->next;
            if(nextNode != nullptr) {
                node->val = nextNode->val;
                prevNode = node;
                node = nextNode;
            }else {
                prevNode->next = nullptr;
                delete(node);
                break;
            }   
        }
    }
};



int main() {

}