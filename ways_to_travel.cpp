#include <bits/stdc++.h>
using namespace std;
template<typename T>
void LOG(T const& t) {std::cout <<t<<endl;}
template<typename First, typename ... Rest>
void LOG(First const& first, Rest const& ... rest) { std::cout << first<<" "; LOG(rest ...);}
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
long long modpow(long long a,long long x,long long M) {
	long long res = 1;
	while(x) {if(x&1) res = (res*a)%M; a = (a*a)%M; x/=2;}
	return res;
}
#define show(a) std::cout << #a << ": " << (a) << std::endl
long long f[100009];
long long rf[100009];
void inv_factorials(long long M) {
	f[0] = 1;
	long long m = 100000;
	for(int i = 1;i<=m;i++) {f[i] = (f[i - 1]*i)%M;}
	rf[m] = modpow(f[m],M-2,M);
	for(int i = m - 1;i>=0;i--) {rf[i] = (rf[i+1]*(i+1))%M;}
}
long long C(int _n,int _r,long long M) {return (_r <0 || _r > _n)?0 : f[_n]*rf[_r]%M*rf[_n - _r]%M; }
void solve();
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	solve();
	return 0;
}
const int MOD = 1e9 + 7;
string a[1100];
int n,m;
int dp[1100][1100];
int recurse(int x,int y) {
	if(dp[x][y] != -1) return dp[x][y];
	int res = 0;
	if(x < n - 1 && a[x+1][y] != '*') res = (res + recurse(x+1,y))%MOD;
	if(y < m - 1 && a[x][y+1] != '*') res = (res + recurse(x,y+1))%MOD;
	cout << x <<" "<<y<<" returns "<<res<<endl;
	return dp[x][y] = res;
}
void solve() {
	cin >> n >> m;
	for(int i = 0;i<n;i++) {
		cin >> a[i];
	}
	memset(dp,-1,sizeof dp);
	dp[n - 1][m - 1] = 1;
	int ans = recurse(0,0);
	cout << ans << endl;
}
