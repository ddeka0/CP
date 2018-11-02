#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MOD 1000000007
LL f[100010];
vector<int> g[100010];
void fact_pre() {
	f[0] = f[1] = 1;
	for(int i = 2;i<=100000;i++) {
		f[i] = (i * f[i - 1])%MOD;
	}
}
LL dfs(int node,int parent) {
	if(g[node].size() == 1) {
		return 1;
	}
	LL res = 0;
	for(int v:g[node]) {
		if(v != parent) {
			res = (res * dfs(v,node)) % MOD
		}
	}
	res = ( res * f[g[node].size()] )%MOD;
	return res;
}
int main() {
	int n,m;
	cin >> n >> m;
	for(int i = 1;i<=n;i++) {
		int x;
		int y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	LL ret = dfs(1,-1);
}