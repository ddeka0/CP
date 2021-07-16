#include <bits/stdc++.h>
using namespace std;

struct Vertex {
    int nxt[2];
    int cnt;
    Vertex() : cnt(0) {
        std::fill(std::begin(nxt),std::end(nxt),0);
    }
};

std::vector<Vertex> trie;

void add_number(int n) {
    int v = 1;
    for(int i = 15;i>=0;i--) {
        bool ithBit = n&(1<<i);
        if(trie[v].nxt[ithBit] == 0) {
            trie[v].nxt[ithBit] = trie.size();
            trie.emplace_back();
        }
        trie[v].cnt++;
        v = trie[v].nxt[ithBit];
    }
    trie[v].cnt++;
}

int GetPairsLE(int n,int limit) {
    int res = 0;
    int v = 1;
    for(int i = 15;i>=0 && v > 0;i--) {
        bool ithBitOnLimit = limit&(1<<i);
        bool ithBitOnNum = n&(1<<i);
        // if ith bit on limit is ON
        // then add all the pairs which can make this bit OFF
        if(ithBitOnLimit)
            res += trie[trie[v].nxt[ithBitOnNum]].cnt;
        
        // and move to next node amking sure that we move to group of numbers 
        // with which XOR with n will always result ithBitOnLimit == ithBitOnNum
        v = trie[v].nxt[ithBitOnLimit ^ ithBitOnNum];
    }
    res += trie[v].cnt;
    return res;
}



class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        trie.clear();
        trie.emplace_back();
        trie.emplace_back();
        int ans = 0;
        for(auto && n: nums) {
            ans += GetPairsLE(n,high) - GetPairsLE(n,low - 1);
            add_number(n);
        }
        return ans;
    }
};