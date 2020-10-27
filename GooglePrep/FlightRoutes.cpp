#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 100;
const long long inf = 1e15;
 
vector<pair<int,int>> g[N];
vector<long long> d[N];
 
int main() {
    int n,m,k;
    cin >> n >> m >> k;
    int u,v,c;
 
    for(int i = 0;i<m;i++) {
        cin >> u >> v >> c;
        g[u].push_back({v,c}); 
    }
 
    priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,greater<pair<long long,int>> > Q;
    
    Q.push({0,1});
 
    vector<long long> cnt(N,0);
 
    while(!Q.empty()) {
        auto p = Q.top();
        Q.pop();
        
        int u = p.second;
        long long _d = p.first;
 
        cnt[u]++;
        if(d[u].size() < k)
            d[u].push_back(_d); // cnt[u]'th shortest path distance for u
 
        if(cnt[u] <= k) {
            for(auto&& e : g[u]) {
                int v = e.first;
                int w = e.second;
                Q.push({_d + w,v});
            }
        }   
    }
      
    for(auto&& v: d[n]) {
        cout<<v<<" ";
    }   
    cout << endl;
}