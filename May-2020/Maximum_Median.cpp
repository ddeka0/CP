/*  Author  : Debashish Deka
    Date    : May 29th 2020
	Compiler and Lang: gcc-10 & C++17 
*/
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
    int n,k;
    cin >> n >> k;
    vector<int> v;
    int t;
    for(int i = 0;i<n;i++) {
        cin >> t;
        v.push_back(t); 
    }
    sort(v.begin(),v.end());
    if(n == 1) {
        return v[0] + k;
    }
    vector<long int> cs;
    cs.push_back(0);
    for(int i = n/2, j = 1; i < n-1; i++,j++) {
        int val = (v[i+1] - v[i])*j + cs[j-1];
        cs.push_back(val);
    }
    auto pos = upper_bound(cs.begin(),cs.end(),k) - cs.begin();
    // trace(pos);
    if(pos == cs.size()) {
        cout << v[n-1] + ((k - cs[pos-1])/pos) << endl;
    }else {
        cout << v[pos - 1 + n/2] + ((k - cs[pos-1])/pos) << endl;
    }
    
}