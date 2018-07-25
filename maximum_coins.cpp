// https://www.hackerrank.com/contests/m-tech-cse-2017-practice-test-dp-special/challenges/maximum-coins
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
int T,n;
int a[100009];
int cnt[100009];
LL dp[100009];
vector<int> v;
int recurse(int i) {
	if(i == n + 1) return 0;
	if(dp[i] != -1) return dp[i];
	int res = 0;
	for(int j = i;j<=n;j++) {
		int x = c_sum[j] - c_sum[i - 1];
		res = max(res , (j - i + 1)*(x > 0) + recurse(j + 1) );
	}
	return dp[i] = res;
}
void solve() {
	cin >> n;
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
		if(cnt[a[i]] == 0) {
			v.push_back(a[i]);
		}
		cnt[a[i]]++; 
	}
	// v contains the distinct elements only
	

}


