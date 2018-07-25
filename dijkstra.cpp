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

#define inf 1e15
#define ff first
#define ss second
vector<pair<int,int>> g[100009];
set<pair<int,int>> Heap;
void solve() {
	int n,m;
	cin >> n;
	cin >> m;
	for(int i = 1,u,v,t;i<=m;i++) {
		cin >> u >> v >> t;
		g[u].push_back(make_pair(t,v));
		g[v].push_back(make_pair(t,u));
	}
	std::vector<long long> d(n + 1,inf);
	std::vector<int> paren(n + 1,-1);
	d[1] = 0;
	Heap.insert(make_pair(0,1));
	while(!Heap.empty()) {
		auto e = *(Heap.begin());
		Heap.erase(Heap.begin());
		int u = e.ss;
		for(auto p:g[u]) {
			int v = p.ss;
			if(d[v] > p.ff + d[u]) {
				if (d[v] != inf)
					Heap.erase(Heap.find(make_pair(d[v], v)));
				d[v] = p.ff + d[u];
				paren[v] = u;
				Heap.insert(make_pair(d[v],v));
			}
		}
	}
	
	if(d[n] != inf) {
		bool done = false;
		int x = n;
		std::vector<int> path;
		path.push_back(n);
		while(!done) {
			path.push_back(paren[x]);
			if(paren[x] == 1) done = true;
			x = paren[x];
		}
		for(int i = (int)(path.size()  - 1);i>=0;i--) {
			cout << path[i] <<" ";
		}
		cout << endl;
	}else {
		cout <<"-1"<<endl;
	}
}




