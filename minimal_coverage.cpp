#include <bits/stdc++.h>
using namespace std;
int M;
bool possible;
int dp[5100];
int R[5100];
int OFFSET 50000
int main() {
	int l,r;
	cin >> M;
	dp[0] = -1;
	while(true) {
		cin >> l >> r;
		if(l == 0 and r == 0) break;
		if(l > M or r < 0) continue;
		if(l<=0) {
			dp[0] = max(dp[0],r);
		}else {
			
		}
	}

	for(int i = 1;i<=M;i++) {
		dp[i] = max(dp[i - 1],R[i]);
	}
	return 0;
}