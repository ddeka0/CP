#include <bits/stdc++.h>
using namespace std;
std::vector<int> g[200009];
int c[200009];
bool f[200009];
int main() {
	cin >> n;
	for(int i = 1,x;i<=n;i++) {
		cin >> x;
		g[i].push_back(x);
		f[x] = true;
	}
	for(int i = 1;i<=n;i++) {
		cin >> c[i];
	}
	
}