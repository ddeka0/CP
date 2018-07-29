#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string a,b;
    vector<vector<int>> dp;
    int recurse(int i,int j) {
        if(i == a.length() and j < b.length()) {
            return b.length() - j;
        }else if(i < a.length() and j == b.length()) {
            return a.length() - i;
        }else if(i == a.length() and j == b.length()) {
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int res = 1e9;
        if(a[i] == b[j]) {
            res = min( res , recurse(i+1,j+1));
        }else {
            // delete
            res = min(res , 1 + recurse(i+1,j));
            // insert 
            res = min(res , 1 + recurse(i,j+1));
            // replace
            res = min(res , 1 + recurse(i+1,j+1));
        }
        return dp[i][j] = res;
    }
    int minDistance(string word1, string word2) {
        a = word1;
        b = word2;
        dp.resize(a.length() + 1,vector<int>(b.length() + 1,-1));
        cout << dp[0][0] <<endl;
        return recurse(0,0);
    }
};