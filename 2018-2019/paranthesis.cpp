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

int n;
vector<char> v;
char c;
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cin >> n;
	cin >> c;
	int bad = 1;
	v.push_back(c);
	for(int i = 1;i<n;i++) {
        cin >> c;
		if(v[bad - 1] == '(' && c == ')') {
			bad--;
            v.pop_back();
		}else {
			bad++;
			v.push_back(c);
		}
	}
	int ans = 0;
	if(bad) {
		if(v[0] == '(') {
			ans = 1;
		}else {
			if(v[0] == v[bad - 1]) {
				ans = 1;
			}else {
				ans = 2;
			}
		}
	}
	cout << ans << endl;
}

