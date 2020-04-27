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
int a[509][509];
int b[509][509];
int N,M,K;
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cin >> N >> M;
	for(int i = 0;i<N;i++) {
		for(int j = 0;j<M;j++) {
			cin >> a[i][j];
		}
	}
	cin >> K;
	// calculate row wise cummulative sum in b[][]
	for(int i = 0;i<N;i++) {
		b[i][0] = a[i][0];
	}
	for(int i = 0;i<N;i++) {
		for(int j = 1;j<M;j++) {
			b[i][j] = b[i][j-1] + a[i][j];
		}
	}
	int ans = 0;
	for(int i = 0;i<=N - K;i++) {
		for(int j = 0;j<=M - K;j++) {
			int sum = 0;
			for(int k = 0;k<K;k++) {
				if(j == 0) {
					sum += b[i+k][j+K - 1];
				}else {
					sum += b[i+k][j+K - 1] - b[i+k][j-1];
				}
			}
			if( sum >= (K*K / 2) ) {
				ans++;
			}else if(sum > (K*K / 2) ){
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}