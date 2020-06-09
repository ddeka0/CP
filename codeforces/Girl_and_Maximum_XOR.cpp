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
    unsigned long long int L,R;
    cin >> L >> R;
    int max_bit_pos; // of R
    for(int i = 63;i>=0;i--) {
        if(R & (1*1LL<<i)) {
            max_bit_pos = i;
            break;
        }
    }
    unsigned long long int a = L;
    unsigned long long int b = R;

    for(int i = max_bit_pos;i>=0;i--) {
        
        bool a_ith_on = a & (1*1LL<<i);
        bool b_ith_on = b & (1*1LL<<i);
        // if low_ith_on and high_ith_on is different, do nothing
        if(a_ith_on == b_ith_on) {
            // toggle ith bit of a and b
            long long int tb = b ^ (1*1LL<<i);
            if(tb <= R and tb >= L) {
                b = tb;
                continue;
            }
            long long int ta = a ^ (1*1LL<<i);
            if(ta >= L and ta <= R) {
                a = ta;
                continue;
            }
        }
    }
    long long int ans  = a ^ b;
    cout << ans << endl;
}