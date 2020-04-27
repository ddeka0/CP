#include <bits/stdc++.h>
using namespace std;
#define inf 	1e9

vector<pair<int,int>> loc;
int dist[20][20];
int dp[20][1<<12];
int N;

int recurse(int curr,unsigned int mask) {
	if(__builtin_popcount(mask) == N+2) {
		return dist[curr][1];
	}
	
	if(dp[curr][mask] != -1) return dp[curr][mask];
	int res = inf;
	
	for(int node = 0;node < N+2;node++) {
		if( !(mask &(1<<node)) ) {
			res = min(res, recurse(node,mask | (1<<node)) + dist[curr][node] );
		}
	}
	return dp[curr][mask] = res;
}
int main() {
	int T;
	cin >> T;
	for(int q = 1;q<=T;q++) {

		loc.clear();
		cin >> N;
		int x,y;
		cin >> x >> y;
		loc.push_back(make_pair(x,y));
		cin >> x >> y;
		loc.push_back(make_pair(x,y));
		for(int i = 1;i<=N;i++) {
			cin >> x >> y;
			loc.push_back(make_pair(x,y));
		}
		
		for(int i = 0;i<N+2;i++) {
			for(int j = 0;j<N+2;j++) {
				dist[i][j] = inf;
			}
		}

		// this section calculated the dist[u][v]
		// pair wise distances
		for(int k = 0;k<N+2;k++) {
			for(int i = 0;i<N+2;i++) {
				for(int j = 0;j<N+2;j++) {
					int p = abs(loc[i].first - loc[k].first) + abs(loc[i].second - loc[k].second);
					int q = abs(loc[j].first - loc[k].first) + abs(loc[j].second - loc[k].second);
					dist[i][j] = min( dist[i][j], p + q);
				}
			}
		}

		unsigned int mask = 0;
		mask = mask | (1<<1) | (1<<0);

		int res = inf;
		memset(dp,-1,sizeof dp);

		res = recurse(0,mask);

		cout << res << endl;

	}
}


