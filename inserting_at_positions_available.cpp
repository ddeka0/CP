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
unordered_map<int,int> Map1; // val -> parent
unordered_map<int,int> Map2; // parent -> right_pos

int n,q;


bool seen[100009];

void resolve(int q) {

	seen[q] = true;
	
	if(!seen[q- 1] && !seen[q + 1]) {

		Map1[q] = q;
		Map2[q] = q + 1;
		cout << q << endl;


	} else if(q > 1 && seen[q - 1] && !seen[q + 1]) { // left seen and right not seen


		
		int parent = Map1[q - 1];

		//int right_empty_pos = Map2[parent];

		Map1[q] = parent;

		Map2[parent] = q + 1;


		// print
		cout << q << endl;


	}else if(!seen[q - 1] && seen[q + 1]){ // right seen and left not seen

		
		int parent = Map1[q + 1];

		//int right_empty_pos = Map2[parent];

		Map1[q] = parent;


		cout << q << endl;


	}else if(seen[q - 1] && seen[q + 1]) { // both side seen
		

		int l_parent = Map1[q - 1];
		int r_parent = Map1[q + 1];

		Map2[l_parent] = Map2[r_parent];


		Map1[q] = r_parent;

		cout << q << endl;

	}
}


void solve() {
	cin >> n;
	for(int i = 0;i<n;i++) {
		cin >> q;

		if(!seen[q]) {

			resolve(q);

		}else {

				int parent = Map1[q];
				
				int ok_position = Map2[parent];

				resolve(ok_position);

				//cout << ok_position << endl;

		}
	}
}













