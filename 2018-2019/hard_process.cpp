// http://codeforces.com/problemset/problem/660/C
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

int z_sum[300009];
int a[300009];
map<int,int> Map;
void solve() {
	int n,k;
	cin >> n >> k;
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
		z_sum[i] = z_sum[i - 1] + (a[i] == 0);
	}
	for(int i = 1;i<=n;i++) {
		if((Map.find(z_sum[i]) == Map.end()) && z_sum[i] /*dont insert zero*/ ) {
			Map[z_sum[i]] = i;
		}
	}
	int ans = -1;
	int indx = 1;
	for(int i = 1;i<=n;i++) {
		int x = i - Map[z_sum[i] - k] /*if key does not exit it will automatically take 0 value*/;
		if(x > ans) {
			ans = x;
			indx = i;
		}
	}
	cout << ans << endl;
	while(ans--) a[indx--] = 1;
	for(int i = 1;i<=n;i++) {
		cout << a[i] <<" ";
	}
	cout << endl;
}

