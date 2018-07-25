// https://www.hackerrank.com/contests/m-tech-cse-2017-practice-test-dp-special/challenges/rectangle-game
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
const int MOD = 1e9 + 7;
int a[1000009];
int b[1000009];
int n;
void solve() {
	cin >> n;
	a[1] = 1;a[2] = 2;b[1] = 1;b[2] = 2;
	int ans = 0;
	if(n == 1 || n == 2) {
		ans = n;
	}else {
		for(int i = 3;i<=n+5;i++) {
			a[i] = a[i - 1] + a[i - 2] + 2*b[i - 2];
			b[i] = a[i - 1] + b[i - 1];
		}
		ans = a[n];
	}
	cout <<ans << endl;
}



