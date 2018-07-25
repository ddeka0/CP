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
unordered_map<int,pair<int,int>> Map; // sum - x / index of x / index of the array

/*int a[100009]; // this is stupid
*/
int a[200009];


void solve() {
	int k,n,x;
	cin >> k;
	bool ok  = false;
	for(int i = 0;i<k && !ok;i++) {
		
		cin >> n;
		
		int sum = 0;
		
		for(int j = 0;j<n;j++) {
			
			cin >> a[j];
			sum = sum + a[j];
		
		}
		//cout << sum <<endl;
		for(int j = 0;j<n && !ok;j++) {
			
			int t = sum - a[j];
			
			if(Map.find(t) == Map.end()) {

				Map[sum - a[j]] = make_pair(j + 1,i + 1);
			
			}else {

				auto val = Map.find(t);
			
				if( val->second.second != (i + 1) ) {
					
					cout << "YES" <<endl;
					//cout <<" sum = "<<t << endl;
					cout << val->second.second <<" "<<val->second.first<<endl;
					cout << i + 1 <<" "<<j + 1<<endl;
					ok = true;
					break;
				

				}else {
					
					// do nothing

				}
			}

		}// end of scaning this array

	}// end of scaning aint array
	
	if(!ok) {
		cout << "NO"<<endl;
	}	

}
