#include <bits/stdc++.h>
using namespace std;
int n,k;

int a[109];
int b[109];

int dp[109][100009 + 12345]; 	// maximum negative can be 1e5
								// so my reference is 1e5
								// max positive can be 1e4
int inf = 1e9;
int zero = 100009;				// my reference
int recurse(int idx,int diff) {
	
	if(idx == n+1 ) {
		return diff == zero ? 0 : -1*inf;
	}

	if(dp[idx][diff] != -1) {
		return dp[idx][diff];
	}
	
	int take = 0,not_take= 0;
	int new_diff = a[idx] - b[idx] + diff;	// this new_diff can never go to negative
	take = recurse(idx+1, new_diff) + a[idx];
	not_take = recurse(idx+1,diff);
	dp[idx][diff] = max(take,not_take);
	return dp[idx][diff];
}
int main() {
	cin >> n >> k;
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++) {
		cin >> b[i];
		b[i] = b[i]*k;
	}
	memset(dp,-1,sizeof dp);
	int ans = recurse(1,zero);
	ans = ans < 1 ? -1:ans;		// ans == 0 means -1 // nothing can be taken
	cout << ans << endl;
}