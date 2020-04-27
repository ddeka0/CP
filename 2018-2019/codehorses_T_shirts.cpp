// http://codeforces.com/problemset/problem/665/C
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
4. For 2D matrix : if possible try to store max/min/best/ values row wise for considering all cols
5. if the answer really exists for a query: then draw the possible structure and observe the property
6. minimum no of someting to be changed ?? visualize what is the final scenario and find out some maximum value of some quantity
*/
/* template code ends */

void solve();
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	solve();
	return 0;
}
std::map<string, int> Map1;
std::map<string, int> Map2;
int n;
void solve() {
    cin >> n;
    string s;
    for(int i = 1;i<=n;i++) {
        cin >> s;
        Map1[s]++;
    }
    for(int i = 1;i<=n;i++) {
        cin >> s;
        Map2[s]++;
    }
    int ans = 0;
    for(auto e:Map1) {
        ans += abs(e.second - Map2[e.first]);
    }
    cout << ans << endl;
}
