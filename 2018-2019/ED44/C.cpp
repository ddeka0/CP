#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
typedef unsigned long long ULL;
typedef long long LL;
template<typename T>
void LOG(T const& t) {
	std::cout << t;
}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
	std::cout << first<<" "; LOG(rest ...);
}
int T;
double EPS = 1e-5;
int h[100009];
int N,K,L;
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cin >> N >> K >> L;
	int M = N*K;
	for(int i = 0;i<M;i++) cin >> h[i];
	sort(h,h+M);
	bool not_possible = true;

	long long max_ans = -1;
	int min_h = h[0];
	for(int i = 0;i<=(M-K);i++) {
		if(abs(min_h - h[i + K - 1]) <= L) {
			long long ans = 0;
			for(int j = 0;j<K;j++) {
				ans += h[i + j];
			}
			max_ans = max(max_ans,ans);
			not_possible = false;
		}else {
			break;
		}
	}
	not_possible?cout << "0" << endl:cout << max_ans << endl;
	return 0;
}
LOG(i,lb,upper,no_upper,left,ll,"\n");