#include <bits/stdc++.h>
using namespace std;
int coin[10];
bool dp[100009];
int main() {
	int x,k;
	cin >> x;
	cin >> k;
	for(int i = 1;i<=k;i++) {
		cin >> coin[i];
		if(i > 1) {
			coin[i] += coin[i - 1];
		}
	}
	dp[0] = 1;
	for(int i = 1;i <= k;i++) {
		for(int m = 0;m <= x;m++) {
			if(m >= coin[i])
				dp[m] = dp[m] || dp[m - coin[i]];
				cout <<"m = "<<m<<" "<<dp[m] <<endl;
		}
	}
	dp[x]?cout <<"YES"<<endl:cout <<"NO"<<endl;
}