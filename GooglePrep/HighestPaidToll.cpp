#include <bits/stdc++.h>
using namespace std;
const int N = 11000;

const int inf = numeric_limits<int>::max();

vector<pair<int,int>> g[2][N];
std::array<vector<long long>,2> d;
vector<bool> visited(N);

int main() {
    int T;
    cin >> T;
    for(int tt = 1;tt<=T;tt++) {
        int n,m,s,t,p;
        cin >> n >> m >> s >> t >> p;

        for(int i = 0;i<2;i++) {
            for(int j = 0;j<N;j++) {
                g[i][j].clear();
            }
            d[i].clear();
        }     

        std::fill(d.begin(),d.end(),vector<long long>(N,inf));
        std::fill(visited.begin(),visited.end(),false);

        int u,v,c;
        while(m--) {
            cin >> u >> v >> c;
            g[0][u].push_back({v,c});
            g[1][v].push_back({u,c});
        }

        int source[2] = {s,t};

        int i = 0;
        while(i < 2) {
            std::fill(visited.begin(),visited.end(),false);
            set<pair<int,int>> H;
            H.insert({0,source[i]});
            d[i][source[i]] = 0;
            visited[source[i]] = true;
            while(!H.empty()) {
                auto e = *(H.begin());
                H.erase(H.begin());
                int u = e.second;
                for(auto p:g[i][u]) {
                    int v = p.second;
                    if(!visited[v] && d[i][v] > p.first + d[i][u]) {
                        auto ptr = H.find({d[i][v],v});
                        
                        if(ptr != H.end())
                            H.erase(ptr);
                        
                        d[i][v] = p.first + d[i][u];
                        H.insert({d[i][v],v});
                    }
                }
            }
            i++;
        }

        std::fill(visited.begin(),visited.end(),false);
        int ans = -1;
        queue<int> Q;
        Q.push(s);
        visited[s] = true;
        while(!Q.empty()) {
            auto u = Q.front();
            Q.pop();
            for(auto&& v: g[0][u]) {

                if(d[0][u] < inf && d[1][v.first] < inf) {
                    if(d[0][u] + v.second + d[1][v.first] <= p) {
                        ans = max(ans,v.second);
                    }
                }

                if(!visited[v.first]) {
                    Q.push(v.first);
                    visited[v.first] = true;
                }
            }

        }
        std::cout << ans << std::endl;
    }
}