#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
class IncreasingSequencesEasy {
public:
	int count(vector<int> L,vector<int> R) {
	 	int n = L.size();
	 	//space optimization :: dp[300][10000] gives seg fault
		std::vector<int> dp(10001);
		dp[0] = 1; // nice
	 	for(int i = 0;i<n;i++) {
	 		int _sum = 0;
	 		std::vector<int> _dp(10001);
			for(int k = 0;k<=10000;k++) {
	 			if(k <= R[i] and k >= L[i]) {
	 				_dp[k] = _sum;
	 			}
	 			_sum = (_sum + dp[k])%MOD;
	 		}
	 		dp = move(_dp);
	 	} 	
	 	int ans = 0;
	 	for(int k = 0;k<=10000;k++) {
	 		ans = (ans + dp[k])%MOD;
	 	}
	 	return ans;
	 }
};

int main() {
	IncreasingSequencesEasy *solver = new IncreasingSequencesEasy();
	std::vector<int> L = {10,20};
	std::vector<int> R = {20,30};
	cout << solver->count(L,R)<<endl;
}