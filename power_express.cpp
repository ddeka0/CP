#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
typedef unsigned long long ULL;
typedef long long LL;
template<typename T>
void LOG(T const& t) {
	std::cout << t;
}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
	std::cout << first<<" "; LOG(rest ...);
}
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int main() {
	int num = 100;
	int n = 1000000;
	vector<char> prime (n+1, true);
	prime[0] = prime[1] = false;
	for (int i=2; i<=n; ++i)
		if (prime[i])
			if (i * 1ll * i <= n)
				for (int j=i*i; j<=n; j+=i)
					prime[j] = false;
	
	vector<int> primes;
	for(int i = 2;i<=n;i++) if(prime[i]) primes.push_back(i);


	map<int,int> counts;
	vector<int> factors;

	int i = 0;
	int _num = num;

	while(num != 1) {
		if( (num%primes[i]) == 0) {
			factors.push_back(primes[i]);
			while((num%primes[i]) == 0) {
				counts[primes[i]]++;
				num = num / primes[i];
			}			
		}
		i++;
	}
	LOG("prime factors of ",_num,"are =","\n");
	for(int e:factors) {
		LOG(e," "," power = ",counts[e],"\n");
	}
	if(factors.size() == 1) {
		cout <<"only one factor : "<<factors[0];
		cout <<" power if = "<<counts[factors[0]]<<endl;
		return 0;
	}
	int gcd_of_powers = counts[factors[0]];
	for(int j = 1;j<factors.size();j++) {
		gcd_of_powers = gcd(gcd_of_powers,counts[factors[j]]);
	}

	cout <<"is it possible to express as power of some number ?"<<endl;
	if(gcd_of_powers > 1) {
		cout << "YES" << endl;
		LOG("gcd was = ",gcd_of_powers,"\n");
	}else {
		cout << "NO" << endl;
	}
	return 0;
}	




