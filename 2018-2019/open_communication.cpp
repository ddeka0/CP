// http://codeforces.com/contest/994/problem/D
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
#define ff first
#define ss second
void solve();
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	solve();
	return 0;
}
std::vector<pair<int,int>> a;
std::vector<pair<int,int>> b;
void _swap_
int eq(pair<int,int> x,pair<int,int> y) {
	if(((x.ff == y.ff) && (x.ss == y.ss) ) || ( (x.ff == y.ss) && (x.ss == y.ff) )){
		return 2;
	}
	if( ((x.ff == y.ff) && (x.ss != y.ss) ) || ( (x.ff == y.ss) && (x.ss == y.ff) ) ) {

	}
}
void solve() {
	cin >> n >> m;
	for(int i = 0;i<n;i++) {
		cin >> x >> y;
		a.push_back(make_pair(x,y))
	}
	for(int i = 0;i<n;i++) {
		cin >> x >> y;
		b.push_back(make_pair(x,y))
	}
	for(int i = 0;i<a.size();i++) {
		auto p = a[i];
		for(int j = 0;j<b.size();j++) {
			auto q = b[j];
			if(eq(p,q)) continue;

		}
	}

}