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

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n,k;
        map<long long,long long> Map;
        cin >> n >> k;
        for(int i = 0;i<n;i++) {
            int x;
            cin >> x;
            int req = (k - x%k)%k;
            if(req)
                Map[req]++;
        }
        long long ans = 0;
        for(auto &[req,f]:Map) {
            ans = max(ans,(f-1)*k + req + 1);
        }
        cout << ans << endl;
    }
}