#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100009];
vector<pair<int,int>> edges;
int a[100009];
bool seen[100009];
bool dfs(int root) {
	bool ans = true;
	seen[root] = true;
	for(int v:adj[root]) { 
		if(!seen[v]) {
			if(a[root] != a[v]) {
				ans = false;
				break;
			}else {
				ans  = ans && dfs(v);
			}
		}
	}
	seen[root] = false;
	return ans;
}
int main() {
	int n,u,v;
	cin >> n;
	for(int i = 0;i<n-1;i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.push_back(make_pair(u,v));	
	}
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
	}
	bool has_diff = false;
	pair<int,int> edg;
	for(int i = 0;i<n-1;i++) {
		if( a[edges[i].first] != a[edges[i].second] ) {
			edg = edges[i];
			has_diff = true;
			break;
		}
	}
	if(!has_diff) {
		cout << "YES"<< endl;
		cout << "1" <<endl;
	}else {
		bool ok = true;
		seen[edg.first] = true;
		for(int e:adj[edg.first]) ok = ok && dfs(e);
		seen[edg.first] = false;
		if(ok) {
			cout <<"YES"<<endl<< edg.first <<endl;
		}else {
			ok = true;
			seen[edg.second] = true;
			for(int e:adj[edg.second]) ok = ok && dfs(e);
			seen[edg.second] = false;	
			if(ok) cout << "YES"<< endl<< edg.second <<endl;
			else cout << "NO" << endl;
		}

	}

	return 0;
}


