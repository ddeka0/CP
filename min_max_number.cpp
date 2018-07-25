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
	long long m = 100001;
	for(int i = 1;i<=m;i++) {f[i] = (f[i - 1]*i)%M;}
	rf[m] = modpow(f[m],M-2,M);
	for(int i = m - 1;i>=0;i--) {rf[i] = (rf[i+1]*(i+1))%M;}
}
long long  C(int _n,int _r,long long M) {return (_r <0 || _r > _n)?0 : f[_n]*rf[_r]%M*rf[_n - _r]%M; }
#define ll long long 
int t,n,k;
int a[5010];
long long mod = 1000000007;
 
int main(){
	cin>>t;
	inv_factorials(mod);
	while(t--){
		cin>>n>>k;
		for (int i = 0; i < n; ++i) {
			cin>>a[i];
		}

		sort(a,a+n);
		
		ll ans=1;

		for (int i = 0; i < n; ++i) {

			ll ex = C(n-1,k-1,mod) - C(n-i-1,k-1,mod) - C(i,k-1,mod);
			
			ans =(ans*(modpow(a[i]*1LL,ex,mod)))%mod;
		}

		cout<<ans<<endl;
	}
	return 0;
}