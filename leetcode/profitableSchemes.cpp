#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {

        long long dp[50][50][50]{};
        
        const long long MOD = 1e9 + 7;
        
        int TotalOptions = group.size();
        int MaxGroupCnt = n;

        for(int i = 0;i<=MaxGroupCnt;i++) {
            dp[0][0][i] = 1;
        }

        for(int idx = 1;idx<=TotalOptions;idx++) { // using 1 based indexing

            int thisProfit = profit[idx - 1];
            int thisGroupCnt = group[idx - 1];

            for(int prevProfit = 0;prevProfit <= minProfit;prevProfit++) {
                for(int prevGroupCnt = 0;prevGroupCnt <= MaxGroupCnt;prevGroupCnt++) {
                    
                    // without taking this option/group/profit
                    dp[idx][prevProfit][prevGroupCnt] += dp[idx - 1][prevProfit][prevGroupCnt];

                    // with taking this option/group/profit
                    // update profit and group cnt
                    int nextProfit = min(prevProfit + thisProfit,minProfit);
                    int nextGroupCnt = prevGroupCnt + thisGroupCnt;

                    if(nextGroupCnt <= MaxGroupCnt) {
                        dp[idx][nextProfit][nextGroupCnt] = 
                            (dp[idx][nextProfit][nextGroupCnt] 
                            + dp[idx-1][prevProfit][prevGroupCnt])%MOD;
                        std::cout <<"idx = "<<idx<<" nextProfit = "<<nextProfit
                            <<" nextGroupCnt = "<<nextGroupCnt
                            <<" "<<dp[idx][nextProfit][nextGroupCnt] << std::endl;
                    }
                    

                }
            }
            std::cout <<">>"<<std::endl;
            for(int i = 0;i<=minProfit;i++) {
                for(int j = 0;j<=MaxGroupCnt;j++) {
                    std::cout << dp[idx][i][j] <<" ";
                }
                std::cout << std::endl;
            }
        }
        int ans = static_cast<int>(dp[TotalOptions][minProfit][MaxGroupCnt]);
        return ans;
    }
};

/*
5
3
[2,2]
[2,3]
10
5
[2,3,5]
[6,7,8]
1
1
[1,1,1,1,2,2,1,2,1,1]
[0,1,0,0,1,1,1,0,2,2]
*/
int main() {
    Solution s;
    vector<int> group = {1,1,1,1,2,2,1,2,1,1};
    vector<int> profit = {0,1,0,0,1,1,1,0,2,2};
    int ans = s.profitableSchemes(1,1,group,profit);
    std::cout << ans << std::endl;
    
}