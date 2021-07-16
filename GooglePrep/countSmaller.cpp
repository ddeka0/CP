#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        /*
        1. Iterate from end to start [end,start)
        2. if we are at index j from the end, lets suppose value at index j is 6
        3. Thefore, we will add +1 on the BIT at position 6
        4. We also need to check now many numbers are already present in the BIT which are < 6
        5. With BIT this is easy because, we make the indices of BIT corresponds to the  numbers present in our given array
        */
        int _offset = 10e4 + 10;
        int maxelem = -1;
        std::for_each(nums.begin(),nums.end(),[&_offset,&maxelem](auto & _elem){
            _elem += _offset;
            maxelem = max(maxelem,_elem);
        });
        vector<int> bits(maxelem + 1,0); // maxelem can be at max 2*10^4 + 1 therefore ~O(10^4)
        vector<int> res(nums.size(),0);
        int j = nums.size() - 1;
        std::for_each(nums.rbegin(),nums.rend(),[this,&res,&bits,&j](auto& _elem) {
            res[j--] = Query(bits,_elem-1);
            Add(bits,_elem,1); // if _elem is 10, add +1 at the position 10 in the BIT tree
        });

        return res;
    }

    inline void Add(vector<int>& bits,int idx,int val) {
        for(;idx < bits.size();idx += (idx & -idx)) bits[idx] += val;
    }
    inline int Query(vector<int>& bits,int idx) {
        int ans = 0;
        for(;idx > 0; idx -= (idx & -idx)) ans += bits[idx];
        return ans;
    }
};

int  main() {
    Solution s;
    vector<int> v = {2,2};
    for(auto&& e: s.countSmaller(v)) {
        std::cout << e <<" ";
    }
    std::cout << std::endl;
}