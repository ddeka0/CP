// http://codeforces.com/problemset/problem/425/A
#include <bits/stdc++.h>
using namespace std;
int dp[210][3][11][11];
bool visited[210][3][11][11];
int n, a[210], k;
int recurse(int indx,int state,int n_skip,int n_taken) {
	if(indx == n) {
		if((n_taken == n_skip) && state)
			return 0;
		return -1e9;
	}
	if(visited[indx][state][n_skip][n_taken]) {
		return dp[indx][state][n_skip][n_taken];
	}
	visited[indx][state][n_skip][n_taken] = true;
	int res = -1e9;
	if(state == 1) {
		res = recurse(indx + 1,1,n_skip,n_taken) + a[indx];
		res = max(res,recurse(indx + 1,2,n_skip,n_taken) + a[indx]);
		if(n_skip < k) {
			res = max(res , recurse(indx + 1,1,n_skip + 1,n_taken));
			res = max(res , recurse(indx + 1,2,n_skip + 1,n_taken));			
		}
		res = max(res,recurse(indx + 1,2,n_skip,n_taken));
	}
	if(state == 0) {
		res = max(recurse(indx + 1,1,n_skip,n_taken) + a[indx],recurse(indx + 1,0,n_skip,n_taken));
		res = max(res , recurse(indx + 1,1,n_skip + 1,n_taken));
		if(n_taken < k)
			res = max(res , recurse(indx + 1,0,n_skip,n_taken + 1) + a[indx]);
	}
	if(state == 2)
		res = max(recurse(indx + 1,2,n_skip,n_taken),n_taken < k?(recurse(indx + 1,2,n_skip,n_taken + 1) + a[indx]):(int)-1e9);
	return dp[indx][state][n_skip][n_taken] = res;	
}

int main () {
    cin >> n >> k;
    for (int i=0;i<n;i++)
        cin >> a[i];
    
    //memset (dp, -1, sizeof(dp));

    cout << recurse (0, 0, 0 ,0) << endl;
    return 0;
}