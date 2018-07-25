#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
template<typename T>
void LOG(T const& t) {
	std::cout << t;
}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
	std::cout << first<<" "; LOG(rest ...);
}
/*template code ends*/
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	int T,n;
	int a[100009];
	long long int sum = 0;
	cin >> T;
	for(int q= 1;q<=T;q++) {
		cin >> n;
		sum = 0;
		for(int i = 0;i<n;i++) {
			cin >> a[i];
			sum += a[i];
		}
		int ans = 0;
		for(int i = 0;i<n;i++) {
			if( (sum - a[i])%2 == 0) {
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}