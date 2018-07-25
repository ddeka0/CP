#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
typedef unsigned long long ULL;
typedef long long LL;
template<typename T>
void LOG(T const& t) {
	std::cout << t<<endl;
}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
	std::cout << first<<" "; LOG(rest ...);
}
int a[100009];
long long n,m,k,t;
long long po(long long a,long long b,long long m) {
	if(b == 0) return 1;
	if(b%2 == 0) {
		long long c = po(a, b/2, m);
		return (c*c)%m;
	}else {
		return (a * po(a, b-1, m)) % m;
	}
}
map<long long, long long> Map;
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cin >> t;
	for(int q = 1;q<=t;q++) {
		cin >> n >> m >> k;
		long long inv_kmodm = po(k,m-2,m);
		long long ans = 0;
		for(int i = 0;i<n;i++) {
			cin >> a[i];
		}
		if(k == 0) {
			int  j = 0;
			for(int i = 0;i<n;i++) {
				if( a[i]%m == 0 ) {
					ans += (n - i) * (i - j + 1);
					j = i + 1;
				}
			}
		}else {
			long long prod = 1;
			Map[1] = 1;

			for(int i = 0;i<n;i++) {
				prod = (prod * a[i])%m;
			
				if(prod != 0) {

					long long val = (prod * inv_kmodm)%m;
					ans += Map[val];
					
					Map[prod]++;
				
				}else {
			
					prod = 1;
					
					Map.clear();
			
					Map[1] = 1;
			
				}
			
			}
		}
		cout << ans << endl;
	}
	return 0;
}