#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
typedef unsigned long long ULL;
typedef long long LL;
template<typename T>
void LOG(T const& t) {
	std::cout << t;
}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
	std::cout << first<<" "; LOG(rest ...);
}

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> prefix_mod_store;
        int n = nums.size();
        long long prefix_sum = 0;
        long long prefix_sum_mod = 0;
        for (int i = 0; i < n; ++i) {
            prefix_sum += nums[i];
            int modk = k == 0?prefix_sum:prefix_sum%k;
            if(prefix_mod_store.count(modk)) {
                return true;
            }
            prefix_mod_store.insert(prefix_sum_mod); // going one step back
            prefix_sum_mod = modk;
        }
        return false;
    }
};


/*int main() {
	Solution *solver = new Solution();
	string s = "abcabcbb";
	int ans = solver->lengthOfLongestSubstring(s);
	cout << ans << endl;
	delete solver;
	return 0;
}*/
