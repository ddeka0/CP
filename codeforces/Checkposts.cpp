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


const int NN = int(2*1000000 + 10);


int main() {
    int n;
    cin >> n;
    vector<int> m(n,0);
    vector<int> adj[n+1];
    for(int i = 0;i<n;i++) {
        cin >> m[i];
    }
    int e;
    cin >> e;
    int u,v;
    for(int i = 0;i<e;i++) {
        cin >> u >> v;
        adj[u].push_back(v); // one way path from u to v
    }
    vector<pair<int,int>> vv(n+1);
    vector<int> visited(n+1,false);
    for(int i = 1;i<=n;i++) {
        vv[i] = make_pair(i,i); // i is a part of ith circle
    }
    for(int node = 1;node <=n;node++) {
        
        auto dfs = [&](int root,int paren) {
            if(visited[root]) {

            }
            visited[root] = true;
            for(int i)
        };
    }
}


// vector < vector<int> > g, gr;
//     vector<bool> used;
//     vector<int> order, component;

//     void dfs1 (int v) {
//         used[v] = true;
//         for (size_t i=0; i<g[v].size(); ++i)
//             if (!used[ g[v][i] ])
//                 dfs1 (g[v][i]);
//         order.push_back (v);
//     }

//     void dfs2 (int v) {
//         used[v] = true;
//         component.push_back (v);
//         for (size_t i=0; i<gr[v].size(); ++i)
//             if (!used[ gr[v][i] ])
//                 dfs2 (gr[v][i]);
//     }

//     int main() {
//         int n;
//         ... reading n ...
//         for (;;) {
//             int a, b;
//             ... reading next edge (a,b) ...
//             g[a].push_back (b);
//             gr[b].push_back (a);
//         }

//         used.assign (n, false);
//         for (int i=0; i<n; ++i)
//             if (!used[i])
//                 dfs1 (i);
//         used.assign (n, false);
//         for (int i=0; i<n; ++i) {
//             int v = order[n-1-i];
//             if (!used[v]) {
//                 dfs2 (v);
//                 ... printing next component ...
//                 component.clear();
//             }
//         }
//     }


































