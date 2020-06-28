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
    int trap(vector<int>& height) {
		int ans = 0;
		stack<int> Stack;
		int curr = 0;
		for(int i = 0;i<height.size();i++) {
			while(!Stack.empty() and height[curr] > height[Stack.top()]) {
				int top = Stack.top();
				// calculate how much water can be stored over the position top
				Stack.pop();
				int d = curr - Stack.top() - 1;
				int waterLevel = min(height[curr],height[Stack.top()]) - height[top];
				ans += d * waterLevel;
			}
			Stack[curr++] = i;
		}
		return ans;    
    }
};


int main() {

}