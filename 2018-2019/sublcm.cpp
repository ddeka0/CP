#include <bits/stdc++.h>
using namespace std;
int a[1000009];
int last[1000009];
char str[1000009];
int primes[1000009];
int cnt = 0;
vector<int> fac[1000009];
void precal() {
    int n = 10000;
    for(int i = 2;i*i <= n;i += 2) {
        if(str[i] == 0) {
            for(int j = i;j*i <=n;j++) {
                str[j*i] = 1;
            }
        }
    }
    for(int i = 2;i<=n;i+= 2) {
        if(str[i] == 0) {
            primes[cnt++] = i;
        }
    }
}
int main() {
    precal();
    int i,j,k;
    for(int i = 2;i<=1000000;i++) {
        j = i;
        for(int k = 0;primes[k] * primes[k] <=j;k++) {
            if(j % primes[k] == 0) {
                fac[i].push_back(primes[k]);
                while(j%primes[k] == 0) {
                    j = j / primes[k];
                }
            }
        }
        if(j>=2) {
            fac[i].push_back(j);
        }
    }
    int T;
    cin >> T;
    for(int q = 1;q<=T;q++) {
        memset(dp,-1,sizeof dp);
        memset(last,-1,sizeof last);
        int n;
        cin >> n;
        for(int i = 1;i<=n;i++) {
            cin >> a[i]
        }
        dp[1] = 1;
        for(int p:fac[a[1]]) {
            last[p] = 1;
        }
        for(int i = 2;i<=n;i++) {
            int maxi = dp[i-1];
            for(int p:fac[a[i]]) {
                maxi = max(maxi,last[p] + 1) // we are adding 1 to it because last is initialized with zeros
                last[p] = i;
            }
            dp[i] = maxi;
        }
        int ans = -1;
        for(int i=1;i<=n;i++) {
            ans = max(ans,i - dp[i] + 1);
        }
        if(ans == 1) cout <<"-1"<<endl;
        else cout <<ans<<endl;
    }
    return 0;
}
