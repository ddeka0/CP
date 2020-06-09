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

int N = 1000000;
int main() {
    vector<int> adj[20];
    int ne;
    cin >> ne;
    for(int i = 0;i<ne;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    long long int tCnt = 0;
    for(int iter = 0;iter <N;iter++) {
        set<int> Set;
        queue<int> Q;
        
        long long int cnt = 0;

        Q.push(1);
        while(!Q.empty()) {
            auto u = Q.front();
            Q.pop();
            Set.insert(u);
            for(auto &v:adj[u]) {
                Q.push(v);
            }
        }
        
        while(!Set.empty()) {
            cnt++;
            int Sz = Set.size();
            //trace(Sz);
            const int range_from  = *Set.begin();
            const int range_to    = *Set.rbegin();
            std::uniform_int_distribution<int>  distr(0,Sz-1);
            int delIndex = distr(generator);
            int delNode = *std::next(Set.begin(), delIndex);
            // trace(delNode);
            // do bfs and delete the subtree rooted at delNode
            // queue<int> Q;
            Q.push(delNode);
            while(!Q.empty()) {
                auto u = Q.front();
                Q.pop();
                Set.erase(u);
                for(auto &v:adj[u]) {
                    Q.push(v);
                }
            }
        }
        trace(cnt);
        tCnt += cnt;
    }
    cout << tCnt*1.0/N << endl;
}

