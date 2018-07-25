#include <bits/stdc++.h>
using namespace std;
vector<int> adj[209];
bool seen[209];
char color[209];
bool check(int root , bool col) {
	seen[root] = true;
	color[root] = col;
	bool ans = true;
	for(int v:adj[root]) {
		if(!seen[v]) {
			ans = ans && check(v,!col);
		}else {
			if(color[v] == col) {
				ans = false;
			}
		}
	}
	return ans;
}
int main() {
	int n,m;
	while(true) {
		cin >> n;
		if(n == 0) break;
		cin >> m;
		for(int i = 0,v,u;i<m;i++) {
			cin >> u >>v ;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		memset(color,-1,sizeof color);
		if(check(0,true)) {
			cout << "BICOLORABLE." << endl;
		}else {
			cout << "NOT BICOLORABLE." << endl;
		}
	}
	return 0;
}