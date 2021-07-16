#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        // we will BIT again to solve this problem
        // but before that we need to normalize the indices for the BIT
        // provided vector container numbers in the full range of ints
        // therefore simply adding offset and allocating BIT space of maxelement amount will cost us a lot of memory
        // therefor we will store the elements inside a sorted container and get the relative indices from there
        vector<long> Sorted;
        Sorted.push_back(LONG_MIN);
        for(auto&& e:nums) {
            Sorted.push_back(2*e + 1);
            Sorted.push_back(e);
        }
        
        for(auto&&e:nums) {
            std::cout << e<<" ";
        }
        std::cout << std::endl;
        
        std::sort(Sorted.begin(),Sorted.end());
        
        for(auto&&e:Sorted) {
            std::cout << e<<" ";
        }
        std::cout << std::endl;

        vector<int> bits(Sorted.size() + 1,0); // maxelem can be at max 2*10^4 + 1 therefore ~O(10^4)
        int res = 0;
        std::for_each(nums.begin(),nums.end(),[this,&res,&bits,&Sorted](auto& _elem) {
            std::cout <<"this num = "<<_elem << std::endl;
            int idx = GetRelativePosition(Sorted,(long)(2LL*_elem + 1));
            std::cout <<"2*_elem + 1 = "<<2*_elem + 1<<" found at "<<idx << std::endl;
            int val = Query(bits,idx);
            std::cout << val <<" added" << std::endl;
            res += val;
            idx = GetRelativePosition(Sorted,(long)(_elem));
            Add(bits,idx,1); // if _elem is 10, add +1 at the position 10 in the BIT tree
            std::cout <<"Added +1 at " <<idx << std::endl << std::endl;
        });

        return res;
    }
	
    template<typename T>
    int GetRelativePosition(vector<T>& sorted, T val) {
		return (int)(std::lower_bound(sorted.begin(),sorted.end(),val) - sorted.begin());
	}

    inline void Add(vector<int>& bits,int idx,int val) {
        for(;idx > 0;idx -= (idx & -idx)) bits[idx] += val;
    }
    inline int Query(vector<int>& bits,int idx) {
        int ans = 0;
        for(;idx < bits.size(); idx += (idx & -idx)) ans += bits[idx];
        return ans;
    }
};

int  main() {
    Solution s;
    vector<int> v = {3,1,0,0};
    std::cout << s.reversePairs(v) <<std::endl;
}