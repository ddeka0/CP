#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
        int n = grid.size();
        int m = grid[0].size();
        dp[n-1][m-1] = grid[n-1][m-1];
        for(int i = n-2;i>=0;i--) {
            dp[i][m-1] = grid[i][m-1] + dp[i+1][m-1];        
        }
        for(int j = m-2;j>=0;j--) {
            dp[n-1][j] = grid[n-1][j] + dp[n-1][j+1];
        }        
        for(int i = n - 2;i>=0;i--) {
            for(int j = m-2;j>=0;j--) {
                dp[i][j] = grid[i][j] + min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};
int main() {
    Solution s;
    vector<vector<int>> v;
    v.push_back(vector<int>{1,2,5});
    v.push_back(vector<int>{3,2,1});
    cout << s.minPathSum(v) << endl;
}