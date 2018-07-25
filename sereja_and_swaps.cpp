// http://codeforces.com/problemset/problem/425/A
#include <bits/stdc++.h>
using namespace std;
int dp[210][3][11][11];
bool visited[210][3][11][11];
int n, a[210], k;

// how to handle the no of swaps
// n_skip means : number element we excluded from the current inrval (while the interval is growing ot opended)
// n_taken means : number of elements included from outside of the interval : (while the interval not started of ended)
// of course we want n_skip == n_taken : means : no of exclusion from inside must be equal to no of inclusion from outside

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
	if(state == 1) { // interval is started
		res = recurse(indx + 1,1,n_skip,n_taken) + a[indx];	// include the current elemement and dont close
		res = max(res,recurse(indx + 1,2,n_skip,n_taken) + a[indx]); // include the current element and close it
		if(n_skip < k) {
			res = max(res , recurse(indx + 1,1,n_skip + 1,n_taken)); // dont close and skip the currrent element
			res = max(res , recurse(indx + 1,2,n_skip + 1,n_taken)); // close and skip the current element			
		}
	}
	if(state == 0) {
		// max between : start interval + include (and) no_start
		res = max(recurse(indx + 1,1,n_skip,n_taken) + a[indx],recurse(indx + 1,0,n_skip,n_taken));
		// start and exclude
		res = max(res , recurse(indx + 1,1,n_skip + 1,n_taken));
		if(n_taken < k)
			res = max(res , recurse(indx + 1,0,n_skip,n_taken + 1) + a[indx]); // dont start but take one from outside
	}
	if(state == 2)
		// max between just moving forward (and) taken one from outside 
		res = max(recurse(indx + 1,2,n_skip,n_taken),n_taken < k?(recurse(indx + 1,2,n_skip,n_taken + 1) + a[indx]):(int)-1e9);
	return dp[indx][state][n_skip][n_taken] = res;	
}
int main () {
    cin >> n >> k;
    for (int i=0;i<n;i++)
        cin >> a[i];
    cout << recurse(0,0,0,0) << endl;
    return 0;
}