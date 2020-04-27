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
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	solve();
	return 0;
}
string str;
int dp[4009];
int ans[4009];
int n;
string T;
vector<int> P;
void pre_process(string S) {
	int n = S.length();
	if(n == 0) T = "^$";
	else {
		T += "^";
		for(int i = 0;i<n;i++) {
			T += "#" + S.substr(i,1);
		}
		T += "#$";
	}
	n = T.length();
	P.resize(n + 2,0);
	int C = 0,R = 0;
	for(int i = 1;i< n - 1;i++) {
		int mirror = C - (i - C);
		P[i] = (R > i)?min(R - i,P[mirror]):0;
		while(T[i + 1 + P[i]] == T[i - 1 - P[i]])
			P[i]++;
		if(i + P[i] > R) {
			C = i;
			R = i + P[i];
		}
	}
}
int recurse(int i,int k) {
	if(i == n) return 0;
	if(dp[i] != -1) {
		return dp[i];
	}
	int res = 1e9;
	for(int j = i;j<n;j++) {
		if(P[j + i + 2] >= (j - i + 1)) {
			int val = 1 + recurse(j+1,k+1);
			if(val < res) {
				res = val;
				ans[i] = j - i + 1; // update the best segment length found from the position i
									// best w.r.t the minimum no of palindromic cut of the string[i ... n]
			}
		}
	}
	return dp[i] = res;
}
void solve() {
	cin >> str;
	n = (int)(str.length());
	pre_process(str);
	memset(dp,-1,sizeof dp);
	cout << recurse(0,0) << endl;
	int i = 0;
	while(i < n) {
		cout << str.substr(i,ans[i]) <<" ";
		i = i + ans[i];
	}
	cout << endl;
}

