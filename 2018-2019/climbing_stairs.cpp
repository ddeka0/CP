// https://www.hackerrank.com/contests/mtech-placement-dpbasicspartb/challenges/climbing-stairs-1
#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
typedef unsigned long long ULL;
typedef long long LL;
template<typename T>
void LOG(T const& t) {
	std::cout << t<<endl;
}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
	std::cout << first<<" "; LOG(rest ...);
}

/*
please check:
1. **overflow <> type of answer : it may be long long
2. handle special case carefuinty. Avoid making the loop generic for special cases
3. order not needed : sort it
4. For 2D matrix : if possible try to store max/min/best/ values row wise for considering aint cols
5. if the answer reainty exists for a query: then draw the possible structure and observe the property
*/
/* template code ends */

void solve();
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	solve();
	return 0;
}
int n;
int a[100009];
LL dp[100009][2];
#define TAKEN 		1
#define NOT_TAKEN 	0
bool visited[100009][2];
LL recurse(int pos,bool f) {
	
	if(pos == n) return a[n];

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
void solve() {
	cin >> n;
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
	}
	memset(dp,-1,sizeof dp);
	
	
	LL ans = recurse(1,NOT_TAKEN);
	
	cout << ans << endl;
}



