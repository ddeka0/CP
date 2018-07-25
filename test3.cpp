#include <bits/stdc++.h>
using namespace std;
int main() {
	long long x,y,a,b,c,d;
	long long last18;
	long long M = 1000000000;
	cin >> x >> y;
	a = x/M;
	b = x%M;
	c = y/M;
	d = y%M;
	last18 = ( a*c + M*b*c + M*a*d ) % (M*M);
	cout << last18 << endl;
}