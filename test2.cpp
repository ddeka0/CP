#include <bits/stdc++.h>
using namespace std;
int main() {
	float a,sum = 1;
	int b;
	cin >> a;
	cin >> b;
	float x = 0,y = 1,z = 1;
	for(int i = 0;i<b;i++) {
		x *= 3;
		if(i %3 == 1) {
			sum += 3*z*y;
		}else if(i%3 == 2) {
			sum -= 3 * z * y;
		}
		y = y*6;
		z *= a;
	}
	cout << sum << endl;
}