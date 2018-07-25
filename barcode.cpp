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

string a[1009];
int hash_count[1009];
int x,y,n,m;
int HASH = 0;
int DOT  = 1;
int dp[1009][1009][2];
int recurse(int col,int last_len,int flag) {
	if(col == m) {
		return (last_len <= y and last_len >= x)?0:1e9;
	}
	if(dp[col][last_len][flag] != -1) return dp[col][last_len][flag];
	int res = 1e9;
	if(last_len < y) {
		res = ((flag == HASH)?(n - hash_count[col]):hash_count[col]) + recurse(col + 1 , last_len + 1 , flag );
	}
	if(last_len >= x) {
		res = min( ((flag == HASH)?hash_count[col]:(n - hash_count[col])) + recurse( col + 1 , 1 , 1^flag ) , res);
	}
	if(last_len == y) {
		res = min( ((flag == HASH)?hash_count[col]:(n - hash_count[col])) + recurse( col + 1 , 1 , 1^flag ) , res);
	}
	return dp[col][last_len][flag] = res;
}
void solve() {
	cin >> n >> m >> x >> y;
	for(int i = 0;i<n;i++) {
		cin >> a[i];
	}
	for(int j = 0;j<m;j++) {
		for(int i = 0;i<n;i++) {
			hash_count[j] += (a[i][j] == '#');
		}
	//	cout << hash_count[j] <<endl;
	}
	memset(dp,-1,sizeof dp);
	int ans = min( recurse(0,0,HASH) , recurse(0,0,DOT) );
	cout << ans << endl;
}
