#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000000;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<std::pair<int,int>> g[110];
        for(auto&& flight : flights) {
            g[flight[0]].emplace_back(flight[1],flight[2]);
        }

        priority_queue<pair<int,std::pair<int,int>>,
            vector<pair<int,std::pair<int,int>>>,greater<pair<int,std::pair<int,int>>> > Q;
        
        std::vector<int> dist(n+1,inf);
        std::vector<int> hops(n+1,inf);

        Q.push({0,{src,0}});
        dist[src] = 0;
        hops[src] = 0;

        while(!Q.empty()) {

            auto thisCity = Q.top();
            Q.pop();

            int _d = thisCity.first;
            int _u = thisCity.second.first;
            int _h = thisCity.second.second;
            
            if(_u == dst) {
                dist[dst] = _d;
                break;
            }
            if(_h < k + 1) {
                for(auto&& nxtCity : g[_u]) {
                    int _v = nxtCity.first;
                    int _w = nxtCity.second;
                    if((dist[_v] >  _d + _w) || (hops[_v] > 1 + _h)) {
                        dist[_v] = _d + _w;
                        hops[_v] = _h + 1;
                        Q.push({dist[_v],{_v,_h+1}});
                    }
                }
            }

        }

        return dist[dst] == inf ? -1:dist[dst];
    }
};