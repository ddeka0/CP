#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int>dp;
    int longestValidParentheses(string s) {
        int n = (int)(s.length());
        dp.resize(n + 10);
        int OFFSET = 2;
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 0;
        int maxx = 0;
        for(int i=1;i<n;i++) {
            if(s[i] == '(') {
                dp[i+OFFSET] = 0;
            }else {
                if(s[i-1] == '(') {
                    dp[i+OFFSET] = 2 + dp[i - 2 + OFFSET];
                    maxx = max(maxx,dp[i+OFFSET]);
                }else {
                    if((i - dp[i - 1 + OFFSET]) > 0) {
                        if(s[i - dp[i - 1 + OFFSET] - 1] == '(') {
                            dp[i+OFFSET] = 2 + dp[i - 1 + OFFSET] + dp[i - dp[i - 1 + OFFSET] - 2 + OFFSET];
                            maxx = max(maxx,dp[i+OFFSET]);
                        }
                    }
                }
            }
        }
        return maxx;
    }
};