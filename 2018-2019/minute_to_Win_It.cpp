// http://codeforces.com/contest/992/problem/C
#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
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
int dp[100009];
int a[100009];
void solve() {
	int n,k;
	cin >> n >> k;
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
	}
	map<int,int>Map;
	for(int i = 1;i<=n;i++) Map[a[i] - k*i]++;
	int ans = 1e9;
	for(auto e:Map) ans = min(ans,n - e.second);
	cout << ans <<endl;
}