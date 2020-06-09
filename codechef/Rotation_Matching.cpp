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

int a[200000 + 5];
int b[200000 + 5];
int main() {
    int N;
    cin >> N;
    int x;
    for(int i=0;i<N;i++) {
        cin >> x;
        a[x] = i;
    }
    for(int i = 0;i<N;i++) {
        cin >> x;
        b[x] = i;
    }
    std::map<int,int> Map;
    for(int num = 1;num<=N;num++) {
        Map[(a[num] - b[num] + N)%N]++;
    }
    int ans = -1;
    for(auto &e:Map) {
        ans = max(ans,e.second);
    }
    cout << ans << endl;
}