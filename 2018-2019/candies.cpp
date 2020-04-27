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
long long n;
bool check(long long k) {
	long long m = n; 
	long long V = 0;
	while(m > 0) {
		V += min(m,k)
;		m = m - min(m,k);
		m = m - m/10;
	}
	if(2*V >= n) {
		return true;
	}
	return false;
}
void solve() {
	cin >> n;
	long long l = 1;
	long long r = n;
	int i = 0;
	long long ans = 0;
	while(i++ < 65) {
		long long mid = (l+r)/2;
		if(mid) {
			if(check(mid)) {
				ans = mid;
				r = mid - 1;
			}else {
				l = mid + 1;
			}
		}
	}
	cout << ans << endl;
}
