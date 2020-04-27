// http://codeforces.com/contest/276/problem/C
// check this one also : Little Girl and Maximum XOR
#include <bits/stdc++.h>
using namespace std;
template<typename T>
void LOG(T const& t) {std::cout <<t<<endl;}
template<typename First, typename ... Rest>
void LOG(First const& first, Rest const& ... rest) { std::cout << first<<" "; LOG(rest ...);}
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
int modpow(int a,int x,int M) {
	int res = 1;
	while(x) {if(x&1) res = (res*a)%M; a = (a*a)%M; x/=2;}
	return res;
}
int f[100009];
int rf[100009];
void inv_factorials(int M) {
	f[0] = 1;
	int m = 100000;
	for(int i = 1;i<=m;i++) f[i] = (f[i - 1]*i)%M;
	rf[m] = modpow(f[m],M-2);
	for(int i = m - 1;i>=0;i--) rf[i] = (rf[i+1]*(i+1))%M;
}
