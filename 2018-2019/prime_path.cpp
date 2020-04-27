#include <bits/stdc++.h>
using namespace std;
template<typename T>
void LOG(T const& t) {std::cout <<t<<endl;}
template<typename First, typename ... Rest>
void LOG(First const& first, Rest const& ... rest) { std::cout << first<<" "; LOG(rest ...);}
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
long long modpow(long long a,long long x,long long M) {
	long long res = 1;
	while(x) {if(x&1) res = (res*a)%M; a = (a*a)%M; x/=2;}
	return res;
}
#define show(a) std::cout << #a << ": " << (a) << std::endl
long long f[100009];
long long rf[100009];
void inv_factorials(long long M) {
	f[0] = 1;
	long long m = 100000;
	for(int i = 1;i<=m;i++) {f[i] = (f[i - 1]*i)%M;}
	rf[m] = modpow(f[m],M-2,M);
	for(int i = m - 1;i>=0;i--) {rf[i] = (rf[i+1]*(i+1))%M;}
}
long long  C(int _n,int _r,long long M) {return (_r <0 || _r > _n)?0 : f[_n]*rf[_r]%M*rf[_n - _r]%M; }
void solve();

int main() {
/*	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);*/
	solve();
	return 0;
}


const int N = 10000;
 
inline void make_array(int a[],int n) {
	int idx = 3;
	while(n){
		a[idx--] = n%10;
		n = n/10;
	}
}

inline int make_num(int a[]) {
    int res = 0, idx=0;
    while(idx < 4){
        res = res*10 + a[idx];
        idx++;
    }
    return res;
}
// main function 
void solve() {
	/*	clock_t b,e; 
		double time_spent;
		b = clock();*/
  	
  	int digits[4]; bool visited[N+1]; int dist[N+1];
	vector<bool> prime(N+1,true);
	prime[0] = prime[1] = false;
	for(int i=0;i<=110;i++) {
		if(prime[i]) 
			if(i*1LL*i <= N)
				for(int j=i*i;j<=N;j = j+i) {
					prime[j] = false;
				}
	}
	int T,s,e;
	cin >> T;
	for(int tc=0;tc<T;tc++) {
		for(int i=0;i<(N+1);i++) {
			visited[i] = false;
			dist[i] = -1;
		}
		cin >> s >> e;
		dist[s] = 0;
		queue<int> Q;
		Q.push(s);
		visited[s] = true;
		while(!Q.empty()) {
			int n = Q.front();
			for(int i=3;i>=0;i--) {
				make_array(digits,n);
				for(int j=0;j< 10;j++) {
					digits[i] = j;  // change the digit
					int new_n = make_num(digits);
					if(prime[new_n] && !visited[new_n] && new_n >= 1000) {
						visited[new_n] = true;
						dist[new_n] = dist[n] + 1;
						Q.push(new_n);
					}
				}
			}
			Q.pop();
		}
		dist[e]==-1 ? cout<<"Impossible"<<endl : cout<<dist[e]<<endl;
	}
 
/*	e = clock();
	time_spent = (double)(e-b)/CLOCKS_PER_SEC;
	printf("%f\n",time_spent);*/
 
	return 0;
} 