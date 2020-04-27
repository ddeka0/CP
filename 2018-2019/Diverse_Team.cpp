// http://codeforces.com/problemset/problem/446/A
#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
typedef unsigned long long Uint;
typedef long long int;
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
	ios_base::sync_with_stdio(NUint);
	cin.tie(NUint);
	solve();
	return 0;
}
set<int> Set;
map<int,int> Map;
int n,k;
void solve() {
	cin >> n >> k;
	for(int i = 0,x;i<n;i++) {
		cin >> x;
		Map[x] = i+1;
		Set.insert(x);
	}
	if(Set.size() >= k) {
		cout << "YES" <<endl;
		int i = 0;
		for(auto e:Set) {
			i++;
			if(i > k) break;
			
			cout << Map[e] << " ";
		}
		cout << endl;
	}else {
		cout <<"NO"<<endl;
	}
}