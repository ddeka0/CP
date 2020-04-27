// http://codeforces.com/contest/987/problem/A
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
2. handle special case carefully. Avoid making the loop generic for special cases
3. order not needed : sort it
4. For 2D matrix : if possible try to store max/min/best/ values row wise for considering all cols
5. if the answer really exists for a query: then draw the possible structure and observe the property
*/
/* template code ends */
void solve();
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	solve();
	return 0;
}
map<string,string> color_to_stone;
map<string,int> found;
int n;
string str;
void solve() {
	color_to_stone["purple"] 	= "Power";
	color_to_stone["green"] 	= "Time";
	color_to_stone["blue"] 		= "Space";
	color_to_stone["orange"] 	= "Soul";
	color_to_stone["red"] 		= "Reality";
	color_to_stone["yellow"] 	= "Mind";
	cin >> n;
	if(n == 0) {
		cout << 6 << endl;
		for(auto e:color_to_stone) {
			cout << e.second << endl;
		}
	}else {
		cout << 6 - n << endl;
		for(int i = 0;i < n;i++) {
			cin >> str;
			found[str] = 1;
		}
		for(auto e:color_to_stone) {
			if(found[e.first] == 0){
				cout << e.second << endl;
			}
		}
	}
}