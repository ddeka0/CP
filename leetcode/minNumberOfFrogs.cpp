int v[256];
std::function<void(int v[],int need[],int tans,char c)> commandTable[26];

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        
        v['c'] = 0;
        v['r'] = 1;
        v['o'] = 2;
        v['a'] = 3;
        v['k'] = 4;

        commandTable[v['c']] = [](int v[],int need[],int tans,char c) {
            need[v[c] + 1]++;
            tans++;       
        }

        commandTable[v['k']] = [](int v[],int need[],int tans,char c) {
            need[v[c]]--;
            tans--;
        }

        std::function<void(int v[],int need[],int tans,char c)> cmd = [](int v[],int need[],int& tans,char c) {
            need[v[c]]--;
            need[v[c] + 1]++;
        }

        commandTable[v['r']] = cmd;
        commandTable[v['o']] = cmd;
        commandTable[v['a']] = cmd;


        int tans = 0;
        int ans = -1;
        
        int need[5] = {0};
        bool possible = true;
        
        for(auto && c : croakOfFrogs) {
            commandTable[v[c]](v,need,tans,c);
            possible &= need[v[c]] >= 0;
        	ans = max(ans,tans);
        }

        for(int i = 0;i<5;i++) need[0] += need[i];

        return (need[0] == 0) && possible ? ans : -1;
    }
};