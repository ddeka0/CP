class Solution {
public:
    int dp[110][110];
    int N;
    int K;
    int recurse(int country,int weeks,vector<vector<int>> &flights,vector<vector<int>> &days) {
        if(dp[country][weeks] != -1) return dp[country][weeks];
        for(int next_country = 0;next_country<N;next_country++) {
            if(flights[country][next_country]) {
                res = max(res, recurse(next_country))
            }
        }
        return dp[country][weeks] = res;
    }

    int maxVacationDays(vector<vector<int>> &flights,vector<vector<int>> &days) {
        N = (int)flights.size();
        K = (int)days[0].size();





        return ans;
    }
};
