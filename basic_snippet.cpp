// prime calculation
void pre() {
	memset(prime,true,sizeof prime);
	prime[0] = prime[1] = false;
	for(int i = 2;i*i<=1000000;i++) {
		if(prime[i]) {
			for(int j = i*i;j<=1000000;j+=i) {
				prime[j] = false;
			}
		}
	}
	for(int i = 2;i<=1000000;i++) {
		if(prime[i])
			primes.push_back(i);
	}
}
