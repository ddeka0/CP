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
int c_sum[510];
void solve() {
	int T,n,k,m;
	cin >> T;
	for(int q = 1;q<=T;q++) {
		cin >> n >> k >> m;
		for(int i = 1,x;i<=m;i++) {
			cin >> x;
			c_sum[i] = c_sum[i - 1] + x;
		}
		cout << lower_bound(c_sum + 1,c_sum + m + 1,k) - (c_sum + 1) + 1 << endl;
	}
}