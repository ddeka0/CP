#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n + 2,1);
        for(int i = 0;i<n;i++) {
            arr[1 + i] = nums[i];
        }
        int dp[510][510];
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<=n + 1;i++) {
            dp[i][i] = arr[i];
        }
        for(int L = 2;L<=n + 2;L++) {
            for(int i = 0;i + L - 1 <=n + 1;i++) {
                // need to calculate dp[i][i + L - 1]
                int j = i + L - 1;
                

            }
        }
    }
};

