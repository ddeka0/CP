#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> paren;
    vector<int> rank;
    struct Edge {
        int u,v,w;
        bool operator<(const Edge& other) {
            return w < other.w;
        }
    };

    int find_set(int u) {
        if(paren[u] != u) {
            u = find_set(paren[u]);
        }
        return paren[u];
    }

    bool make_set(int u,int v) {
        int uu = find_set(u);
        int vv = find_set(v);
        if(uu == vv) return false;
        if(rank[uu] > rank[vv]) {
            swap(uu,vv);
        }
        if(rank[uu] == rank[vv]) rank[vv]++:
        
        paren[uu] = vv;
        return true;
    }
    int minimumCost(int N, vector<vector<int>>& connections) {
        if(N == 0) return 0;
        paren.resize(N+1,0);
        rank.resize(N+1,0);
        for(int i = 1;i<=N;i++) { paren[i] = i; }
        
        vector<Edge> edges;

        for(auto&& edge : connections) {
            Edge e;
            e.u = edge[0];
            e.v = edge[1];
            e.w = edge[2];
            edges.push_back(std::move(e));
        }
        
        sort(edges.begin(),edges.end());
        
        int ans = 0;
        
        for(auto&& e:edges) {
            if(make_set(e.u,e.v)) {
                ans += e.w;
            }
        }
        return ans;
    }
};

int main() {

}