#include <bits/stdc++.h>
using namespace std;
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
#define show(a) std::cout << #a << ": " << (a) << std::endl
void solve();
int main() {
	ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    solve();
    return 0;
}
const int MAXN = 100009;
int a[MAXN];
int b[MAXN];
void solve() {
	int n;
	cin >> n;
	if(n == 1) {
		cout << 1 << endl;
		return;
	}
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++) b[i] = 1;
	for(int i = 2;i<=n;i++) {
		if(a[i - 1] < a[i]) {
			b[i] = b[i - 1] + 1;
		}		
	}
	for(int i = n - 1;i>=1;i--) {
		if((a[i] > a[i + 1]) && (b[i] <= b[i + 1])) {
			b[i] = b[i + 1] + 1;
		}		
	}
	LL s = 0;
	for(int i = 1;i<=n;i++) s += b[i];
	cout << s << endl;	
}