#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> closestFromRight(n);
        closestFromRight[n-1] = seats[n-1] ? n-1:inf;
        for(int i = seats.size() - 2;i>=0;i--) {
            if(seats[i]) {
                closestFromRight[i] = i;
            }else {
                closestFromRight[i] = closestFromRight[i+1] == inf ? inf:closestFromRight[i+1] + 1;
            }
        }
        int ans = 1;
        int closestFromLeft = inf;
        for(int i = 0;i<seats.size();i++) {
            if(seats[i]) {
                closestFromLeft = i;
            }else {
                closestFromLeft = closestFromLeft == inf ? inf : closestFromLeft + 1;
                if(closestFromLeft != inf) ans = max(ans,closestFromLeft);
                if(closestFromRight[i] != inf) ans = max(ans,closestFromRight[i]);
            }
        }

        return ans;
    }
};