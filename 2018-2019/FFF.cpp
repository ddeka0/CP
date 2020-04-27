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
long long  C(int _n,int _r,long long M) {return (_r <0 || _r > _n)?0 : f[_n]*rf[_r]%M*rf[_n - _r]%M; }
void solve();
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	solve();
	return 0;
}
long long a[30][30];
long long n,m,k;
map<long long, long long> dp[30][30]; // dp[col]
long long recurse() {
	long long val = 0;
	for (int i = 1; i <=n; ++i) {
		val = a[i][1]^val;
		dp[i][1][val] = 1;
	}
	val = 0;
	for (int i = 1; i <=m; ++i) {
		val = a[1][i]^val;
		dp[1][i][val] = 1;
	}
	int i,j;
	for(i = 2;i<=n;i++) {
		for(j = 2;j<=m;j++) {
			for(auto e:dp[i - 1][j]) {
				long long val = e.first;
				val = val^a[i][j];
				dp[i][j][val] = e.second;
			}
			for(auto e:dp[i][j - 1]) {
				long long val = e.first;
				val = val^a[i][j];
				dp[i][j][val] += e.second;
			}
			dp[i - 1][j].clear();
		}
	}
}
void solve() {
	cin >> n >> m >> k;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=m;j++) {
			cin >> a[i][j];
		}
	}
	recurse();
	cout << dp[n][m][k] << endl;
}