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
string T;
vector<int> P;
void pre_process(string S) {
	int n = S.length();
	if(n == 0) T = "^$";
	else {
		T += "^";
		for(int i = 0;i<n;i++) {
			T += "#" + S.substr(i,1);
		}
		T += "#$";
	}
	n = T.length();
	P.resize(n + 2,0);
	int C = 0,R = 0;
	for(int i = 1;i< n - 1;i++) {
		int mirror = C - (i - C);
		P[i] = (R > i)?min(R - i,P[mirror]):0;
		while(T[i + 1 + P[i]] == T[i - 1 - P[i]])
			P[i]++;
		if(i + P[i] > R) {
			C = i;
			R = i + P[i];
		}
	}
}

int dp[1009];
const int MOD = 1e9 + 7;
int recurse(int i) {
	if(i == n) {
		return 1;
	}
	if(dp[i] != -1) return dp[i];
	int res = 0;
	for(int j = i;j < n;j++) {
		res = (res + (P[j + i + 2] >= (j - i + 1) ) * recurse(j + 1)) % MOD;
	}
	return dp[i] = res;
}
void solve() {
	string str;
	cin >> str;
	n = str.length();
	pre_process(str);	
	memset(dp,-1,sizeof dp);
	int ans = recurse(0);
	cout << ans << endl;
}
