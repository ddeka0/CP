#include <bits/stdc++.h>
using namespace std;

vector<int> g[100010];
vector<bool> started;
vector<bool> ended;
vector<int> ans;

bool dfs(int root) {
    started[root] = true;
    bool ret = true;
    for(int u : g[root]) {
        if(started[u] && !ended[u]) return false;
        if(!ended[u]) ret &= dfs(u);
    }
    ans.push_back(root);
    ended[root] = true;
    return ret;
}

int main() {
    int n,m;
    cin >> n >> m;

    for(int i = 0;i<m;i++) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    started.assign(n + 1 ,0);
    ended.assign(n + 1,0);

    ans.clear();

    for(int k = 1;k<=n;k++) {
        if(ended[k]) continue;
        if(!dfs(k)) {
            std::cout <<"IMPOSSIBLE" << std::endl;
            return 0;
        }
    }
    std::reverse(ans.begin(),ans.end());
    for(auto&& e: ans) 
        std::cout << e <<" ";
    
    std::cout << std::endl;
}