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
    int n;
    string s;
    for(int t = 1;t<=T;t++) {
        cin >> n;
        cin >> s;
        string _ones;
        int _zeros = 0;
        for(int i = n-1;i>=0;i--) {
            if(s[i] == '1') {
                if(_zeros == 0) {
                    _ones += "1";
                }else {
                    _zeros = 1;
                }
            }else {
                _zeros++;
            }
        }
        string ans;
        for(int i = 0;i<_zeros;i++) {
            ans += "0";
        }
        cout << ans + _ones << endl;
    }
}