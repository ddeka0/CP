#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        vector<int> dp(stations.size() + 1,-1);
        // dp[i] = maximum distance using i no of stations
        // dp[0] = maximum distace using no stations (just by using startfuel)
        dp[0] = startFuel;
        for(int i = 1;i<=stations.size();i++) {
            // going to include ith station
            for(int j = 0;j<i;j++) {
                // So, we can take, -> (0 stations + ith ) Or (1 station + ith) Or (2 stations + ith) ..etc ...
                if(dp[j] >= stations[i-1][0]) { // it means station i is reachable from station j
                    dp[j+1] = max(dp[j+1],dp[j] + stations[i-1][1]);
                }
            }
        }
        int ans = -1;
        for(int i = 0;i<dp.size();i++) {
            if(dp[i] >= target) {
                ans = i;
            }
        }
        return ans;
    }
};

int main() {

}