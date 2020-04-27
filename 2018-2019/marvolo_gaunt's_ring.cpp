#include <bits/stdc++.h>
using namespace std;
#define _p 		0
#define _pq 	1
#define _pqr	2
long long int dp[100009][3];
long long int a[100009];
int main() {
	long long int n,p,q,r;
	cin >> n >> p >> q >> r;
	for(int i = 0;i<n;i++) {
		cin >> a[i];
	}
	dp[0][_p] 	= p*a[0];
	dp[0][_pq] 	= p*a[0] + q*a[0]; 
	dp[0][_pqr] = p*a[0] + q*a[0] + r*a[0];
	for(int i = 1;i<n;i++) {
		dp[i][_p] 		= max(	dp[i-1][_p]		,	1LL*p*a[i]);
		dp[i][_pq] 		= max(	dp[i-1][_pq]	,	1LL*dp[i][_p] + 1LL*q*a[i]);
		dp[i][_pqr] 	= max(	dp[i-1][_pqr]	,	1LL*dp[i][_pq] + 1LL*r*a[i]); 
	}
	cout << dp[n-1][_pqr] << endl;
	return 0;
}