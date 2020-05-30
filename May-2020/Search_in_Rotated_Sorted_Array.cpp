#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        auto pivot = nums.begin();
        auto i = nums.begin();
        for(;i!= nums.end();i++) {
            if(*pivot > *i) {
                pivot = i;
            }
        }
        auto p = lower_bound(nums.begin(),pivot,target);
        if(p != nums.end())
        if(*p == target) {
            return p - nums.begin();
        }
        auto q = lower_bound(pivot,nums.end(),target);
        if(q != nums.end())
        if(*q == target) {
            return q - nums.begin();
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> v{1,3};
    cout << s.search(v,4) << endl;
}