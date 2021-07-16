#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int nEvents = events.size();
        // max size of this 2D table will be 10^6 only
        // which will be ok > dont cry!
        vector<vector<int>> dp(nEvents+1,vector<int>(k+1,0));

        std::sort(events.begin(),events.end());

        // events[nEvents - 1] is the last event to start

        for(int e = 1;e <=k;e++) {
            dp[nEvents - 1][e] = events[nEvents - 1][2];
        }

        for(int i = nEvents - 2;i>=0;i--) {
            for(int e = 1;e<=k;e++) {
                
                // skip this event
                dp[i][e] = dp[i+1][e];

                // take this event
                int thisEventEndTime = events[i][1];
                int thisEventValue = events[i][2];
                int restValue = 0;
                
                auto nextIdx = std::lower_bound(events.begin(),events.end(),thisEventEndTime,
                    [](const vector<int>& a,int b) {
                        return a[0] <= b;
                    }) - events.begin();
                
                std::cout <<"query indx = "<<i<<" resIdx = "<<nextIdx<<" end was = "<<thisEventEndTime<<std::endl;

                if(nextIdx < nEvents - 1) {
                    restValue = dp[nextIdx][e - 1];
                }

                dp[i][e] = max(dp[i][e],thisEventValue + restValue);
            }
        }


        return dp[0][k];
    }
};