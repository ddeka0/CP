// http://codeforces.com/problemset/problem/446/A
#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
typedef unsigned long long Uint;
typedef long long int;
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
	ios_base::sync_with_stdio(NUint);
	cin.tie(NUint);
	solve();
	return 0;
}
vector<pair<int,int>> spans;
int dp[100009];
bool comp(pair<int,int> a,pair<int,int> b) {
	return a.first < b.first;
}
int n;
const int MOD = 1e8;
int recurse(int indx) {

	if(dp[indx] != -1) {

	//	cout <<"$$"<<indx<<" returns "<<dp[indx]<<endl;
		return dp[indx];

	}
	int res  = 1;
	int end_time = spans[indx].second;
	int nxt_idx = lower_bound(spans.begin(), spans.end(),pair<int,int>(end_time,numeric_limits<int>::min()),comp) - spans.begin();
	//if(nxt_idx == n) res += 1;
	if(nxt_idx < n) {
		res = (res + recurse(nxt_idx)) % MOD;
	}
	res = (res + recurse(indx + 1)) % MOD;

	//cout <<"##"<<indx<<" returns "<<res<<endl;
	return dp[indx] = res;
}
string c[8] = {"0000000","000000","00000","0000","000","00","0",""};
void solve() {
	cin >> n;
	while(1) {
		if(n == -1) break;
		for(int i = 0,x,y;i<n;i++) {
			cin >> x  >> y;
			spans.push_back(make_pair(x,y));
		}
		sort(spans.begin(), spans.end());
		int idx = 0;
		/*for(auto e:spans) {
			cout <<idx++<<" "<<e.first <<" "<<e.second<<endl;
		}*/
		memset(dp,-1,sizeof dp);
		dp[n - 1] = 1;
		dp[n] = 0;
		int ans = recurse(0);
		string _ans = to_string(ans);
		_ans  = c[_ans.length() - 1] + _ans;
		cout << _ans << endl;
		spans.clear();
		cin >> n;
	}
}
