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
int a[2009];
vector<pair<int,int>> v;
vector<pair<int,int>> vv;
void solve() {
	int n,k;
	cin >> n >> k;
	for(int i = 0,x;i<n;i++) {
		cin >> x;
		v.push_back(make_pair(x,i));
	}
	sort(v.begin(), v.end());
	for(int i = 0;i<k;i++) {
		vv.push_back(make_pair(v[n - i - 1].second,v[n - i - 1].first));
	}
	sort(vv.begin(), vv.end());


	int ans = 0;
	for(int i = 0;i<k;i++) {
		ans += vv[i].second;
	}
	cout << ans << endl;
	if(k == 1) {
		cout << n << endl;
		return;
	}
	cout << vv[0].first + 1 <<" ";
	int p = vv[0].first;
	for(int i = 1;i<vv.size() - 1;i++) {
		int idx = vv[i].first;
		cout << idx - p <<" ";
		p = idx;
	}
	cout <<  n - vv[(int)(vv.size() - 2)].first - 1 <<endl;
}