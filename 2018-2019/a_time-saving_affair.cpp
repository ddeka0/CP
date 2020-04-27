// http://codeforces.com/contest/992/problem/C
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
#define inf 1e9
#define ff first
#define ss second
vector<pair<int,int>> g[10001];
set<pair<int,int>> Heap;
int memo[10001][101];
void solve() {
	int n,k,m;
	cin >> n;
	cin >> k;
	cin >> m;
	for(int i = 1,u,v,t;i<=m;i++) {
		cin >> u >> v >> t;
		g[u].push_back(make_pair(t,v));
		g[v].push_back(make_pair(t,u));
	}
	std::vector<int> d(n + 1,inf);
	d[1] = 0;
	Heap.insert(make_pair(0,1));
	while(!Heap.empty()) {
		auto e = *(Heap.begin());
		Heap.erase(Heap.begin());
		int u = e.ss;
		for(auto p:g[u]) {
			int v = p.ss;
			int t = d[u] + p.ff;
			int y = t / k;
			int wait_time_at_v = 0;
			if(y&1 && (v != n)) {
				wait_time_at_v = k - (t%k);
			}
			t += wait_time_at_v;
			if(d[v] > t) {
				if (d[v] != inf)
					Heap.erase(Heap.find(make_pair(d[v], v)));
				d[v] = t;
				memo[v][wait_time_at_v] = t;
				Heap.insert(make_pair(t,v));
			}
		}
	}
	cout << d[n] << endl;
}








