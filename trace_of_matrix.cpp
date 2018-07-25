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
int a[109][109];
int N,T;
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cin >> T;
	for(int q = 1;q<=T;q++) {
		cin >> N;
		int ans = -1;

		for(int i = 0;i<N;i++) {
			for(int j = 0;j<N;j++) {
				cin >> a[i][j];
			}
		}
		
		int len = 1;
		int i = 0;
		int j = N - 1;

		for(int c = 0;c<N-1;c++) {
			int this_sum = 0;
			for(int l = 0,_i = i,_j = j;l<len;l++) {
				this_sum += a[_i][_j];
				_i++; _j++;
			}
			ans = max(ans,this_sum);
			len++;
			j--;
		}

		len = 1;
		i  = N - 1;
		j = 0;

		for(int c = 0;c<N-1;c++) {
			int this_sum = 0;
			for(int l = 0,_i = i,_j = j;l<len;l++) {
				this_sum += a[_i][_j];
				_i++; _j++;
			}
			len++;
			i--;
			ans = max(ans,this_sum);
		}

		int this_sum = 0;
		for(int ii = 0,jj = 0;ii<N;ii++,jj++) {
			this_sum += a[ii][jj];
		}
		cout << max(ans,this_sum) << endl;
	}
	return 0;
}