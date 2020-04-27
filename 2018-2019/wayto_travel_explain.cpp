#include <bits/stdc++.h>
using namespace std;


typedef long long LL;
int n;
int a[100009];
LL dp[100009][2];
#define TAKEN 		1
#define NOT_TAKEN 	0
bool visited[100009][2];




LL recurse(int pos,bool f) {
	
	if(pos == n) return a[n]; // return ther last value

	if(visited[pos][f]) return dp[pos][f];

	LL res = -1e15;
	
	if(f == TAKEN) { // taken case

		if(pos + 2 <= n)
			res = recurse(pos + 2,TAKEN) + a[pos];
		if(pos + 3 <= n) 
			res = max(res , recurse(pos + 3,TAKEN) + a[pos] );		
	
    }else { // not taken case
	
    	if(pos + 1 <= n)
			res = recurse(pos + 1,TAKEN) + a[pos];
		if(pos + 2 <= n)
			res = max (res , recurse(pos + 2,NOT_TAKEN) + a[pos] );
		if(pos + 3 <= n) 
			res = max(res , recurse(pos + 3,NOT_TAKEN) + a[pos] );
	
    }
	
    visited[pos][f] = 1;
	return dp[pos][f] = res;
}
