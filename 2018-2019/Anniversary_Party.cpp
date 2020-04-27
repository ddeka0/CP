// http://acm.timus.ru/problem.aspx?space=1&num=1039
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

#define TAKE 		1
#define NOT_TAKE 	0
int dp[6009][2];
vector<int> adj[6009];
int a[6009];
int recurse(int root, bool flag) {
	if(dp[root][flag] != -1) return dp[root][flag];
	int res = 0;
	if(adj[root].size() == 0) {
		dp[root][flag] = flag? a[root]>0?a[root]:0 : 0;
		return dp[root][flag];
	}
	else if(flag == TAKE) {
		res = res + (a[root] > 0)*a[root];
		for(int v:adj[root]) {
			res += recurse(v,NOT_TAKE);
		}
	}else {
		for(int v:adj[root]) {
			res += max( recurse(v,TAKE), recurse(v,NOT_TAKE));
		}
	}
	return dp[root][flag] = res;
}
int n;
bool check[6009];
void solve() {
	cin >> n;
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
	}
	int x,y;
	cin >> x >> y;
	memset(check,true,sizeof check);
	while(true) {
		if(x == 0 && y == 0) break;
		check[x] = false;
		adj[y].push_back(x);
		cin >> x >>y;
	}
	int ans = 0;
	for(int i = 1;i<=n;i++) {
		if(check[i]) {
			memset(dp,-1,sizeof dp);
			ans += max( recurse(i,TAKE) , recurse(i,NOT_TAKE) );
		}
	}
	cout << ans << endl;
}
