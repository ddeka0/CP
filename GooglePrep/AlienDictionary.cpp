#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int getID(char c) {
        return (c == ' ')?0:c - 'a' + 1;  
    }
    
    string alienOrder(vector<string>& words) {

        if(words.size() == 0) return "";
        if(words.size() == 1) return words[0];

        int e[30][30];
        memset(e, 0, sizeof(e));
            
        // (" ") --> (any char) directed edge
        for(int i = 1; i <= 26; i++)
            e[0][i] = true;
        
        vector<bool> Set(30,false);
        for(int i = 0;i<words.size();i++) {
            for(int j = 0;j<words[i].size();j++)
                Set[getID(words[i][j])] = 1;
            words[i] += " ";
        }

        for(int i = 0;i<words.size() - 1;i++) {
            int pos = 0;
            while(words[i][pos] == words[i+1][pos] && pos+1 < min(words[i].size(),words[i+1].size()))
                pos ++;
            if(words[i][pos] != words[i+1][pos])
            e[getID(words[i][pos])][getID(words[i+1][pos])] = true;
        }

        for(int k = 0; k <= 26; k++)
            for(int i = 0; i <= 26; i++)
                for(int j = 0; j <= 26; j++)
                    e[i][j] |= e[i][k] & e[k][j];
        
    
        bool haveCycle = false;
        string ans;
        for(int i = 0; i <= 26; i++)
            haveCycle |= e[i][i];
        if(haveCycle)
            return "";
        else {
            // better topo sort algo
            std::queue<int> Q;
            vector<int> indegree(30,0);
            for(int i = 1;i<=26;i++) {
                for(int j = 1;j<=26;j++) {
                    if(e[i][j])
                        indegree[j]++;
                }
            }
            for(int i = 1;i<=26;i++) {
                if(indegree[i] == 0)
                    Q.push(i);
            }
            
            while(!Q.empty()) {
                auto t = Q.front();
                Q.pop();
                ans += char('a' + t - 1);
                for(int i = 1;i<=26;i++) {
                    if(e[t][i]) {
                        indegree[i]--;
                        if(indegree[i] == 0) {
                            Q.push(i);
                        }
                    }
                }

            }
        }
        return ans;
    }
};
int main() {


}