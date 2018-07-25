#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100009];
bool seen[100009];
int n;
int r_level;
int dfs(int root,int level) {
    if(r_level == level) {
        return 1;
    }
    seen[root] = true;
    int ans = 0;
    for(int v:adj[root]) {
        if(!seen[v]) {
        	ans += dfs(v,level+1);
        }
    }
    seen[root] = false;
    return ans;
}
int main() {
    cin >> n;
    for(int i=1,u,v;i<n;i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> r_level;
    cout << dfs(1,1) << endl;
    return 0;
}
