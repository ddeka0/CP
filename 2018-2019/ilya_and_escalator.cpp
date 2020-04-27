// http://codeforces.com/problemset/problem/518/D
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
int n,t;
double p;
double dp[2009][2009];
double recurse(int _time,int m) {
	//cout <<"entry "<<_time <<" "<<m<<endl;
	
	if(_time < 0 || m < 0) return 0;
	if(_time == 0 && m == 0) {
	//	cout <<"exit "<<_time <<" "<<m<<" returns "<<1<<endl;
		return 1.0;
	}
	if(_time == 0 && m > 0) {
	//	cout <<"exit "<<_time <<" "<<m<<" returns "<<0<<endl;
		return 0.0;
	}
	
	if(dp[_time][m] > 0) {
	//	cout <<"exit "<<_time <<" "<<m<<" returns "<<dp[_time][m]<<endl;
		return dp[_time][m];
	}
	//res += recurse(_time - 1,m);
	double res = 0.0;
	if(m == n) res += recurse(_time - 1,m);
	if(m > 0) res += recurse(_time - 1,m - 1) * p;
	if(m != n) res += recurse(_time - 1,m) * (1 - p);
	//cout <<"exit "<<_time <<" "<<m<<" returns "<<res<<endl;
	return dp[_time][m] = res;
}
void solve() {
	cin >> n >> p >> t;
	memset(dp,-1.0,sizeof dp);
	double ans = 0;
	for(int i = 1;i<=n;i++) {
		ans += i * recurse(t,i);
	//	cout << ans << endl;
	}

	cout << ans << endl;
}