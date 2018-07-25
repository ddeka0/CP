#include <bits/stdc++.h>
using namespace std;
int p[1009];
long long dp[1009];
const long long MOD = 1e9 + 7;
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++) {
		cin >> p[i];
	}
	dp[1] = 0;
	for(int i = 2;i<=n+1;i++) {
		dp[i] = ( 1LL*2*dp[i-1] - dp[p[i-1]] + 2 ) % MOD;
	}
	cout << dp[n+1]%MOD << endl;
	return 0;
}