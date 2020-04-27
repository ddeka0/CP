#include <bits/stdc++.h>
using namespace std;
template<typename T>
void LOG(T const& t) {std::cout <<t<<endl;}
template<typename First, typename ... Rest>
void LOG(First const& first, Rest const& ... rest) { std::cout << first<<" "; LOG(rest ...);}
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
long long modpow(long long a,long long x,long long M) {
	long long res = 1;
	while(x) {if(x&1) res = (res*a)%M; a = (a*a)%M; x/=2;}
	return res;
}
#define show(a) std::cout << #a << ": " << (a) << std::endl
long long f[100009];
long long rf[100009];
void inv_factorials(long long M) {
	f[0] = 1;
	long long m = 100000;
	for(int i = 1;i<=m;i++) {f[i] = (f[i - 1]*i)%M;}
	rf[m] = modpow(f[m],M-2,M);
	for(int i = m - 1;i>=0;i--) {rf[i] = (rf[i+1]*(i+1))%M;}
}
long long  C(int _n,int _r,long long M) {return (_r <0 || _r > _n)?0 : f[_n]*rf[_r]%M*rf[_n - _r]%M; }
void solve();
int main() {
/*	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);*/
	solve();
	return 0;
}
bool g[110][110];
bool articulation_point[110];
int dfs_timer;
int dfs_start[110];
int dfs_low[110];
int paren[110];
#define UNVISITED 	-1
int rootchild;
int root;
int n;
void find_articulation_points(int u) {
	dfs_start[u] = dfs_low[u] = ++dfs_timer;
	for(int v = 1;v<=n;v++) {
		if(g[u][v]) {
			if(dfs_start[v] == 0) {
				paren[v] = u;
				if(u == root) rootchild++;
				find_articulation_points(v);
				if(dfs_low[v] >= dfs_start[u]) {
					articulation_point[u] = true;
				}
				dfs_low[u] = min(dfs_low[u],dfs_low[v]);
			}else {
				if(v != paren[u]) {
					dfs_low[u] = min(dfs_low[u],dfs_start[v]);
				}
			}
		}
	}
}
void solve() {
	string s;
	while(true) {
		scanf("%d\n",&n);
		if(n == 0) break;

		dfs_timer = 0;
		rootchild = 0;
		memset(dfs_low,0,sizeof dfs_low);
		memset(dfs_start,0,sizeof dfs_start);
		memset(paren,0,sizeof paren);
		memset(g,0,sizeof g);
		memset(articulation_point,false,sizeof articulation_point);

		while(true) {
			int u;
			getline(cin,s);
			istringstream ss(s);
			ss >> u;
			if(u == 0) break;
			int v;
			while(ss >> v) {
				g[u][v] = g[v][u] = true; 
			}
		}
		root = 1;
		find_articulation_points(root);
		articulation_point[root] = (rootchild > 1);
		int ans = 0;
		for(int i = 1;i<=n;i++) {
			if(articulation_point[i]) 
				ans++;
		}
		cout << ans << endl;
	}
}