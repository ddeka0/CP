// http://www.spoj.com/problems/CSUBSEQS/
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
int dp[51][51][51][51];
string a,b,c,d;
int recurse(int x, int y, int p, int q) {
	//cout << "hi" <<endl;
	
	if(x >= a.length() || y >= b.length() || p >= c.length() || q >= d.length()) {
		return 0;
	}
	if(dp[x][y][p][q] != -1) return dp[x][y][p][q];
	int res = 0;
	if((a[x] == b[y]) && (b[y] == c[p]) && (c[p] == d[q]) ) {
		cout <<"oo0000000000" <<endl;
		int x = recurse(x+1,y+1,p+1,q+1);
		res = 2 * x + 1;
	}
	else {
		for(int i = 0;i<=1;i++) {
			for(int j = 0;j<=1;j++) {
				for(int k = 0;k<=1;k++) {
					for(int l = 0;l<=1;l++) {
						if( (i == 0) &&  (j == 0) && (k == 0) && (l == 0)) continue;
						res += recurse(x + i,y + j,p + k,q + l);
					}
				}
			}
		}
	}
	return dp[x][y][p][q] = res;
}
void solve() {
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	memset(dp,-1,sizeof dp);
	int ans = recurse(0,0,0,0);
	cout << ans << endl;
}


