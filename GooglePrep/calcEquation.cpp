#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<string,vector<pair<string,double>>> adj;

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        for(int i = 0;i<equations.size();i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double ubyv = values[i];
            adj[u].emplace_back(v, 1.0*ubyv);
            adj[v].emplace_back(u, 1.0/ubyv);
        }

        map<string,double> ratioMap;
        map<string,bool> visited;
        map<string,int> compId;

        int cnt = 0;

        for(int i = 0;i<equations.size();i++) {

            if(visited[equations[i][0]]) continue;
            
            cnt++;

            string _start = equations[i][0];

            queue<pair<string,double>> Q;
            visited[_start] = 1;
            Q.push({_start,1.0});

            while(!Q.empty()) {
                auto u = Q.front();
                Q.pop();

                string _u = u.first;
                double w = u.second;

                compId[_u] = cnt;   // component ID fixed
                ratioMap[_u] = w;   // ratio fixed now, root/_u = w

                for(auto&& v: adj[_u]) {
                    string _v = v.first;
                    double _w = v.second;
                    if(visited.find(_v) == visited.end()) {
                        visited[_v] = 1;
                        double __w = w * 1.0 * _w;
                        Q.push({_v,__w});
                    }
                }
            }
        }

        vector<double> ans;
        for(int i = 0;i<queries.size();i++) {
            string c = queries[i][0];
            string d = queries[i][1];
            
            if(compId.find(c) == compId.end() || compId.find(d) == compId.end()) {
                ans.push_back(-1.0);
                continue;
            }

            if(compId[c] != compId[d]) {
                ans.push_back(-1.0);
                continue;
            }
            double v = 1.0/ratioMap[c];
            v = v * 1.0 * ratioMap[d];
            ans.push_back(v);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<string>> equations = {{"a","b"},{"b","c"}};
    vector<double> values = {2.0,3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    auto val = s.calcEquation(equations,values,queries);
    for(auto&& e:val) {
        std::cout << e <<" ";
    }
    std::cout << std::endl;
}