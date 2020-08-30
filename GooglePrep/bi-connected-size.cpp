#include <bits/stdc++.h>
using namespace std;

vector<int> g[100001];
int num[100001];
int lnum[100001];
int dfsCounter;
stack<pair<int,int>> Stack;
int bcc;

int mxSize;

void dfs(int u,int paren = -1) {
    num[u] = lnum[u] = ++dfsCounter;
    for(auto &v:g[u]) {
        if(num[v] == 0) { // not visited
            dfs(v,u);
            if(lnum[v] > num[u]) {
                cout <<"bi-connectec component : "<< ++bcc << endl;
                while(!Stack.empty() && Stack.top().second > lnum[u]) {
                    cout << Stack.top().first << endl;
                    Stack.pop();
                }
            }
            lnum[u] = min(lnum[u],lnum[v]);
        }else if(v != paren) {
            lnum[u] = min(lnum[u],num[v]);
        }
    }
    Stack.push(make_pair(u,lnum[u]));
}
int main() {
    int n,m;
    cin >> n >> m;
    for(int i = 0;i<m;i++) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    
    // remaining comp size

    cout << Stack.size() << endl;
}