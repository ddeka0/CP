/* 
	G(n)= G(n-1) + 3*G(n-2) + 3*G(n-3) + G(n-4)
	G(1)=1
	G(2)=3
	G(3)=3
	G(4)=1
	1 ≤ t ≤ 10000
	1 ≤ n ≤ 10^18 
*/
#include <bits/stdc++.h>
using namespace std;
template<typename T>
void LOG(T const& t) {std::cout <<t<<endl;}
template<typename First, typename ... Rest>
void LOG(First const& first, Rest const& ... rest) { std::cout << first<<" "; LOG(rest ...);}
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
typedef long long LL;
typedef vector<vector<LL>> matrix;
long long modpow(long long a,long long x,long long M) {
	long long res = 1;
	while(x) {if(x&1) res = (res*a)%M; a = (a*a)%M; x/=2;}
	return res;
}

const int K = 4;

matrix mat_mul(matrix A, matrix B,LL M) {
	matrix C(K+1, vector<LL>(K+1));
    for(int i = 1;i<=K;i++) {
		for(int j = 1;j<=K;j++) {
			for(int k = 1;k<=K;k++) {
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
			}
		}
	}
	return C;
}
matrix mat_pow(matrix A, LL p,LL M) {
    if (p == 1)
        return A;
    if (p % 2)
        return mat_mul(A, mat_pow(A, p-1,M),M);
    matrix X = mat_pow(A, p/2,M);
    return mat_mul(X, X, M);
}
#define show(a) std::cout << #a << ": " << (a) << std::endl
const LL MOD = 1000000007;
long long f[100009];
long long rf[100009];
void inv_factorials(long long M) {
	f[0] = 1;
	long long m = 100000;
	for(int i = 1;i<=m;i++) {f[i] = (f[i - 1]*i)%M;}
	rf[m] = modpow(f[m],M-2,M);
	for(int i = m - 1;i>=0;i--) {rf[i] = (rf[i+1]*(i+1))%M;}
}
long long C(int _n,int _r,long long M) {return (_r <0 || _r > _n)?0 : f[_n]*rf[_r]%M*rf[_n - _r]%M; }
void solve();
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	solve();
	return 0;
}

// returns the N-th term of Fibonacci sequence
int fib(LL N) {
    // create vector F1
    vector<LL> F1(K+1);
	LL M = 10000007;
    F1[1] = 1;
    F1[2] = 3;
    F1[3] = 3;
    F1[4] = 1;
    // create matrix T
    matrix T(K+1, vector<LL>(K+1));
    T[1][1] = 0, T[1][2] = 1,T[1][3] = 0,T[1][4] = 0;
    T[2][1] = 0, T[2][2] = 0,T[2][3] = 1,T[2][4] = 0;
    T[3][1] = 0, T[3][2] = 0,T[3][3] = 0,T[3][4] = 1;
    T[4][1] = 1, T[4][2] = 3,T[4][3] = 3,T[4][4] = 1;
    // raise T to the (N-1)th power
    if (N == 1)
        return 1;
    T = mat_pow(T, N-1,M);
    // the answer is the first row of T . F1
    LL res = 0;
	for(int i = 1;i<=K;i++) {
        res = (res + T[1][i] * F1[i]) % M;
	}
    return res;
}
void solve() {
    LL T;
    LL n;
    cin >> T;
    LL M = 10000007;
	for(int q = 1;q<=T;q++) {
		cin >> n;
		cout << fib(n)%M<<endl;    
    }
}
