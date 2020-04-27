#include <bits/stdc++.h>
using namespace std;
const int N = (int) 1e7 + 4;
int cnt[N];
int prime[N];
int f[N];
int main() {
	int n;
	scanf("%d",&n);
	prime[0] = prime[1] = 1;
	for(int i = 2;i * i< N;i++) {
		if(prime[i] == 0) {
			for(int j = 1;i * j<N;j++) {
				prime[i * j] = i;
			}
		}
		
	}
	for(int i = 2;i<N;i++) {
		if(prime[i] == 0) prime[i] = i;
	}
	for(int i = 0,x;i<n;i++) {
		scanf("%d",&x);
		int y = prime[x];
		while(true) {
			y = prime[x]; 	// get next largest prime divisor of x
			f[y]++;
			while(x%y == 0)x/=y;
			if(x == 1)break;
		}
	}
	for(int i = 2;i<N;i++) {
		f[i] = f[i] + f[i - 1];
	}
	int m,l,r;
	scanf("%d",&m);
	for(int i = 0;i<m;i++) {
		scanf("%d %d",&l,&r);
		l = min(l,10000001);
		r = min(r,10000001);
		cout << f[r] - f[l - 1] <<endl;
	}
	return 0;
}