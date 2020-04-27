#include<bits/stdc++.h>
using namespace std;
int main() {
	cin >> T;
	for(int q = 1;q<=T;q++) {
		cin >> n >> k;
		// we need n characters and total sum = k
		
		/*1. first fill all a's and increament sum by n*/
		string res("");
		int _sum = 0;
		for(int i = 0;i<n;i++) {
			res += 'a';
			_sum++;
		}

		/*2. traverse from the back */
		for(int i = n-1;i>=0;i--) {
			
		}
	}
}