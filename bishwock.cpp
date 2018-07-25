// http://codeforces.com/contest/991/problem/C
#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
template<typename T>
void LOG(T const& t) {
	std::cout <<t<<endl;
}
template<typename First, typename ... Rest>
void LOG(First const& first, Rest const& ... rest) {
	std::cout << first<<" "; LOG(rest ...);
}
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
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
int n;
long long dp[110][4];
long long recurse(int i,int m) {
	if(i == n - 1) {
		return 0;
	}

	if(dp[i][m] != -1) return dp[i][m];
	long long res = 0;

	if(m == 0) {

		if(i < (n - 1) && a[i] == '0' && b[i] == '0' && b[i+1] == '0') res = 1 + recurse(i+1,2);
		if(i < (n - 1) && a[i] == '0' && b[i] == '0' && a[i+1] == '0') res = max(res, 1 + recurse(i+1,1));
		if(i < (n - 1) && a[i+1] == '0' && b[i+1] == '0' && b[i] == '0') res = max(res, 1 + recurse(i+1,3));
		if(i < (n - 1) && a[i+1] == '0' && b[i+1] == '0' && a[i] == '0') res = max(res, 1 + recurse(i+1,3));
		if(i < (n - 1)) res = max(res,recurse(i+1,0));

	}

	if(m == 1) {

		if(i < (n - 1) && a[i + 1] == '0' && b[i + 1] == '0' && b[i] == '0') res = 1 + recurse(i+1,3);
		if(i < (n - 1))	res = max(res, recurse(i+1,0));

	}

	if(m == 2) {

		if(i < (n - 1) && a[i + 1] == '0' && b[i + 1] == '0' && a[i] == '0') res = 1 + recurse(i+1,3);
		if(i < (n - 1)) res = max(res, recurse(i+1,0));

	}

	if(m == 3) {

		if(i < (n - 1)) res = recurse(i+1,0);

	}
	return dp[i][m] = res;
}
void solve() {
	cin >> a;
	cin >> b;
	n = a.size();
	memset(dp,-1,sizeof dp);
	long long ans = recurse(0,0);
	cout << ans << endl;
}
