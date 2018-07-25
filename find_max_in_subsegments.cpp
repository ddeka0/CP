// https://www.hackerrank.com/contests/101hack52/challenges/construct-the-array
#include<bits/stdc++.h>
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
int n,k;
set<int> Set;
map<int,int> Map;
int a[100009];
void solve() {
	cin >> n >> k;
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
	}
	for(int i = 1;i<=k;i++) {
		Map[a[i]]++;
	}
	for(int i = 1;i<=k;i++) {
		if(Map[a[i]] == 1) {
			Set.insert(a[i]);
		}
	}
	if(k == n) {
		if(!Set.empty()) {
			cout << *Set.rbegin() << endl;
		}else {
			cout <<"Not Exist"<<endl;
		}
	}else {
		for(int i = k + 1;i<=n;i++) {
			if(!Set.empty()) {
				cout << *Set.rbegin() << endl;
			}else {
				cout <<"Not Exist"<<endl;		
			}
			Map[a[i - k]]--;
			if(Map[a[i - k]] == 1) {
				Set.insert(a[i - k]);
			}else if(Map[a[i - k]] == 0) {
				Set.erase(a[i - k]);
			}
			Map[a[i]]++;
			if(Map[a[i]] == 1) {
				Set.insert(a[i]);
			}else if(Map[a[i]] == 2){
				Set.erase(a[i]);
			}
		}
		if(!Set.empty()) {
			cout << *Set.rbegin() << endl;
		}else {
			cout <<"Not Exist"<<endl;		
		}	
	}
}