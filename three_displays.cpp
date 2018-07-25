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
int n;
LL s[3009];
LL c[3009];
void solve() {
	cin >> n;
	for(int i = 0;i<n;i++) {
		cin >> s[i];
	}
	for(int i = 0;i<n;i++) {
		cin >> c[i];
	}
	bool solution_found = false;
	LL ans = 1e12;
	for(int mid = 1;mid<n-1;mid++) {
		bool left_found = false;
		LL left_cost = 1e12;
		for(int l = 0;l<mid;l++) {
			if(s[l] < s[mid]) {
				left_cost = min(left_cost,c[l]);
				left_found = true;
			}
		}
		bool right_found = false;
		LL right_cost = 1e12;
		for(int r = mid+1;r<n;r++) {
			if(s[r] > s[mid]) {
				right_cost = min(right_cost,c[r]);
				right_found = true;
			}
		}
		if(right_found && left_found) {
			ans = min(ans,right_cost + left_cost + c[mid]);
			solution_found = true;
		}
	}

	if(solution_found) {
		cout << ans << endl;
	}else {
		cout << "-1"<< endl;
	}
}