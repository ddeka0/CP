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
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(k);
        for(int i = 0;i<n;i++) {
            cin >> a[i];
        }
        for(int i = 0;i<k;i++) {
            cin >> b[i];
        }
        sort(a.begin(),a.end(),std::greater<int>());
        sort(b.begin(),b.end());
        long long int ans = 0;
        for(int i = 0,j = k-1;i<k;i++) {
            // int w = a[i];
            ans += a[i];
            if(b[i] > 1)
                ans += a[j + b[i]-1];
            else   
                ans += a[i];
            j += b[i]-1;
        }
        cout << ans << endl;
    }
}