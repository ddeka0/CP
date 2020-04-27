#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	vector<int> v;
	cin >> n;
	for(int i = 1,x;i<=n;i++) {
		cin >> x;
		auto ptr = lower_bound(v.begin(), v.end(),x);
		if(ptr == v.end()) v.push_back(x);
		else *ptr = x;
	}
	cout <<n - v.size()<<endl;
}