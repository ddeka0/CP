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
const long long MOD = 1e9+7;
long long exp(long long k) {
	long long res = 1;
	long long x = 2;
	while(k > 0) {
		if(k&1) {
			res = (res * x)%MOD;
		}
		k = k / 2;
		x = (x*x)%MOD;
	}
	return res;
}
void solve() {
	long long x,k;
	cin >> x >> k;
	if(x == 0) {
		cout << 0 << endl;
		return;
	}
	long long p = exp(k);
	long long ans = ((p *1LL* (  (1LL*2*(x%MOD))%MOD   - 1 + MOD ) % MOD)%MOD + 1) % MOD;
	cout << ans << endl;
}

