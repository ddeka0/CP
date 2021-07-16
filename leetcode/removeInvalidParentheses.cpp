#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isValid(std::string s) {
        // todo
        return false;
    }
    vector<string> removeInvalidParentheses(string s) {
        std::queue<std::string> Q;
        std::map<std::string,bool> visited;

        Q.push(s);
        visited[s] = true;

        std::vector<std::string> ans;
        
        while(!Q.empty()) {
            
            for(int i = 0;i<Q.size();i++) {
                
                std::string sx = std::move(Q.front());
                
                Q.pop();

                if(isValid((sx))) {
                    ans.push_back(sx);
                }

                if(ans.empty()) {
                    int m = sx.size();
                    for(int j = 0;j<m;j++) {
                        
                    }
                }

            }

        }
    }
};


int main() {


}