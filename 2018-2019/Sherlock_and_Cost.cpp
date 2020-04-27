#include <bits/stdc++.h>
using namespace std;
#define inf 1e9
int dp[100009][2];
int b[100009];
int T,n;
int recurse(int x,int f) {
    if(x == n) return 0;
    if(dp[x][f] != -1) {
        return dp[x][f];
    }
    int res = max(recurse(x + 1,0) + (f?abs(1 - b[x]):0) ,
                  recurse(x + 1,1) + (f?abs(b[x + 1] - b[x]):abs(1 - b[x + 1])) 
                 );
    return dp[x][f] = res;
}
int main() {
    cin >> T;
    for(int q = 1;q<=T;q++) {
        cin >> n;
        for(int i = 1;i<=n;i++) {
            cin >> b[i];
        }
        memset(dp,-1,sizeof dp);
        cout << max(recurse(1,0),recurse(1,1)) << endl;
    }
}