#include <bits/stdc++.h>
using namespace std;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#define debug(stuff) cout << #stuff << ": " << stuff <<endl
#define debugc(stuff) cout << #stuff << ": "; for(auto x: stuff) cout << x << " "; cout << endl;

#define day first
#define height second

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> v(m);
	for(int i = 0;i<m;i++) {
		int di,hi;
		cin >> di >> hi;
		v[i].day = di;
		v[i].height = hi;
	}
	// check for impossible cases
	for(int i = 0;i<m-1;i++) {
		int diffDay = v[i+1].day - v[i].day;
		int diffHeight = abs(v[i+1].height - v[i].height);
		if(diffHeight > diffDay) {
			cout <<"IMPOSSIBLE" << endl;
			return 0;
		}
	}
	int ans = -1;
	for(int i = 0;i<m-1;i++) {
		ans = max(ans,(v[i].height + v[i+1].height + v[i+1].day - v[i].day)/2);
	}
	ans = max(ans,(v[0].day - 1) + v[0].height);
	ans = max(ans,(n - v[m-1].day) + v[m-1].height);
	cout << ans << endl;
}