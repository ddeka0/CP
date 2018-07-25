// http://codeforces.com/contest/987/problem/B
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
int x,y;
void solve() {
	cin >> x >> y;
	string ans = "";
	if(x == 1 && y != 1) {
		ans += "<";
	}else if (x != 1 && y == 1) {
		ans += ">";
	}else if(x == 1 && y == 1) {
		ans += "=";
	}else {
		long double L = y/(x*1.0);
		long double R = logl(y*1.0) / logl(x*1.0);
		if(L < R) {
			ans += "<";
		}else if(L > R) {
			ans += ">";
		}else {
			ans += "=";
		}		
	}
	cout << ans << endl;
}