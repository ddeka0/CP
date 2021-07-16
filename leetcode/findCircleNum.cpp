#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void dfs(vector<int>g[],vector<int>& visited,int root,int parent = -1) {
        visited[root] = true;
        for(auto&& u:g[root]) {
            if(!visited[u] && u != parent) {
                dfs(g,visited,root);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> g[210];
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                if(isConnected[i][j]) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int ans;
        vector<int> visited(210,false);
        for(int i = 0;i<n;i++) {
            if(!visited[i]) {
                dfs(g,visited,i);
                ans++;
            }
        }

        return ans;
    }
};


int main() {


}