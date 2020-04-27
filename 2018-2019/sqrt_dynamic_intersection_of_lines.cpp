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
/* template code ends */

int n,k,b,q;
char c;
int a[100009];
int m[330][330];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int qq = 1;qq<=n;qq++) {
		cin >> c;
		if(c == '+' or c == '-') {
			cin >> k >> b;
			if(k > 320) {
				for(int x_cor = (-1)*b/k; (x_cor*k + b) <=100001;x_cor++)
					(c == '+')? a[x_cor*k + b]++ : a[x_cor*k + b]--;
			}else 
				(c == '+')? m[k][b%k]++ : m[k][b%k]--;
		}else {
			cin >> q;
			int ans = 0;

			for(int slope = 1;slope<321;slope++) {
				ans += m[slope][q%slope];
			}
			
			ans += a[q];
			cout << ans << endl;
		}
	}
	return 0;
}