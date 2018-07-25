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
int dp[510][510];
string str;
int recurse(int i,int j) {
	if(j < i) return 1e9;
	if(i == j) return 1;
	if(dp[i][j] != -1) return dp[i][j];
	int res = 1e9;
	if(str[i] == str[i+1]) res = min(res,recurse(i+2,j));
	for(int mirror = i + 2;mirror<=j;mirror++) {
		if(str[i] == str[mirror]) {
			res = min(recurse(i+1,mirror-1), recurse(mirror+1,j));
		}
	}
	return dp[i][j] = res;
}
void solve() {
	cin >> str;
	int n = str.length();
	cout << recurse(0,n - 1)<<endl;
}
