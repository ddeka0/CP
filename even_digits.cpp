#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
	int T;
	cin >> T;
	for(int q = 1;q<=T;q++) {
		cout <<"Case #"<<q<<": ";

		cin >> n;
		long long ans = INT_MAX;
		string s = to_string(n);
		int len = s.length();
		int f = 0,idx, j;
		
		for(idx = 0; idx < len; ++idx) {
			if( (s[idx] - '0')%2 ) {
				f = idx;
				break;
			}
		}

		if(idx == len){
			cout << 0 <<endl;
			continue;
		}

		// copy from [0 --- f - 1]
		string s1 = s.substr(0,f);
		string s2 = s.substr(0,f);

		if(s[f] == '9') {
			// make all the reamining digits 8
			for (j = f; j < len; ++j) {
				s2 +='8';
			}
			long long l = stoll(s2);
			cout << n - l << endl;
			continue;
		}

		// try up and down digits at the position f
		s1 += (s[f] + 1); // up
		s2 += (s[f] - 1); // down

		for (f++; f < len; ++f) {
			s1 += '0';
			s2 += '8';
		}
		long long int u = stoll(s1);
		long long int l = stoll(s2);
		ans = min(u-n, n-l);
		cout << ans << endl;
	}
	return 0;
}



