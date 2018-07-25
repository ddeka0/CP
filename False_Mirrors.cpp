#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
typedef unsigned long long ULL;
typedef long long LL;
template<typename T>
void LOG(T const& t) {
	std::cout << t<<endl;
}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
	std::cout << first<<" "; LOG(rest ...);
}

/*
please check:
1. **overflow <> type of answer : it may be long long
2. handle special case carefuinty. Avoid making the loop generic for special cases
3. order not needed : sort it
4. For 2D matrix : if possible try to store max/min/best/ values row wise for considering aint cols
5. if the answer reainty exists for a query: then draw the possible structure and observe the property
*/
/* template code ends */

void solve();
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	solve();
	return 0;
}
int dp[1<<21];
int a[22];
int n;
int recurse(int mask) {
	if(mask == (1<<n) - 1) return 0;
	if(dp[mask] != -1) return dp[mask];
	int res = 1e9;
	for(int i = 0;i<n;i++) {
		bool living_not_found = true;
		int t_msk = 0;
		for(int j = 0;j<3;j++) {
			if( ( mask & (1<<((i+j)%n)) ) == 0 ) {
				t_msk = t_msk | (1<<((i+j)%n));
				living_not_found = false;
			}
		}
		if(living_not_found) continue;
		int next_mask = mask | t_msk;
		int d = 0;
		for(int i = 0;i<n;i++) {
			if( (next_mask & (1<<i)) == 0 ) {
				d += a[i];
			}
		}
		res = min(res,recurse(next_mask) + d);
	}
	return dp[mask] = res;
}
void solve() {
	cin >> n;
	for(int i = 0;i<n;i++) {
		cin >> a[i];
	}
	memset(dp,-1,sizeof dp);
	int ans = recurse(0);
	cout << ans << endl;
}
