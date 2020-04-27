//http://codeforces.com/problemset/problem/777/C
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
int a[100009];
void solve() {
	int n;
	cin >> n;
	for(int i = 0;i<n;i++) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	LL start_box_height = a[0];
	for(int i = 0,w,h;i<m;i++) {
		cin >> w >> h;
		LL ans = max(a[w - 1]*1LL,start_box_height);
		cout << ans << endl;
		start_box_height = ans + h;
	}
}
