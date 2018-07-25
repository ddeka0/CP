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
int _left[100009];
int _right[100009];
int a[100009];
int n;
void solve() {
	cin >> n;
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
	}
	int _less = 0;
	for(int i = 1;i<=n;i++) {
		_less = min(_less,a[i] - i);
		_left[i] = i + _less;
	}
	_less = 0;
	for(int i = 1;i<=n;i++) {
		_less = min(_less,a[n + 1 - i] - i);
		_right[n + 1 - i] = i + _less;
	}
	int ans = 0;
	for(int i = 1;i<=n;i++) {
		ans = max(ans , min(_left[i],_right[i]) );
	}
	cout << ans << endl;
}
