// http://codeforces.com/problemset/problem/282/C
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
string s1,s2;
void solve() {
	cin >> s1;
	cin >> s2;
	string ans = "";
	if(s1 == s2) {
		ans += "YES";
	}else if(s1.length() != s2.length()) {
		ans += "NO";
	}else {
		if((s1.find("1") == string::npos) || (s2.find("1") == string::npos)) {
			ans += "NO";
		}else {
			ans += "YES";
		}
	}
	cout << ans << endl;
}


