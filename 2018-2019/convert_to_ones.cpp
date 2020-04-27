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
int n,rev_cost,flip_cost;
int ones[300009];
int zeros[300009];
int dp[300009];
string str;
int recurse(int i) {
    cout <<"entry "<<i<<endl;
    if(i == n) {
        return 0;
    }
    if(dp[i] != -1) return dp[i];
    int res = 1e9;
    if(str[i] == '1') {
        res = recurse(ones[i]);
    }else {
        res = flip_cost + recurse(zeros[i]);
        int k = zeros[i];
        if(k < n) {
            x = ones[k] - k;
            reverse
            res = min(res,rev_cost + recurse(i + k));
        }

    }
    cout <<"exit "<<i<<endl;
    return dp[i] = res;
}
void solve() {
    cin >> n >> rev_cost >> flip_cost;
    cin >> str;
    memset(ones,-1,sizeof ones);
    memset(zeros,-1,sizeof zeros);
    for(int i = 0;i<n;) {
        if(str[i] == '1') {
            int j = i;
            while(str[i] == '1') {
                i++;
            }
            ones[j] = i;
        }else {
            int j = i;
            while(str[i] == '0') {
                i++;
            }
            zeros[j] = i;
        }
    }
    memset(dp,-1,sizeof dp);
    int ans = recurse(0);
    cout << ans << endl;
}
