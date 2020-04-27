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
int M;
bool possible;
int dp[5100];
int R[5100];
pair<int,int> ans[5100];
void solve() {
	int l,r;
	cin >> M;
	dp[0] = -1;
	while(true) {
		cin >> l >> r;
		if(l == 0 and r == 0) break;
		if(l > M or r < 0) continue;
		if(l<=0) {
			if(r > dp[0]) {
				ans[0] = make_pair(l,r);
				dp[0] = r;
			}
		}else {
			R[l] = max(R[l],r);
		}
	}
	for(int i = 1;i<=M;i++) {
		if(dp[i - 1] > R[i]) {
			ans[i] = ans[i - 1];
			dp[i] = dp[i - 1];
		}else {
			ans[i] = make_pair(i,R[i]);
			dp[i] = R[i];
		}
	}
	if(dp[0] == -1 or dp[0] == 0) {
		cout << "No solution"<<endl;
		return;
	}
	int prev = 0;
	vector<pair<int,int>> seg;
	seg.push_back(ans[0]);
	prev = dp[0];
	while(prev < M) {
		if(dp[prev] == prev) {
			cout <<"No solution"<<endl;
			return;
		}else {
			seg.push_back(ans[prev]);
			prev = dp[prev];
			if(prev >= M) {
				break;
			}
		}
	}
	cout << seg.size() <<endl;
	for(auto e:seg) {
		cout << e.first <<" "<<e.second<<endl;
	}
}