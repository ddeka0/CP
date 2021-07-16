#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> x(n + 1 ,0);
        vector<int> y(n + 1 ,0);
        stack<int> Stack;

        int cnt = 0;
        for(int i = 0;i<nums.size();i++) {
            int thisNumber = nums[i];
            while(!Stack.empty() && nums[Stack.top()] > thisNumber) {
                cnt++;
                Stack.pop();
            }
        }
    }
};

int main() {

}