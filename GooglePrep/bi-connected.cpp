#include <bits/stdc++.h>
using namespace std;

vector<int> g[100001];
int num[100001];
int lnum[100001];
int dfsCounter;
stack<pair<int,int>> Stack;
int bcc;

void dfs(int u,int paren = -1) {
    num[u] = lnum[u] = ++dfsCounter;
    for(auto &v:g[u]) {
        if(num[v] == 0) { // not visited
            //cout <<__LINE__<<" : "<<u<<" -- "<<v<<" pushed" << endl;
            Stack.push(make_pair(u,v));
            dfs(v,u);
            if(lnum[v] >= num[u]) { // u is a articulation point
                cout <<"bi-connected component : "<< ++bcc << endl;
                cout <<"Articulation Point : "<<u << endl;
                while(!(Stack.top().first == u and Stack.top().second == v)) {
                    cout << Stack.top().first <<" -- "<<Stack.top().second << endl;
                    Stack.pop();
                }
                cout << Stack.top().first <<" -- "<<Stack.top().second << endl;
                Stack.pop();
                cout << endl;
            }
            lnum[u] = min(lnum[u],lnum[v]);
        }else if(v != paren) {
            if(num[v] < num[u]) {
                //cout <<__LINE__<<" : "<<u<<" -- "<<v<<" pushed" << endl;
                Stack.push(make_pair(u,v));
            }
            lnum[u] = min(lnum[u],num[v]);
        }
    }
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
}