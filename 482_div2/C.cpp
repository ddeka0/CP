#include <bits/stdc++.h>
using namespace std;
int xx,yy;
bool seen[300009];
void bfs(int s,int t,bool flag,bool ss[]) {
	queue<int>Q;
	Q.push(s);
	seen[s] = true;
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for(int v:adj[u]) {
			if(!seen[v]) {
				seen[v] = true;
				Q.push(v);
				if(v == t) {
					if(!flag) {
						xx = u;
					}else {
						yy = u;
					}	
				}
			}
		}
	}
}

int dfs_count(int root,int obst) {
	int ans = 1;
	if(root == obst) return 0;
	seen_dfs[root] = true;
	for(int v:adj[root]) {
		if(!seen_dfs[v]) {
			ans += dfs_count(v,obst);
		}
	}
	seen_dfs[root] = false;
	return ans;
}

int main() {
	cin >> n >> x >> y;
	for(int i = 0;i<n-1;i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfs(x,y,0);
	memset(seen,false,sizeof seen);
	bfs(y,x,1);
	int x_val = 1,y_val = 1;
	for(int v:adj[x]) {
		x_val += dfs_count(v,xx);
	}
	for(int v:adj[y]) {
		y_val += dfs_count(v,yy);
	}
	cout <<"value of x_val = "<<x_val<<endl;
	cout <<"value of y_val = "<<y_val<<endl;
	unsigned long long int total = n*n - n;
	unsigned long long int deduction = 1;
	deduction += x_val*y_val;
	cout << total - deduction << endl;
	return 0;
}








