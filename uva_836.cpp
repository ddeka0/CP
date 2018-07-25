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
string a[101];
int N,T;
void solve() {
	
	cin >> T;
	for(int q = 1;q<=T;q++) {
		int max_overall = -1;
		int max_ending;
		cin >> a[1]; // read the first line of a text case
		//cout << a[1] << endl;
		N = a[1].length(); 
		//exit(0);
		for(int j = 1;j<=N;j++) {
			c_sum[1][j] = c_sum[1][j - 1] + (a[1][j - 1] - '0');
		}		
		for(int i = 2;i<=N;i++) {
			cin >> a[i];
		//	cout << a[i] << endl;
			for(int j = 1;j<=N;j++) {
				c_sum[i][j] = c_sum[i][j - 1] + (a[i][j - 1] - '0');
			}
		}
		// kadane algorithms
		for(int i = 1;i<=N;i++) { // fix left col
			for(int j = i;j<=N;j++) { // fix right col
				max_ending = 0;
				for(int k = 1;k<=N;k++) { // do down
					int x = c_sum[k][j] - c_sum[k][i - 1];
					if(x == (j - i + 1) ) {
						max_ending = c_sum[k][j] - c_sum[k][i - 1] + max_ending;	
					}else {
						max_ending = 0;
					}
					max_overall = max(max_ending,max_overall);
				}
			}
		}
		cout << max_overall << endl;
		if(q < T)
			cout << endl;
	}
}