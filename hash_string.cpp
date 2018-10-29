#include <bits/stdc++.h>
using namespace std;

long long prime_mod0 = 2147483647;
long long prime_mod1 = 67280421310721;

int d = 31; // prime again : no of unique characters

long long b_exp(int a,int x) {
	long long res = 1;
	while(x > 0) {
		if(x&1) {
			res = res * a;
		}
		a = a * a;
		x = x / 2;
	}
	return res;
}

int main() {
	string str;
	cin >> str;
	int n = str.length();
	long long prefix_hash = 0;
	long long suffix_hash = 0;
	int r = n - 1;
	int l = 0;
	int ans = 0;
	while(l<n - 1) {
		prefix_hash = (prefix_hash*d + str[l]) % prime_mod0;
		suffix_hash = (str[r]*b_exp(d,l) + suffix_hash) % prime_mod0;
		if(prefix_hash == suffix_hash) {
			ans += (l+1);
		}
		l++; r--;
	}
	ans += n; // adding n for full prefix and suffix
	cout << ans << endl;
}


