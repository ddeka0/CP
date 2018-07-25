// http://codeforces.com/problemset/problem/446/A
#include <bits/stdc++.h>
using namespace std;


int solve_row(int a[],int indx,int m,int dp[]) {
	if(indx > m) return 0;
	if(indx == m) {
		return /*dp[indx] = */ a[indx];
	}
	if(dp[indx] != -1) return dp[indx];
	int res = 0;
	res = a[indx] + solve_row(a,indx + 2,m,dp);
	res = max(res , solve_row(a,indx + 1,m,dp));
	return dp[indx] = res;
}
int main() {
	int N,M;
	cin >> N >> M;
	while(true) {
		if(N == 0 && M == 0) break;
		int a[N + 1][M+ 1];
		int b[N + 1];
		for(int i = 1;i<=N;i++) {
			for(int j = 1;j<=M;j++) {
				scanf("%d",&a[i][j]);
			}
		}
		int dp[ max(N,M) + 1 ];
		for(int row = 1;row<=N;row++) {
			memset(dp,-1,sizeof dp);
			b[row] = solve_row(a[row],1,M,dp);
		}
		
		memset(dp,-1,sizeof dp);
		int ans = solve_row(b,1,N,dp);
		printf("%d\n",ans);
		scanf("%d%d",&N,&M);

	}
	return 0;
}




