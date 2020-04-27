// https://www.hackerrank.com/contests/mtech-placement-dpbasicspartb/challenges/interseting-subsets/problem
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

int N,K;
int a[100009];
int dp[100009][11];
const int MOD = 1e9 + 7;
int recurse(int pos,int rem) {
	if(pos == N + 1 && rem == 0) return 1;
	if(pos == N + 1 && rem != 0) return 0;
	int res = 0;
	if(dp[pos][rem] != -1) return dp[pos][rem];
	// exclude a[pos]
	res += recurse(pos + 1,rem)%MOD;
	//cout <<"1 :: "<<res << endl;
	// include a[pos]
	res = (res + recurse(pos + 1, (rem + a[pos])%K ))%MOD;
	//cout <<"2 :: "<<res << endl;

	//cout <<pos<<" "<<rem<<" returns "<<res<<endl; 
	return dp[pos][rem] = res;
}

void solve() {
	cin >> N >> K;
	for(int i = 1;i<=N;i++) {
		cin >> a[i];
	}
	memset(dp,-1,sizeof dp);
	int ans = recurse(1,0);
	cout << ans << endl;
}



