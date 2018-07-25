// https://www.hackerrank.com/contests/mtech-placement-dpbasicspartb/challenges/make-the-strings-equal
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
string a,b;
int n,m;
int dp[1009][1009];
int recurse(int x,int y) {
	if(x == n && y < m) {
		return dp[x][y] = m - y;
	}else if(x < n && y == m) {
		return dp[x][y] = n - x;
	}else if(x == n && y == m) {
		return dp[x][y] = 0;
	}
	if(dp[x][y] != -1) return dp[x][y];
	int res = 1e9;
	if(a[x] == b[y]) {
		res = recurse(x+1,y+1);
	}else {
		res = min( recurse(x+1,y) + 1, recurse(x,y+1) + 1 );
	}
	return dp[x][y] = res;
}

void solve() {
	cin >> a >> b;
	n = a.length();
	m = b.length();
	memset(dp,-1,sizeof dp);
	int ans = recurse(0,0);
	cout << ans << endl;
}










