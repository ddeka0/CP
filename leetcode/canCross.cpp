#include <bits/stdc++.h>
//#include <bits/stdc++.h>
class Solution {
public:
    bool canCross(std::vector<int>& stones) {
    	int nStones = stones.size();
        std::map<int,std::unordered_set<long int>> jumps;
        jumps[0].insert(0);

        for(int i = 0;i<nStones;i++) {
        	for(auto jump : jumps[i]) {
                for(int nxtJump = jump;nxtJump <= jump + 1;nxtJump++) {
                    jumps[stones[i] + nxtJump].insert(nxtJump);
                }
            }
        }

        return jumps[stones[nStones - 1]].size() > 0;
    }
};