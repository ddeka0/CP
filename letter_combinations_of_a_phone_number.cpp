#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int N;
    vector<string> ans;
    map<int,string> Map;
    void recurse(int indx,string _input,string _output) {
        if(indx == N) {
            ans.push_back(_output);
            return;
        }
        string ss = Map[_input[indx] - '0'];
        for(int i = 0;i<(int)(ss.length());i++) {
            recurse(indx + 1,_input,_output + ss[i]);
        }
    }
    void _init() {
        Map[2] = "abc";
        Map[3] = "def";
        Map[4] = "ghi";
        Map[5] = "jkl";
        Map[6] = "mno";
        Map[7] = "pqrs";
        Map[8] = "tuv";
        Map[9] = "wxyz";
    }
    vector<string> letterCombinations(string digits) {
        _init();
        N = (int)(digits.length());
        string s = "";
        if(N == 0) return ans;
        recurse(0,digits,s);
        return ans;
    }
};