#include <bits/stdc++.h>
using namespace std;
std::vector<int> z;
void z_function(string s) {
	int n = (int)s.length();
	z.resize(n+1,0);
	for(int i = 1,l = 0,r = 0;i<n;i++) {
		if(i <= r) {
			z[i] = min(z[i - l],r - i + 1);
		}
		while(i + z[i] < n and s[z[i]] == s[i + z[i]]) {
			++z[i];
		}
		if(i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
}
int main() {
	string str;
	cin >> str;
	z_function(str);
	int ans = 0;
	for(int i = 0;i<(int)str.length();i++) {
		ans += z[i];
	}
	cout << ans + (int)str.length() << endl;
}