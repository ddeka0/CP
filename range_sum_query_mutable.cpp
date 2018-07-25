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

class NumArray {
public:
	vector<int> bit;
	int n;
    NumArray(vector<int> nums) {
    	n = nums.size();
    	bit.resize(n+1,0);
    	for(int i = 0;i<n;i++) {
    		bit[i+1] = nums[i];
    	}
    	for(int i = 1;i<bit.size();i++) {
    		int j = i + (i & (-i));
    		if(j < bit.size()) {
    			bit[j] += bit[i];
    		}
    	}
    }
    void update(int i, int val) {
        for(int j = i+1 ; j<bit.size() ; j = j + (j & (-j) )) {
        	bit[j] += val;
        }
    }
    int sumRange(int i, int j) {
        return prefix_query(j) - prefix_query(i - 1);
    }
    int prefix_query(int i) {
    	int result = 0;
    	for(int j = i+1; j > 0 ;j = j - (j & (-j) )) {
    		result += bit[j];
    	}
    	return result;
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
