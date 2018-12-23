#include <bits/stdc++.h>
using namespace std;
string str;
int mod = 1e9 + 7;
int main() {
    cin >> str;
    int n = (int)(str.length());
    vector<int> dp1(n+2,0);
    vector<int> dp2(n+2,0);
    int lastB = 0;
    dp1[0] = dp2[0] = 1;
    for(int i = 0;i<n;i++) {
        if(str[i] == 'b') {
            lastB = i + 1;
        }
        if(str[i] == 'a') {
            dp1[i+1] = dp2[lastB];            
        }
        dp2[i+1] = (dp2[i] + dp1[i+1])%mod;
    }
    cout << dp2[n] - 1 << endl;
}