#include <bits/stdc++.h>
using namespace std;
long long dp[2009][2009];
long long mod = 1e9 + 7;
int main() {
	int n,k;
	cin >> n >> k;
	/* number range [1,2,3...n]
	   find sequence : b_1,b_2,b_3...b_k such that b_i divides b_(i+1)
	   and b_i <= b_(i+1)
	   how many such sequence of length k ?
	*/
	for(int i = 1;i<=n;i++) {
		dp[1][i] = 1;
	}	
	for(int len = 2;len <=k;len++) {
		for(int i = 1;i<=n;i++) {
			for(int j = i;j<=n;j += i) {
				dp[len][j] = (dp[len][j] + dp[len - 1][i])%mod;
			}
		}
	}
	long long ans = 0;
	for(int i = 1;i<=n;i++) {
		ans  = (ans + dp[k][i])%mod;
	}
	cout << ans << endl;
}