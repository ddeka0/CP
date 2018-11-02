#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> g[100009];
int main() {
	cin >> n >> m;
	for(int i = 0;i<m;i++) {
		int x,y;
		cin >> x >> y;		// x must be done before y
		g[x].push_back(y);	
		ind[y]++;
	}
	
	for(int node = 1;node<=n;node++) {
		if(ind[node] == 0) {
			Q.push(node);
		}
	}
	if(Q.empty()) {
		return 0;
	}
	int ans = 0;
 	while(true) {
 		if(Q.empty()) {
 			break;
 		}
 		int u = Q.front();
 		ans++;
 		Q.pop();
 		for(int v:g[u]) {
 			ind[v]--;
 			if(ind[v] == 0) {
 				Q.push(v);
 			}
 		}
	}
	cout << ans << endl;
}