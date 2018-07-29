#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = (int)(grid.size());
        int n = (int)(grid[0].size());
        vector<int> dp(m + 2,0);
        for(int col = 1;col<=n;col++) {
            for(int row = 1;row<=m;row++) {
                if(col == 1) {
                    dp[row] = dp[row - 1] + grid[row - 1][col - 1];
                }else if(row == 1) {
                    dp[row] += grid[row - 1][col - 1];
                }else {
                    dp[row] = min( dp[row] , dp[row - 1]) + grid[row - 1][col - 1];
                }
            }
        }
        return dp[m];    
    }
};