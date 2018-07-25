// http://codeforces.com/problemset/problem/446/A
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
int a[100009];
int right_most[100009];
int left_most[100009];
void solve() {
	cin >> n;
	for(int i = 0;i<n;i++) {
		cin >> a[i];
	}
	if(n <= 2) {
		cout << n << endl;
		return;
	}
	right_most[n - 1] 	= 1; 		// len
	left_most[0] 		= 1;		// len
	for(int i = 1,j = n-2;i<n;i++,j--) {
		left_most[i] = (a[i] > a[i - 1])?left_most[i - 1] + 1:1;
		right_most[j] = (a[j] < a[j + 1])?right_most[j + 1] + 1:1; 
		//cout << "left_most :"<<i<<" "<<left_most[i]<<" right_most :"<<j<<" "<<right_most[j]<<endl;
	}
	int ans = 0;
	ans = max(ans,right_most[0]);
	ans = max(ans,left_most[n-1]);
	
	for(int i = 1,j;i<n-1;i++) {
		if(a[i - 1] + 1 < a[i + 1]) {
			ans = max(ans, left_most[i - 1] + right_most[i + 1] + 1);
		}
		ans = max(ans,right_most[i] + 1);
		ans = max(ans,left_most[i] + 1);
	}

	cout << ans << endl;
}



