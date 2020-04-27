#include <bits/stdc++.h>
using namespace std;
vector<bool> prime(N+1,true);
vector<int> primes;
void pre() {
	prime[0] = prime[1] = false;
	for(int i=0;i<=1000000;i++) {
		if(prime[i]) 
			if(i*1LL*i <= N)
				for(int j=i*i;j<=N;j = j+i) {
					prime[j] = false;
				}
	}
	for(int i = 2;i<=1000000;i++) {
		if(prime[i]) primes.push_back(i);
	}

}
int main() {
	cin >> T;
	for(int )	
}