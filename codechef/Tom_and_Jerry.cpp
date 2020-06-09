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
    for(int t = 1;t<=T;t++) {
        long long int TS = 0;
        int pos = 0;
        bool f = false;
        cin >> TS;
        long long int ans = 0;
        while(TS > 0 && !f) {
            if(TS%2)
                f = 1;
            TS = TS >> 1;
        }
        cout << TS << endl;
    }
}