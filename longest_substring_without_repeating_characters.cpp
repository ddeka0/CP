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
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int n = s.length();
        /*int *dp = new int[n+2];*/
        /*dp[0] = 1;*/ int prev = 1;
        last[s[0]] = 0;
        int ans = -1;
        for(int i = 1;i<n;i++) {
            /*dp[i]*/ prev = (last[s[i]] < ( i - /*dp[i-1]*/ prev )) ? /*dp[i-1]*/ prev + 1 : i - last[s[i]];
            last[s[i]] = i;
            ans = max(ans, /*dp[i]*/ prev );
        }
/*        delete[] dp;*/
        return ans;
    }
};

int main() {
	Solution *solver = new Solution();
	string s = "abcabcbb";
	int ans = solver->lengthOfLongestSubstring(s);
	cout << ans << endl;
	delete solver;
	return 0;
}
