// http://codeforces.com/contest/525/problem/C
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
int a[100009];
void solve() {
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
	}
	// sort it
	sort(a+1,a+n+1);
	// make a list where each elememnt occurs twice
	// reduce one length when required
	// make two stick of same length and push in a list or vector 
	std::vector<int> v;
	for(int i = n;i>1;i--) {
		if(a[i] - a[i - 1] < 2) {
			v.push_back(a[i - 1]); 	// now we have at least two stick of length a[i - 1] 
									// there can be more // but has to be even
			i--;
		}
	}
	// inside v there are stick lengths, each with frequency 2 ... stick lengths may be equal
	// if equal they will remain contiguosly because we have sorted the array initially
	int m = v.size();
	LL ans = 0;
	for(int i = 0;i<m - 1;i = i + 2) {
		ans +=  v[i]*1LL*v[i+1];
	}
	cout << ans << endl;
}