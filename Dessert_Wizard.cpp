#include <bits/stdc++.h>
using namespace std;
int a[10001];
int Lmn_x[10001],Lmn_y[10001],Rmx_x[10001],Rmx_y[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T,n;
	cin >> T;
	for(int q=0;q<T;q++) {
		cin >> n;
		for(int i = 0;i<n;i++) {
			cin >> a[i];
		}
		Lmn_x[0] = Lmn_y[0] = a[0];
		for(int i = 1;i<n;i++) {
			Lmn_x[i] = min(a[i],Lmn_x[i-1] + a[i]);
			Lmn_y[i] = min(Lmn_x[i],Lmn_y[i-1]);
		}
		Rmx_x[n-1] = Rmx_y[n-1] = a[n-1];
		for(int i = n-2;i>=0;i--) {
			Rmx_x[i] = max(a[i],Rmx_x[i+1] + a[i]);
			Rmx_y[i] = max(Rmx_x[i],Rmx_y[i+1]);
		}
		int ans = -1;
		for(int i=1;i<n;i++) {
			ans = max(ans, abs(  Lmn_y[i-1] - Rmx_y[i] )  );
		}
		cout << ans << endl;
	}
	return 0;
}