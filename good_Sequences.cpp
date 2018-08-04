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
const int N = (int)1e5 + 10;
int prime[N];
int a[N];
int dp[N];
// lets suppose we are at index i
// x is a prime factor
// dp[x] maximum length of seq that we can achieve
// using x as a key
void solve() {
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++) {
        cin >> a[i];
    }
    prime[0] = prime[1] = 1;
    for(int i = 2;i * i < N;i++) {
        if(prime[i] == 0) {
            for(int j = 1;j*i<N;j++) {
                prime[i*j] = i;
            }
        }
    }
    for(int i = 2;i<N;i++) {
        if(prime[i] == 0) prime[i] = i;
    }
    vector<int> p;
    int ans = -1;
    for(int i = 1;i<=n;i++) {
        int k = a[i];
        int dv = prime[k];
        int val = 0;
        while(true) {
            dv = prime[k];     // x is the largest prime divisor of k
            p.push_back(dv);
            val = max(val , dp[dv] + 1);
            while(k%dv == 0 && dv > 1) k /= dv;
            if(k == 1) break;
        }
        for(int e:p) {
            dp[e] = max(dp[e],val);     // imp
            // lets suppose we arrive at a[i] with prime 2,3, and 11
            // and lengths are 4,8,3
            // therefore using 3 we get the maximum length sequence ending at a[i]
            // and a[i] has all these factors 2,3,11
            // therefrom using 2,3 and 11 we can reach a maximum seq length of 8
            // so make d[2] = dp[3] = dp[11] = 8
            //show(dp[e]);
        }   
        p.clear();
    }
    for(int i = 1;i<N;i++) {    // n can be 1 and a[0] = 1 possible
        ans = max(ans,dp[i]);
    }
    cout << ans << endl;
}