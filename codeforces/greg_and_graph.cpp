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


long long inf = LLONG_MAX;
long long a[501][501];
// long long dp[501][501];

int main() {
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			cin >> a[i][j];
		}
	}
	vector<int> nodes(n+1);

	for(int i = n;i>=1;i--) {
		cin >> nodes[i];
	}

	vector<long long> ans(n+1,0);

	// for(int i =1;i<=n;i++) {
	// 	for(int j = 1;j<=n;j++) {
	// 		dp[i][j] = inf;
	// 	}
	// }
	vector<int> otherNodes;
	for(int k = 1;k<=n;k++) {
		int addnode = nodes[k];
		// for(int i = 1;i<=otherNodes.size();i++) {
		// 	int x = otherNodes[i - 1];
		// 	dp[addnode][x] = min(dp[addnode][x],a[addnode][x]);
		// 	dp[x][addnode] = min(dp[x][addnode],a[x][addnode]);
		// }
		
		for(int i = 1;i<=otherNodes.size();i++) {
			for(int j = 1;j<=otherNodes.size();j++) {
				int u = otherNodes[i-1];
				int v = otherNodes[j-1];
				a[addnode][u] = min(a[addnode][u],a[addnode][v] + a[v][u]);
				a[u][addnode] = min(a[u][addnode],a[u][v] + a[v][addnode]);
			}
		}
		
		otherNodes.push_back(addnode);

		for(int i = 1;i<=otherNodes.size();i++) {
			for(int j = 1;j<=otherNodes.size();j++) {
				int u = otherNodes[i-1];
				int v = otherNodes[j-1];
				a[u][v] = min(a[u][v],a[u][addnode] + a[addnode][v]);
				// cout << a[u][v] <<" ";
				ans[k] += a[u][v];
			}
			//cout << endl;
		}
		// for(int i = n;i>=1;i--) {
		// 	cout << ans[i] <<" ";
		// }
		// cout << endl;
	}
	for(int i = n;i>=1;i--) {
		cout << ans[i] <<" ";
	}
	cout << endl;
}