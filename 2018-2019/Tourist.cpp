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
string a[110];
int T;
int recurse(int x,int y,int z) {
	if(dp[x][y] != -1) return dp[x][y];
	




	return dp[x][y][z] = res;
}
void solve() {
	cin >>T;
	for(int q = 1;q<=T;q++) {
		cin >> W >> H;
		for(int i = 1;i<=H;i++) {
			cin >> a[i];
		}
	}

}