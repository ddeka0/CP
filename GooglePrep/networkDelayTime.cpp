#include <bits/stdc++.h>
using namespace std;

const int inf = std::numeric_limits<int>::max();

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        vector<pair<int,int>> adj[110];
        for(int i = 0;i<times.size();i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].emplace_back(v,w);
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
        // N : 1 .. N
        // K : 1 .. N
        vector<int> d(N+1,inf);

        d[K] = 0;
        Q.push({d[K],K});

        while(!Q.empty()) {
            auto u = Q.top();
            Q.pop();


            int _u = u.second; 
            int _w = u.first;  // _u 's distance from K is finalized now

            for(auto&& v:adj[_u]) {
                int _v = v.first;
                int w = v.second;
                if(d[_v] > _w + w) { // if _v is already in the Q, this condition will not met
                    d[_v] = _w + w;
                    Q.push({d[_v],_v});
                }
            }
        }

        bool possible = true;
        int ans = -1;
        for(int i = 1;i<=N;i++) {
            if(d[i] == inf) {
                possible = false;
                break;
            }
            ans = max(ans,d[i]);
        }
        return possible ? ans : -1;
    }
};