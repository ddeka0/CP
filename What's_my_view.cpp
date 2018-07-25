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
int T,q,n;
int a[100009];
void solve() {

	cin >> T;
	
	for(int q = 1;q<=T;q++) {
		cin >> n;
		for(int i = 0;i<n;i++) {
			cin >> a[i];
		}
		std::vector<int> ans;
		stack<int> ss;
		ss.push(a[n - 1]);
		ans.push_back(0);
		for(int i = n - 2;i>=0;i--) {
			ans.push_back( int(ss.size()) );
			while(!ss.empty() && (a[i] >= ss.top()) ) {
				ss.pop();
			}
			ss.push(a[i]);
		}
		for(int i = n - 1;i>=0;i--) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}