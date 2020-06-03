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

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> g[numCourses];
        vector<int> ind(numCourses,0);
        for(auto &e:prerequisites) {
            g[e[0]].push_back(e[1]);
            ind[e[1]]++;
        }
        queue<int> Q;
        for(int i = 0;i<numCourses;i++) {
            if(ind[i] == 0) {
                Q.push(i);
            }
        }
        int cnt = 0;
        while(!Q.empty()) {
            auto n = Q.front();
            Q.pop();
            cnt++;
            for(auto & e:g[n]) {
                ind[e]--;
                if(ind[e] == 0) {
                    Q.push(e);
                }
            }
        }
        return cnt == numCourses;
    }
};

int main() {
    Solution s;
    
}