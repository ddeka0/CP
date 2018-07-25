// https://www.hackerrank.com/contests/101hack52/challenges/construct-the-array
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
int c_sum[101][101];
int a[101][101];
int N;
void solve() {
	cin >> N;
	for(int i = 1;i<=N;i++) {
		for(int j = 1;j<=N;j++) {
			cin >> a[i][j];
			c_sum[i][j] = c_sum[i][j - 1] + a[i][j];
		}
	}
	int max_overall = -1;
	int max_ending;
	// kadane algorithms
	for(int i = 1;i<=N;i++) { // fix left col
		for(int j = i;j<=N;j++) { // fix right col
			max_ending = 0;
			for(int k = 1;k<=N;k++) { // do down
				max_ending = max( c_sum[k][j] - c_sum[k][i - 1] + max_ending, 
								c_sum[k][j] - c_sum[k][i - 1] 
								);
				max_overall = max(max_ending,max_overall);
			}
		}
	}
	cout << max_overall << endl;
}