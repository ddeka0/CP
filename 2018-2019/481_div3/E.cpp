#include <bits/stdc++.h>
using namespace std;
int n,w;
int a[1009];
bool check_1(int val) {
	for(int i = 0;i<n;i++) {
		int next = val + a[i];
		if(next > w) {
			return false;
		}
		val = next;
	}	
	return true;
}
bool check_2(int val) {
	for(int i=0;i<n;i++) {
		int next = val + a[i];
		if(next < 0) {
			return false;
		}
		val = next;
	}
	return true;
}
int main() {
	int up,lo;
	cin >> n >> w;
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	int l = 0;
	int r = w;
	int i = 0;
	while(i++ < 100) {
		int mid = (l+r)/2;
		if(check_1(mid)) {
			up = mid;
			l = mid + 1;
		}else {
			r = mid - 1;
		}
	}
	l = 0;
	r = w;
	i = 0;
	while(i++ < 100) {
		int mid = (l+r)/2;
		if(check_2(mid) && mid <= w) {
			lo = mid;
			r = mid - 1; 
		}else {
			l = mid + 1;
		}
	}

	if( up >= lo && lo >= 0 && up <= w) {
		cout << up - lo + 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}