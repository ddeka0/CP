// http://codeforces.com/problemset/problem/665/C
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
long long ll[100009];
long long rr[100009];
long long a[100009];
int n,m;
void solve() {
    cin >> n >> m;
    for(int i = 1;i<=n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i<=n;i++) {
        if(i&1) ll[i] = (a[i] - a[i - 1]) + ll[i - 1];
        else ll[i] = ll[i - 1];
    }
    if(n&1) {
        rr[n] = m - a[n];
        for(int i = n - 1;i>=1;i--) {
            if(i&1) rr[i] = (a[i + 1] - a[i]) + rr[i + 1];
            else rr[i] = rr[i + 1];
        }
    }else {
        rr[n] = 0;
        for(int i = n - 1;i>=1;i--) {
            if(i&1) rr[i] = (a[i+1] - a[i]) + rr[i + 1];
            else rr[i] = rr[i + 1];
        }
    }

	if(n&1) {
        long long ans = -1;
        ans = max(ans,ll[n]);
        if(a[n] + 1 < m ) {
            ans = max(ans, ll[n] + m - a[n] - 1);
        }
        if(a[1] > 1) {
            ans = max(ans ,rr[1] + a[1] - 1);
        }
        for(int i = 1;i < n;i++) {
            if( (a[i] + 1) < a[i + 1]) {
                ans = max(ans, rr[i + 1] + a[i+1] - a[i]  -1 + ll[i]);
            }
        }
        cout << ans << endl;
        return;
    }else {
        long long ans = -1;
        ans = max(ans,ll[n] + m - a[n]);
        if(a[1] > 1) {
            ans = max(ans ,rr[1] + a[1] - 1);
        }
        for(int i = 1;i < n;i++) {
            if( (a[i] + 1) < a[i + 1]) {
                ans = max(ans, rr[i + 1] + a[i+1] - a[i]  - 1 + ll[i]);
            }
        }
        cout << ans << endl;
        return;
    }

}
