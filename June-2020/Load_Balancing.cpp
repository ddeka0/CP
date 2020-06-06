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
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    int s = 0;
    for(int i = 0;i<n;i++) {
        cin >> v[i];
        s += v[i];
    }
    sort(v.begin(),v.end());
    int n_big = s % n;
    int n_small = n - n_big;
    int big = ceil(s*1.0/n);
    int small = floor(s*1.0/n);
    //trace(n_big,n_small,big,small);
    int ans = 0;

    for(int i = 0;i<n;i++) {
        ans += abs(v[i] - ((i<n_small)?small:big));
    } 
    cout << ans / 2 << endl;
}