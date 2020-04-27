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

long long n,k;
long long total;
long long a[100009];
long long sum[100009];

map<long long,long long> Map;

void solve() {
	cin >> n >> k >> total;
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
	}
	sum[1] = a[1];
	for(int i = 1;i<=n;i++) sum[i] = sum[i - 1] + a[i];
	for(int i = k;i<=n;i++) {
		Map[sum[i] - sum[i - k]]++;
	}
	long long ans = 0;
	for(int i = k;i<=n;i++) {
		long long got = sum[i] - sum[i - k];
		if(total%got == 0) {
			long long need = total / got;
			ans += Map[need];
		}	
	}
	cout << ans << endl;
}


