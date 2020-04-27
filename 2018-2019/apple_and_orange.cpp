#include <bits/stdc++.h>
using namespace std;
int main() {
	long long cnt,s,t,m,n,a,b;
	cin >> s >> t;
	cin >> a >> b;
	cin >> m >> n;
	cnt = 0;
	for(int i = 0,x;i<m;i++) {
		cin >> x;
		if(((a+x)>= s) && ((a+x) <= t)) {
			cnt++;
		}
	}
	cout << cnt << endl;
	cnt = 0;
	for(int i = 0,x;i<n;i++) {
		cin >> x;
		if(((b+x)>= s) && ((b+x) <= t)) {
			cnt++;
		}
	}
	cout << cnt << endl;	
	return 0;
}