#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n,m;
    string ss;
    vector<vector<int>> dp;
    bool recurse(int i,int j) {
        if() {
            
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.length();
        m = s2.length();
        ss = s3;
        dp.resize(n + 1,vector<int>(m+1,-1));
        return recurse(0,0);
    }
};