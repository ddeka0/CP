#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        int n = s1.length();
        int m = s2.length();
        if(n != m) return false;
        map<int,int> Map;
        for(int i = 0;i<n;i++) {
            Map[s1[i] - 'a']++;
            Map[s2[i] - 'a']--;
        }
        for(int i = 0;i<26;i++) {
            if(Map.find(i) != Map.end() and Map[i] != 0) {
                return false;
            }
        }
        for(int len = 1;len<n;len++) {
            // no flip
            if(isScramble(s1.substr(0,len),s2.substr(0,len)) and isScramble(s1.substr(len),s2.substr(len))) {
                return true;
            }
            // flip
            if(isScramble(s1.substr(0,len),s2.substr(n - len)) and isScramble(s1.substr(len),s2.substr(0,n - len))) {
                return true;
            }
        }
        return false;   
    }
};