n#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int countRangeSum(vector<int>& nums, int lower, int upper) {
		vector<long long> Sorted;
		Sorted.push_back(LONG_LONG_MIN);
		
		vector<long long> sums(nums.size() + 1,0);
		
		Sorted.push_back(sums[0]);

		for(int i = 1;i<=nums.size();i++) {
			sums[i] = sums[i-1] + nums[i-1];
			Sorted.push_back(sums[i]);
			Sorted.push_back(lower + sums[i-1] - 1);
			Sorted.push_back(upper + sums[i-1]);
		}

		std::sort(Sorted.begin(),Sorted.end());

		// initialize the bits array
		vector<int> bits(Sorted.size(),0);
		for(int i = 0;i<sums.size();i++) {
			int idx = BinarySearch(Sorted,sums[i]); 
			Add(bits,idx,1);
		}
		int ans = 0;
		for(int i = 1;i<sums.size();i++) {
			Add(bits,BinarySearch(Sorted,sums[i-1]),-1);
			ans += Query(bits,BinarySearch(Sorted,upper + sums[i-1]));
			ans -= Query(bits,BinarySearch(Sorted,lower + sums[i-1] - 1));
		}

		return ans;
    }

	int BinarySearch(vector<long long>& sorted, long long val) {
		return (int)(std::lower_bound(sorted.begin(),sorted.end(),val) - sorted.begin());
	}

	void Add(vector<int>& bits,int idx,int val) {
		for(;idx < bits.size(); idx += (idx & -idx)) bits[idx] += val;
	}

	int Query(vector<int>& bits,int idx) {
		int ans = 0;
		for(;idx > 0;idx -= (idx & -idx)) ans += bits[idx]; 
		return ans;
	}
};

int main() {
    Solution s;
    vector<int> nums = {2,1,2,1};
    std::cout << s.countRangeSum(nums,1,3) << std::endl;
}