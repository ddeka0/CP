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
int n,a,b,c;
int dp[5100];
int recurse(int i) {
	if(i == 0) return 0;
	if(dp[i] != -1) return dp[i];
	int res = -1e9;
	if(i >= a) res = 1 + recurse(i - a);
	if(i >= b) res = max(res, 1 + recurse(i - b));
	if(i >= c) res = max(res, 1 + recurse(i - c));
	cout << i <<" returns "<<res <<endl;
	return dp[i] = res;
}
void solve() {
	cin >> n >> a >> b >> c;
	memset(dp,-1,sizeof dp);
	int ans = recurse(n);
	cout << ans << endl;
}
