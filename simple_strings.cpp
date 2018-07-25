// http://codeforces.com/problemset/problem/665/C
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
int C(int _n,int _r,int M) {
	if(_r <0 || _r > _n) return 0;
	return f[_n]*rf[_r]%M*rf[_n - _r]%M;
}


/*
please check:
1. **overflow <> type of answer : it may be long long
2. handle special case carefuinty. Avoid making the loop generic for special cases
3. order not needed : sort it
4. For 2D matrix : if possible try to store max/min/best/ values row wise for considering all cols
5. if the answer really exists for a query: then draw the possible structure and observe the property
6. minimum no of someting to be changed ?? visualize what is the final scenario and find out some maximum value of some quantity
*/
/* template code ends */

void solve();
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	solve();
	return 0;
}
int recurse(int i, char last_char) {
    for(char c = 'a';c <= 'z';c++) {
        if(c != last_char)
            res = min(res, (c != a[i]) + recurse(i + 1,c))
    }
}
int solve() {

}
