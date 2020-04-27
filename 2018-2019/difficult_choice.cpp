//__builtin_popcountll()
// concept
// parity of( bit difference of two numbers ) = parity of ( sum of no of bits of those two numbers )
#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
typedef unsigned long long ULL;
typedef long long LL;
template<typename T>
void LOG(T const& t) {
	std::cout << t;
}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
	std::cout << first<<" "; LOG(rest ...);
}
/*template code ends*/
LL b[40];
int a[100009];
bool visited[100009];
int T;
vector<vector<int>> adj;
void dfs(int root,int depth) {
	if(visited[true]) return;
	visited[root] = true;
	a[root] = __builtin_popcountll(root) + (depth&1);
	for(int v:adj[root]) {
		if(!visited[root])
			dfs(v,depth+1);
	}
}
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cin >> T;
	for(int q = 1,n;q <= T;q++) {
		cin >> n;
		adj = vector<vector<int>>(n+1);
		memset(visited,false,sizeof visited);
		for(int i = 0,u,v;i<n-1;i++) {
			cin >> u >> v;
			adj[u-1].push_back(v-1);
			adj[v-1].push_back(u-1);
		}
		for(int i = 0;i<n;i++) cin >> a[i];
		dfs(0,0);
	    memset(b,0,sizeof b);
		for(int i  = 0;i<n;i++) b[a[i]]++;
		LL ans = 0;
		for(int i = 0;i<38;i++) {
			for(int j = 0;j<38;j++) {
				if((i+j)%2 == 1) ans += b[i] * b[j];
			}
		}
		cout << (ans >> 1) << endl;
	}
	return 0;
}