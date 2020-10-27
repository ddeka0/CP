#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;
const long long inf = 1e15;
 
vector<pair<int,int>> g[2][N];
long long d[2][N];
bool visited[N];


int main() {
    int n,m;
    cin >> n >> m;
    int u,v,c;
    for(int i = 0;i<m;i++) {
        cin >> u >> v >> c;
        g[0][u].push_back({v,c});
        g[1][v].push_back({u,c});
    }

    std::fill(d[0],d[0]+N,inf);
    std::fill(d[1],d[1]+N,inf);

    int source[2] = {1,n};
    int t = 0;
    while(t < 2) {

        std::fill(visited,visited + N,false);
        
        priority_queue<pair<long long,int>,
            vector<pair<long long,int>>,greater<pair<long long,int>>> Q;

        Q.push({0,source[t]});
        d[t][source[t]] = 0;
        visited[source[t]] = true;

        while(!Q.empty()) {
            auto res = Q.top();
            Q.pop();
            int u = res.second;
            long long _d = res.first;

            

            for(auto&& e:g[t][u]) {
                int v = e.first;
                int w = e.second;
                if(!visited[v] and d[t][v] > _d + w) {
                    d[t][v] = _d + w;
                    visited[v] = true;
                    Q.push({d[t][v],v});
                }
            }
        }
        
        t++;

    }


    long long ans = inf;
    std::fill(visited,visited + N,false);
    queue<int> _Q;
    _Q.push(1);
    while(!_Q.empty()) {
        auto u = _Q.front();
        _Q.pop();
        for(auto&& e:g[0][u]) {
            int v = e.first;
            if(!visited[v]) {
                visited[v] = true;
                if(d[0][u] < inf and d[1][v] < inf) {
                    long long x = floor((e.second)/2);
                    ans = min(ans, d[0][u] + x + d[1][v]);
                }
            }
        }

    }

    cout << ans << endl;

}