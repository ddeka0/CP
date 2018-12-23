#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n,d;
int main() {
	cin >> n >> d;
	for(int i = 1;i<=n;i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	if(n == 1 or n == 2) {
		cout << 0 << endl;
		return 0;
	}
	long long ans = 0;
	int i = 0;
	int j = 0;
	for(i = 0;i< n-2;i++) {
		while(j + 1 < n) {
			if(v[j + 1] - v[i] <= d) {
				j++;
			}else {
				break;	
			}
		}
		if((j - i) >= 2) {
			int k = j - i;
			ans += (k*1LL*(k-1))/2;
		}
	}
	cout << ans << endl;
}