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

std::vector<string> ans;
std::map<int, int> Map;
int a[]100009];

void solve() {
	int n,k;
	cin >> n >> k;
	for(int i = 0;i<n;i++) {
		cin >> a[i];
	}
	
	for(int i = 0;i<k;i++) {
		
		if(Map[a[i]] == 0) {

			Map[a[i]]++;

		}else {

			Map.erase(a[i]);
		
		}
	}
	
	if(!Map.empty())

		ans.push_back( to_string(Map.begin()->first) );
	
	else {
	
		ans.push_back("Not Exist");
	
	}

	for(int i = k;i<n;i++) {
	

			Map[a[i - 1]]--;

			if(Map[a[i]] == 0) {
				
				Map[a[i]]++;
			
			}else {

				Map.erase(a[i]);
			}



			if(!Map.empty())

				ans.push_back( to_string( (Map.rbegin())->first) );
			
			else {
			
				ans.push_back("Not Exist");
			
			}


	}


}