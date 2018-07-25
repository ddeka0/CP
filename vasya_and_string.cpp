// http://codeforces.com/problemset/problem/282/C
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
2. handle special case carefully. Avoid making the loop generic for special cases
3. order not needed : sort it
4. For 2D matrix : if possible try to store max/min/best/ values row wise for considering all cols
5. if the answer really exists for a query: then draw the possible structure and observe the property
*/
/* template code ends */
void solve();
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	solve();
	return 0;
}

unordered_map<int,int> one_sum;
unordered_map<int,int> zero_sum;
vector<int> v;

#define OFST 	2
#define ONE 	1
#define ZERO 	0
int dp[100009][2];
int a[100009];
int b[100009];

void solve() {
	int n,k;
	string str;
	cin >> n >> k;
	cin >> str;
	for(int i = 0;i<str.length();i++) {
		if(str[i] == 'a') v.push_back(0);
		else v.push_back(1);
	}
	a[0] = v[0];	
	int sum = v[0];
	if(sum == 1) one_sum[1] = 0 + OFST;
	for(int i = 1;i<v.size();i++) {
		sum = sum + v[i];		
		a[i] = a[i - 1] + v[i];
		if(one_sum[sum] == 0 && sum > 0) {
			one_sum[sum] = i + OFST;
		}
	}
	sum = (v[0] == 0);
	b[0] = (v[0] == 0);
	if(sum == 1) zero_sum[1] = 0 + OFST;
	for(int i = 1;i<v.size();i++) {
		b[i] = b[i - 1] + (v[i] == 0);
		if(v[i] == 0) {
			sum = sum + 1;
			if(zero_sum[sum] == 0) {
				zero_sum[sum] = i + OFST;
			}
		}
	}
	int ans = -1;
	// make 0 substring
	for(int i = 0;i<v.size();i++) {
		if( (a[i] - k) > 0) {
			int indx = one_sum[a[i] - k] - OFST;
			dp[i][ONE] = i - indx;
		}else {
			dp[i][ONE] = i + 1;
		}
		ans = max(ans,dp[i][ONE]);
	}
	// make 1 substring
	for(int i = 0;i<v.size();i++) {
		if( (b[i] - k) > 0) {
			int indx = zero_sum[b[i] - k] - OFST;
			dp[i][ZERO] = i - indx;
		}else {
			dp[i][ZERO] = i + 1;
		}
		ans = max(ans,dp[i][ZERO]);
	}
	cout << ans << endl;
}



