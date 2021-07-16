#include <bits/stdc++.h>

class Solution {
public:
    int countDistinct(std::string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 1;i<n;i++) {

            int p = [&s](int startIdx) {
                int ret = -1;
                std::vector<int> lps(startIdx + 2,0);
                for(int j = startIdx - 1;j>=0;j--) {
                    int k = lps[j+1];
                    while(k > 0 && s[startIdx - k] != s[j]) {
                        k = lps[startIdx - k];
                    }
                    if(s[startIdx - k] == s[j]) {
                        k++;
                    }
                    lps[j] = k;
                    ret = std::max(ret,lps[j]);
                }
            }(i);

            ans += i + 1 - p;
        }
        
        return ans;
    }
};