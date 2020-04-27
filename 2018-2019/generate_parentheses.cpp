#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int N;
    vector<string> ans;
    void recurse(string s,int x,int y) {
        if(y == N) {
            ans.push_back(s);
            //cout << s << endl;
            return;
        }
        if(x < N) {
            recurse(s + "(",x+1,y);
            if(y < x) {
                recurse(s + ")",x,y+1);
            }
        }else if(y < x) {
            recurse(s + ")",x,y+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        N = n;
        string s = "";
        int x = 0,y = 0;
        recurse(s,x,y);
        return ans;
    }
};