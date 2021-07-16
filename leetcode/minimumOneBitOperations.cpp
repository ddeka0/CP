#include <bits/stdc++.h>
//#include <bits/stdc++.h>
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n <= 1) return n;
        std::unordered_map<long long,long long> dp;
        long long int N = n;
        
        dp[0] = 0;
        dp[1] = 1;

        long long ans = 0;
        for(int i = 1;i<=32;i++) {
            bool iMinusOneBit = (1LL<<(i-1))&N;
            if(iMinusOneBit) {
                bool ithBit = ((1LL<<i)&N);
                int prev = ithBit*ans;
                ans = ithBit + dp[1LL<<(i-1)] + prev;
                N = N & (~(1LL<<i));
            }
            dp[1LL<<i] = 1 + 2*dp[1LL<<(i-1)];
        }
        return (int)(ans);
    }
};