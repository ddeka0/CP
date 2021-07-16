#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int MOD = 1000000007;
        std::stack<int> Stack;
        vector<int> numSubArrayToLeft(A.size(),0);
        for(int i = 0;i<A.size();i++) {
            while(!Stack.empty() && A[i] <= A[Stack.top()]) {
                Stack.pop();
            }
            numSubArrayToLeft[i] = i - (Stack.empty() ? -1/* full prefix*/ : Stack.top());
            Stack.push(i);
        }
        while(!Stack.empty()) Stack.pop();

        vector<int> numSubArrayToRight(A.size(),0);
        for(int i = A.size() - 1;i>=0;i--) {
            while(!Stack.empty() && A[i] < A[Stack.top()]) {
                Stack.pop();
            }
            numSubArrayToRight[i] = (Stack.empty() ? A.size()/* full suffix*/ : Stack.top()) - i;
            Stack.push(i);
        }
        
        // for(int i = 0;i<A.size();i++) {
        //     std::cout <<"A["<<i<<"] "<<A[i]<<" : L = "<<numSubArrayToLeft[i]<<" R = "<<numSubArrayToRight[i]<<" add: "<<(((numSubArrayToLeft[i]*1LL*numSubArrayToRight[i])%MOD)*A[i]%MOD)<<std::endl;
        // }

        long long ans = 0;
        for(int i = 0;i<A.size();i++) {
            ans += ((numSubArrayToLeft[i]*1LL*numSubArrayToRight[i])%MOD)*A[i]%MOD;
            ans %= MOD;
        }
        return (int)ans;
    }
};

int main() {
    Solution s;
    vector<int> v = {1,1,2,2};
    int ans = s.sumSubarrayMins(v);
    std::cout << ans << std::endl;
}