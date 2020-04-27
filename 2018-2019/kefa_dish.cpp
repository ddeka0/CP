#include <bits/stdc++.h>
using namespace std;
int a[20];
int c[20][20];
long long dp[20][1<<20];
int n,m,k;
	
long long recurse(int curr,unsigned int mask) {
	if(__builtin_popcount(mask) == m) {
		return 0;
	}
	if(dp[curr][mask] != -1) return dp[curr][mask];
	long long res = 0;
	for(int node=0;node<n;node++) {
		if( !(mask &(1<<node)) ) {
			res = max(res, recurse(node,mask | (1<<node)) + a[node] + c[curr+1][node+1]);
		}
	}
	return dp[curr][mask] = res;
}

int main() {
	cin >> n >> m >> k;
	for(int i = 0;i<n;i++) {
		cin >> a[i];
	}
	for(int i = 0;i<k;i++) {
		int x,y,z;
		cin >> x >> y >> z;
		c[x][y] = z;
	}	
	memset(dp,-1,sizeof dp);
	long long res = -1e9;
	unsigned int mask = 0;
	for(int node = 0;node<n;node++) {
		res = max(res , recurse(node,mask|(1<<node)) + a[node]);
	}
	cout << res << endl;
}
