
int recurse(int curr_city,int mask) {	
	if(mask == (1<<n) - 1) {
		return dist[curr_city][n];
	}
	int res = inf;
	for(int city = 1;city<20;city++) {
		if( !(mask & (1<<city)) ) {
			res = min(res,recurse(mask | (1<<city),i) + dist[curr_city][city]);
		}
	}
	return dp[curr_city][mask] = res;	
}

int main() {
	int mask = 0; 00000000000000000
	int n = 20; // we need to start from 1 and go to 20
				// we need to cover all other 18 cities
	mask = mask | (1<<0);
	for(int next = 0 ; next<n ; next++) {
		if(next is off) {
			res = max(res,recurse(next,mask | (1<<next)) + dist[0][next]);
		}
	}
	cout << res << endl;
}