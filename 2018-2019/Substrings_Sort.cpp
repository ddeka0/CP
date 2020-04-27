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

bool comp(const string &a,const string &b) {
	return a.size() < b.size();
}


vector<string> v;
string str;

void solve() {
	int n;
	cin >> n;
	for(int i = 0;i<n;i++) {
		cin >> str;
		v.push_back(str);
	}
	if(n == 1) {
		cout <<"YES"<<endl;
		cout <<v[0] <<endl;
		return;
	}

	sort(v.begin(), v.end(),comp);
	
	bool possible = true;

	for(int i =0;i<n - 1;i++) {
		if(v[i+1].find(v[i]) == std::string::npos) {
			possible = false;
			break;
		}
	}

	if(possible) {
		cout << "YES" << endl;
		for(string s:v) {
			cout << s <<endl;
		}
	}else {
		cout <<"NO" << endl;
	}
}