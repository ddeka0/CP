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


class Solution {
public:
    vector<int> nodeCount;
    std::shared_ptr<vector<int>[]> adj = nullptr;
    int TotalNodes = 0;
    vector<int> finalAns;
    
    std::pair<int,int> dfs(int root,int paren) {
        int ans = 0;
        int nodes = 1;
        for(auto &v: adj[root]) {
            if(v == paren) continue;
            auto val = dfs(v);
            int _nodes = val.first;
            int _ans = val.second;
            nodes += _nodes;
            ans = ans + ( _nodes + _ans );
        }
        nodeCount[root] = nodes;    // for leaf nodes == 1
        auto ret = make_pair(nodes,ans); // for leaft ret = (1,0) // ok
        return ret;
    }
    void propagateAns(int rootAns,int root) {
        finalAns[root] = rootAns;
        for(auto &v:adj[root]) {
            int v_finalAns = rootAns + TotalNodes - 2 * nodeCount[v]; 
            propagateAns(v_finalAns,v);
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        TotalNodes = N;

        adj = shared_ptr<vector<int>[]>(new vector<int>[N]);
        
        nodeCount.resize(N);
        for(auto&x : nodeCount) x = 0;

        finalAns.resize(N);
        for(auto&x : finalAns) x = 0;
        
        for(auto &e:edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        auto T = dfs(0,-1).second;

        // cout <<"nodeCounts ..." << endl;
        // for(auto&v:nodeCount) 
        //     cout << v <<" ";
        // cout << endl;

        propagateAns(T,root);

        return finalAns;
    }
};

int main() {
    Solution s;
    // [[0,1],[0,2],[2,3],[2,4],[2,5]]
    vector<vector<int>> v;
    v.push_back(vector<int>{0,1});
    v.push_back(vector<int>{0,2});
    v.push_back(vector<int>{2,3});
    v.push_back(vector<int>{2,4});
    v.push_back(vector<int>{2,5});


    auto ans = s.sumOfDistancesInTree(6,v);
    for(auto &x:ans) {
        cout << x << " ";
    }
    cout << endl;
}