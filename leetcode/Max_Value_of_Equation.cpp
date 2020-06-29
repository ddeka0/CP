#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        // we need to maximize the value of 
        // yi + yj + |xi - xj|
        // = yi + yj - xi + xj
        // = (yi-xi) + (yj+xj) // call them as (a + b)
        // therefore store (yi-xi) in a map upto a window of len k
        map<long long,long long> Map;
        long long ans = LLONG_MIN;
        
        for(int i = 0,j = 0;i<points.size();i++) {
            
            while(j<i and !Map.empty()) {
                int xj = points[j][0]; 
                int xi = points[i][0];
                if(xj - xi > k) {
                    auto itr = Map.find(points[j][1] - points[j][0]);
                    Map.erase(itr);
                }
                j++;
            }            
            
            int b = points[i][1] - points[i][0]; // yi - xi
            auto ptr = Map.rbegin();
            if(ptr != Map.rend()) {
                // ptr will point to the maximum a value we can get for 
                // this b
                auto a = ptr->first;
                ans = max(ans,a+b);
            }

            // now its time to adjust the map
            // try to delete all such entries jth in the map
            // such that diff of x co-ordinate between 
            // ith and jth points goes beyond allowed value k
            
            // insert this b now --> which will act as a
            // for next bs
 
            Map.insert(b);
        }
        return ans;
    }
};
int main() {

}