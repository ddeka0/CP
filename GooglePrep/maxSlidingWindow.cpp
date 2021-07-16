#include <bits/stdc++.h>
#include "printHelper.hpp"

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> dq;
        vector<int> res;
        int i = 0;
        std::for_each(nums.begin(),nums.end(),[&](auto& _elem) mutable -> void {
            while(!dq.empty() and dq.front() <= i - k) {
                dq.pop_front();
            }
            while(!dq.empty() and nums[dq.back()] < _elem) {
                dq.pop_back();
            }
            dq.push_back(i++);
            if(i < k) return;
            res.push_back(nums[dq.front()]);
        });
        return res;
    }
};

int main() {
    Solution s;
    
    vector<int> v = {4,-2};
    int k = 2;

    auto&& res = s.maxSlidingWindow(v,k);

    for(auto&& e: res) {
        std::cout << e <<" ";
    }
    std::cout << std::endl;
}