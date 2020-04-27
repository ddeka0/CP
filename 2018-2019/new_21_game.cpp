class Solution {
public:
	int dp[10009];
	int N,K,W;
	double solve(int val) {
		if(val > N) return 0;
		if(val <= N && val >= K) return 1.0;

		if(dp[val] != -1) return dp[val];
		`
		double res = 0.0;
		for(int w = 1;w<=W;w++) {
			if(val + w > N) continue;
			res += (1.0 / (W*1.0))*(solve(val + w) );
		}
		return dp[val] = res;
	}
	
	double new21Game(int N, int K, int W) {
		this.N = N;
		this.K = K;
		this.W = W;
		memset(dp,-1,sizeof dp);
		cout << solve(0) << endl;
	}
};