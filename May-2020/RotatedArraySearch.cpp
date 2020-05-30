#include <bits/stdc++.h>
using namespace std;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#define debug(stuff) cout << #stuff << ": " << stuff <<endl
#define debugc(stuff) cout << #stuff << ": "; for(auto x: stuff) cout << x << " "; cout << endl;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int l = 0;
        int r = nums.size() - 1;
        int step = 0;
        int mid = 0;
        while(step <= 70 && l<=r) {
            mid = (l + r)/2;
            trace(l,mid,r);    
            if(mid == l) { // to handle l == 0 case
                break;
            }else if(mid == r) { // to handle r == nums.size() - 1 case
                break;
            }else {
                if(nums[mid - 1] > nums[mid] and nums[mid + 1] > nums[mid]) {
                    break;
                }else if(nums[mid] < nums[r]) {
                    r = mid - 1;
                }else if(nums[mid] > nums[r]) {
                    l = mid + 1;
                }
            }
            step++;
        }
        
        auto pivot = nums.begin() + mid;
        auto p = lower_bound(nums.begin(),pivot,target);
        // trace()
        if(p != nums.end())
        if(*p == target) {
            return p - nums.begin();
        }
        p = lower_bound(pivot,nums.end(),target);
        if(p != nums.end())
        if(*p == target) {
            return p - nums.begin();
        }
        p = lower_bound(pivot+1,nums.end(),target);
        if(p != nums.end())
        if(*p == target) {
            return p - nums.begin();
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> v{5,1,2,3,4};
    // vector<int> v{1,2,3,4,5};
    trace(5,s.search(v,5));
}