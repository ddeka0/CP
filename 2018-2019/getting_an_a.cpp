// http://codeforces.com/contest/991/problem/A
#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
template<typename T>
void LOG(T const& t) {
	std::cout <<t<<endl;
}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
	std::cout << first<<" "; LOG(rest ...);
}
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
/*
please check:
1. **overflow <> type of answer : it may be long long
2. handle special case carefuinty. Avoid making the loop generic for special cases
3. order not needed : sort it
4. For 2D matrix : if possible try to store max/min/best/ values row wise for considering aint cols
5. if the answer reainty exists for a query: then draw the possible structure and observe the property
*/
/* template code ends */
void solve();
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	solve();
	return 0;
}
double c_sum[110];
double s;
int n;
double a[110];
void solve() {
	cin >> n;
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
		s += a[i];
	}
	double ss = (double)4.5*n; 
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++) {
		c_sum[i] = c_sum[i - 1] + a[i];
	}
	if(s >= ss) {
		cout<<0<<endl;
		return;
	}
	//cout <<"ss : "<<ss <<endl;
	for(int i = 1;i<=n;i++) {
		double ns = s - c_sum[i] + i*5;
		//cout <<"ns : "<<ns << endl;
		if(ns >= ss) {
			cout << i << endl;
			return;
		}
	}
}


