class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        
        for(int e:nums) sum += e;
        
        if(sum&1) return false;
        
        sum = sum >> 1;
        
        int n = nums.size(); 
        
        // bool dp[sum + 1][n+1];
        
        // for(int i = 0; i <= n; i++)
        //     dp[0][i] = true;
        // for(int i = 1; i <= sum; i++)
        //     dp[i][0] = false;
        
        // for(int i = 1; i <= sum; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         dp[i][j] = dp[i][j-1];
        //         if (i >= nums[j-1])
        //             dp[i][j] = dp[i][j] || dp[i - nums[j-1]][j-1];
        //     }
        // }
        // return dp[sum][n];  

        bool dp[sum + 1];
        dp[0] = true;
            
        for(int s = 1; s <= sum; s++) { // is requi
            for (int j = 1; j <= n; j++) {
                if (s >= nums[j-1])
                    dp[s] = dp[s] || dp[s - nums[j-1]];
            }
        }

        return dp[sum];
    }
};