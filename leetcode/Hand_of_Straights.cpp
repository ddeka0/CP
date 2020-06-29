#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int,int,std::greater<int>> Map;
        for(auto &e:hand) {
            Map[e]++;
        }
        bool done = false;
        while(!Map.empty()) {
            auto ptr = Map.begin();
            int x = ptr->first;
            for(int i = 0;i<W;i++) {
                if(!Map.empty() and (Map.find(x-i) != Map.end())) {
                    if(!(--Map[x-i])) {
                        Map.erase(Map.find(x-i));
                    }
                }else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    
}