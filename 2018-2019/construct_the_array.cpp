// https://www.hackerrank.com/contests/101hack52/challenges/construct-the-array
#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
typedef unsigned long long ULL;
typedef long long LL;
template<typename T>
void LOG(T const& t) {
    std::cout << t<<endl;
}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
    std::cout << first<<" "; LOG(rest ...);
}

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
LL MOD = 1e9 + 7;
LL a[100009];	// x .... y
LL b[100009];	// x .... x

// https://discuss.codechef.com/questions/3040/newsch-editorial

void solve() {
	int n,k,x;
	cin >> n >> k >> x;
	a[1] = 0;
	b[1] = 1;
	for(int i = 2;i<=n + 1;i++) {
		b[i] = ( (k - 1) * a[i - 1] ) % MOD;
		a[i] = ( b[i - 1] + (k - 2) * a[i - 1] ) % MOD;
	}
	(1 == x) ? cout << b[n] <<endl:cout <<a[n]<<endl;
}



