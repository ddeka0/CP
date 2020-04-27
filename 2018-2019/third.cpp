#include <bits/stdc++.h>
using namespace std;
const int N = 1000100;
bool prime[N];
vector<int> primes;
int table[500][500];
int offset = 200;
void traverse(int maxx) {
    int stp_cnt = 1;
    int stp_lmt = 2;
    int adder = 1;
    int x = 0, y = 0;
    int prime_count = 0;
	table[x+offset][y+offset] = primes[prime_count++];
    for (;;stp_cnt++) { 
		if (stp_cnt <= .5 * stp_lmt) x += adder;
		else if (stp_cnt <= stp_lmt) y += adder;
		if (stp_cnt == stp_lmt) {
			adder *= -1; 
			stp_lmt += 2; 
			stp_cnt = 0; 
		}
		if((int)(primes.size()) > prime_count)
			table[x+offset][y+offset] = primes[prime_count++];
		else break;
    }
}
int main() {
	memset(prime,true,sizeof prime);
	prime[0] = prime[1] = false;
	for(int i = 2;i*i<N;i++) {
		if(prime[i]) {
			for(int j = i + i ;j<N;j += i) {
				prime[j] = false;
			}
		}
	}
	for(int i = 2;i<N;i++) {
		if(prime[i]) primes.push_back(i);
	}
	traverse(N - 50);
	int n;
	string str;
	cin >> n;
	for(int q = 1;q<=n;q++) {
		cin >> str;
		std::stringstream ss(str);
		int x,y;
		ss >> x;ss.ignore();ss >> y;
		cout<<table[x+offset][y+offset]<<endl;
	}
}