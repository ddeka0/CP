#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ch[200];
    int res;
    vector<int> dp;
    int n;
    int numDecodings(string s) {    // s is a string a digits
        n = (int)(s.length());
        dp.resize(n + 10,-1);
        int ans = recurse(s,0);
        return ans;
    }
    int recurse(string s,int idx) {
        //cout << "entry "<< idx << endl;
        if(s[idx] == '0') return 0;
        if(idx >= n) return 1;
        if(dp[idx] != -1) return dp[idx];
        int res = 0;
        if( (idx == n-1) and (s[idx] != '0')) return 1;
        if( (s[idx + 1] != '0') and ((idx + 1) < n)  ) {
            res += recurse(s,idx + 1);
        }
        if((idx + 2) <=n) {
          //  cout << "hi" << endl;
            int num = stoi(s.substr(idx,2));
            if(num <= 26) {
                res += recurse(s,idx + 2);
            }
        }
        //cout << idx <<" returns "<<res << endl;
        return dp[idx] = res;
    }
};