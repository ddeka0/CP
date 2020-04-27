#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
string a;
int n;
LL dp[20][200][2];
LL solve(int pos,int _sum,int tight) {
	
	if(pos == n) {
		return (_sum == 0);
	} 
	
	if(_sum < 0) {
		return 0;
	}
	
	if(dp[pos][_sum][tight] != -1) return dp[pos][_sum][tight];
	
	LL res = 0;
	
	if(tight == 0) {
		for(int d = 0;d<=9;d++) {
			res += solve(pos+1,_sum - d,0);
		} 
	}

	if(tight == 1) {
		for(int d = 0;d<=a[pos] - '0';d++) {
			int new_tight = 0;
			if(d == a[pos] - '0') {
				new_tight = 1;
			}
			res += solve(pos + 1,_sum - d,new_tight);
		}
	}

	return dp[pos][_sum][tight] = res;
}
int main() {
	memset(dp,-1,sizeof dp);
	cin >> a;
	n = a.length();
	int T;
	cin >> T;
	cout << solve(0,T,1) << endl;
}
