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
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());

    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    int u,v;
    for(int i = 0;i<m;i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int MAX_ITER = 1;
    int iteration = 0;
    int maxIS = -1;
    vector<int> maxV;
    
    while(iteration++ <= MAX_ITER) {
        set<int> Set;
        for(int i = 1;i<=n;i++) {
            Set.insert(i);
        }
        vector<int> v;
        while(!Set.empty()) {
            int Sz = Set.size();
            const int range_from  = *Set.begin();
            const int range_to    = *Set.rbegin();
            std::uniform_int_distribution<int>  distr(0,Sz-1);
            int delIndex = distr(generator);
            int delNode = *std::next(Set.begin(), delIndex);
            v.push_back(delNode);
            for(auto v:adj[delNode]) {
                Set.erase(v);
            }
            Set.erase(delNode);
        }
        int sz = v.size();
        // trace(iteration,sz,maxIS);
        if(sz > maxIS) {
            //trace(1);
            maxIS = sz;
            maxV.clear();
            for(auto x:v) {
                maxV.push_back(x);
            }
        }
    }
    vector<bool> f(n+1,false);
    for(auto x:maxV) {
        f[x] = 1;
        // cout << x << endl;
    }
    cout << maxV.size() << endl;
    for(int i =1;i<=n;i++) {
        cout << f[i] <<" ";
    }
}