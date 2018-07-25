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
long long f[100009];
long long rf[100009];
void inv_factorials(long long M) {
	f[0] = 1;
	long long m = 100000;
	for(int i = 1;i<=m;i++) {f[i] = (f[i - 1]*i)%M;}
	rf[m] = modpow(f[m],M-2,M);
	for(int i = m - 1;i>=0;i--) {rf[i] = (rf[i+1]*(i+1))%M;}
}
long long C(int _n,int _r,long long M) {
	return (_r <0 || _r > _n)?0 : f[_n]*rf[_r]%M*rf[_n - _r]%M;
}
void solve();
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	solve();
	return 0;
}
int n;
int a[1009];
long long dp[1009];
// dp[i] : how many ways to select subsequence from i ... n such that subsequence start must be a[i]
// if i < j and if we know dp[j] (for example dp[j] = 3) , then
// and if we can select ONE subsequence that starts with a[i] and considers elememts till index (j - 1) and make this a single good subarray
// we can prepend this good subsequence to those 3 subsequence (dp[j]) to form 3 good subsequence that starts with a[i]
long long recurse(int i) {
	if(i == n + 1) return 1;
	if(dp[i] != -1) return dp[i];
	int res = 0;
	if(a[i] > 0) {
		for(int j = i + a[i] + 1;j<=n+1;j++) {
			res = (res + ((C(j - i - 1,a[i],998244353) * recurse(j))) % 998244353 ) % 998244353;
		}
	}
	return dp[i] = res;
}
void solve() {
	inv_factorials(998244353);
	cin >> n;
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
	}
	memset(dp,-1,sizeof dp);
	long long ans = 0;
	for(int i = 1;i<=n;i++) {
		ans = (ans +recurse(i))%998244353;
	}
	cout << ans << endl;
}
