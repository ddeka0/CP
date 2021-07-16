#include <bits/stdc++.h>
//#include <bits/stdc++.h>
int cs[110][110];
class Solution {
public:
    int maxSumSubmatrix(std::vector<std::vector<int>>& matrix, int k) {
        int nR = matrix.size();
        int nC = matrix[0].size();
        // reset the boundary
        for(int r = 0;r<=nR;r++) cs[r][0] = 0;
        for(int c = 0;c<=nC;c++) cs[0][c] = 0;
        // fill the cummulative sum table
        for(int r = 1;r<=nR;r++) {
            for(int c = 1;c<=nC;c++) {
                cs[r][c] = cs[r - 1][c] + cs[r][c - 1] - cs[r - 1][c - 1] + matrix[r-1][c-1];
                std::cout << cs[r][c] <<" ";
            }
            std::cout << std::endl;
        }
        
        auto CheckIfSumExists = [&](int reqSum) { // O(n^3 * logn)
            int mx = -1000000000;    
            for(int r1 = 1;r1<=nR;r1++) {
                for(int r2 = r1;r2<=nR;r2++) {
                    std::set<int> prefixSum;
                    for(int c2 = 1;c2 <=nC;c2++) {
                        int s = cs[r2][c2] - cs[r1-1][c2];
                        int searchPref = s - reqSum;
                        auto found = prefixSum.lower_bound(searchPref);
                        if(found != prefixSum.end()) {
                            mx = std::max(mx,s - *found);
                        }
                        prefixSum.insert(s);
                    }
                }
            }
            return mx;
        };

        int ans = CheckIfSumExists(k);

        return ans;
    }
};