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
int dp[301][10][1801];
const int MOD = 1e9 + 7;
int R,B,W;
int recurse(int ball,int wicket,int run_scored) {

	if(ball == 0 && run_scored > 0) return 0;

	if(run_scored == 0 && ball == 0) {

		return 1;
	}
	if(dp[ball][wicket][run_scored] != -1) {

		return dp[ball][wicket][run_scored];
	}

	int res = 0;
	if(ball > 0) res = recurse(ball - 1,wicket,run_scored);

	if(ball > 0 && run_scored >= 4) res = (res + recurse(ball - 1,wicket,run_scored - 4))%MOD;
	if(ball > 0 && run_scored >= 6) res = (res + recurse(ball - 1,wicket,run_scored - 6))%MOD;
	if(ball > 0 && wicket > 0) res = (res + recurse(ball - 1,wicket - 1,run_scored))%MOD;
	//cout << ball <<" "<<wicket <<" "<<run_scored<<" returns "<<res<<endl;
	return dp[ball][wicket][run_scored] = res;
}
void solve() {
	int T;
	cin >> T;
	memset(dp,-1,sizeof dp);
	for(int q = 1;q<=T;q++) {
		cin >> R >> B >> W;

		if(R > 1800) {
			cout << 0 << endl;
		}else {
			int ans = recurse(B,W,R);
			cout << ans << endl;
		}
	}
}
