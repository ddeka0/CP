#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
		
		int dp[301][11];

		for(int i = 0;i<301;i++) {
			for(int j = 0;j<11;j++) {
				dp[i][j] = INT_MAX;
			}
		}

		int n = jobDifficulty.size();
		
		if(n < d) return -1;

		dp[0][1] = 0; // 1 day and no job

		for(int i = 1;i<=n;i++) {
			// i jobs in one day 
			dp[i][1] = max(dp[i-1][1],jobDifficulty[i-1]);
		}
		
		for(int k = 2;k<=d;k++) {
			// solve for kth day
			stack<int> Stack;
			
			for(int i = k;i<=n;i++) { // not check first k-1 jobs
				// consider from kth job
				int currJobDiff = jobDifficulty[i - 1];

				dp[i][k] = dp[i - 1][k - 1] + currJobDiff;

				while(!Stack.empty() && jobDifficulty[Stack.top() - 1] <= currJobDiff) {
					int j = Stack.top();
					dp[i][k] = min(dp[i][k], dp[j][k] - jobDifficulty[j - 1] + currJobDiff); 
				}

				if(!Stack.empty())
					dp[i][k] = min(dp[i][k],dp[Stack.top()][k]);

				Stack.push(i);
			}
		}

		return dp[n][d];
	}
};