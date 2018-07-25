#include <bits/stdc++.h>
using namespace std;
int dp[110][110];
int M = 100;
int a[10000];
int n;
int target = 10;
int solve() {
    for(int j = 0;j <= M;j++) {
        dp[0][j] = abs(a[0] - j);
       // cout << dp[0][j] <<" ";
    }
    for(int i = 1;i<n;i++) {
        for(int j = 0;j<=M;j++) {
            dp[i][j] = 1e8;
            for(int k = max(0,j - target);k<= min(M,j+target);k++) {
                dp[i][j] = min( dp[i][j] , dp[i - 1][k] + abs(a[i] - j) );
            }
        }
    }
    int ans = 1e8;
    for(int j = 0;j<=M;j++) {
        //cout << dp[n-1][j] << endl;
        ans = min(ans , dp[n - 1][j]);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    memset(dp,1e8,sizeof dp);
    cin >> n;
    for(int i = 0;i<n;i++) {
        cin >> a[i];
    }
    int ans = solve();
    cout << ans << endl;
}
