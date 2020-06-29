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
    int primes[2] = {2,3};
    while(T--) {
        int n;
        cin >> n;
        if(n == 1) {
            cout << 0 << endl;
            continue;
        }
        int i = 0;
        int primeCnt[2] = {0,0};
        while(n > 1 and i < 2) {
            while(n%primes[i] == 0) {
                n = n/primes[i];
                primeCnt[i]++;
            }
            i++;
        }
        if(n > 1) {
            cout << -1 << endl;
            continue;
        }
        // n == 1
        if(primeCnt[0] > primeCnt[1]) {
            cout << -1 << endl;
            continue;
        }else {
            cout << 2*primeCnt[1] - primeCnt[0] << endl;
        }
    }
}