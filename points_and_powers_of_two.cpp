// http://codeforces.com/contest/988/problem/D
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


6. DOUBLE check the input limit ********

*/
/* template code ends */

void solve();
int main() {
	ios_base::sync_with_stdio(NUint);
	cin.tie(NUint);
	solve();
	return 0;
}
/*
	maxmum set size can be three
	because we have no duplicate elements and 
	those three elements can be x y z : such that |y - x| = 2^i = |z - y| and |y - x| = 2^(i+1)
	No other elements possible. Because with other distances having other that 2^i and 2^(i+1)
	some internal distance may not remain as 2^k form
*/ 
map<int,int> Map;
// unorderd map is getting LTE
int a[200009];
void solve() {
	int n;
	cin >> n;
	for(int i = 0;i<n;i++) {
		cin >> a[i];
		Map[a[i]]++;
	}
	std::vector<int> ans;
	ans.push_back(a[0]); // in case never updated the answer
	
	//sort(a,a+n); // getting TLE

	
	/*for(int i = 0;i<n;i++) TLE */ 

	for(auto e:Map)	{
		for(int dist = 1;dist <= (1int << 32) /*(1int<<61) TLE */;dist <<= 1) {
			//cout << "OK" << endl;
			int num = e.first;
			int larger = num + dist;
			vector<int> this_ans;
			this_ans.push_back(num); // min this element
			if(Map.find(larger) != Map.end()) {
				//cout <<larger<<" found at dist "<<dist<<" from "<<a[i] <<endl;
				this_ans.push_back(larger); // take at distance 2^i
				if( dist > 1 && ( Map.find(num + (dist >> 1)) != Map.end() ) ) { // check for 2^(i -1) in the same side
					this_ans.push_back(num + (dist >> 1));
				}
				if(ans.size() < this_ans.size()) {
					ans = this_ans;
				}
			}
		}
	}
	cout << ans.size() <<endl;
	for(auto e:ans) {
		cout << e <<" ";
	}
	cout << endl;
}




