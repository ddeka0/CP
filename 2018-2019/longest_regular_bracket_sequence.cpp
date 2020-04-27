#include <bits/stdc++.h>
using namespace std;
int dp[1000009];
#define OFFSET 2
int main() {
	string str;
	cin >> str;
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 0;
	int maxx = 0;
	int n = str.length();
	for(int i=1;i<n;i++) {
		if(str[i] == '(') {
			dp[i+OFFSET] = 0;
		}else {
			if(str[i-1] == '(') {
				dp[i+OFFSET] = 2 + dp[i - 2 + OFFSET];
				maxx = max(maxx,dp[i+OFFSET]);
			}else {
				if((i - dp[i - 1 + OFFSET]) > 0) {
					if(str[i - dp[i - 1 + OFFSET] - 1] == '(') {
						dp[i+OFFSET] = 2 + dp[i - 1 + OFFSET] + dp[i - dp[i - 1 + OFFSET] - 2 + OFFSET];
						maxx = max(maxx,dp[i+OFFSET]);
					}
				}
			}
		}
	}
	int cnt = 0;
	for(int i = 0;i<n;i++) {
		if(maxx == dp[i+ OFFSET]) {
			cnt++;
		}
	}
	if(maxx == 0) {
		cout <<"0 1"<<endl;
	}else cout <<maxx<<" "<<cnt<<endl;
	return 0;
}










