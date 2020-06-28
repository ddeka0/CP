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


bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for(int t = 1;t<=T;t++) {
        int n;
        cin >> n;
        if(n == 1) {
            cout << "FastestFinger" << endl; // B
            continue;
        }

        if(n&1 or n == 2) {
            cout <<"Ashishgup" << endl; // A
        }else {
            // only power of 2 -> lose
            // with other factor -> win
            if(n && (!(n&(n-1)))) { // power of 2
                cout << "FastestFinger" << endl;
            }else {
                if(n%4 == 0) {
                    cout << "Ashishgup" << endl;
                }else {
                    int v = n / 2;
                    if(isPrime(v)) {
                        cout << "FastestFinger" << endl;
                    }else {
                        cout << "Ashishgup" << endl;
                    }
                }
 
            }
        }
    }
}