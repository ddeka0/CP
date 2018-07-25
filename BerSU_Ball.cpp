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
int n,m;
int a[110],b[110];
int dp[110][110];
int recurse(int x,int y) {
	if(x > n || y > m) return 0;
	if(x == n || y == m) {
		if(abs(a[x] - b[y]) <=1) {
			return dp[x][y] = 1;
		}
	}
	if(dp[x][y] != -1) return dp[x][y];
	int res = 0;
	if(abs(a[x] - b[y]) <= 1) {
		res += 1;
		res = res + recurse(x+1,y+1);
	}else {
		res = max(recurse(x,y+1) , recurse(x+1,y));
	}
	return dp[x][y] = res;
}
void solve() {
	cin >> n;
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	cin >> m;
	for(int i = 1;i<=m;i++) {
		cin >> b[i];
	}
	sort(b+1,b+m+1);
	memset(dp,-1,sizeof dp);
	int ans = recurse(1,1);
	cout << ans << endl;
}