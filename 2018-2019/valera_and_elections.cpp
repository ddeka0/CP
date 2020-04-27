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
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	solve();
	return 0;
}
vector<pair<int,int>> g[100009];
bool visited[100009];
std::vector<int> vertices;
int dfs(int u,int p,int state) {
	visited[u] = true;
	int ans = 0;
	for(auto e:g[u]) {
		int v = e.first;
		int f = e.second;
		if(!visited[v]) {
			ans += dfs(v,u,f);
		}
	}
	if(ans == 0 && state == 2) {
		ans = 1;
		vertices.push_back(u);
	}
	return ans;
}
void solve() {
	int n,u,v,f;
	cin >> n;
	for(int i = 1;i<n;i++) {
		cin >> u >> v >> f;
		g[u].push_back(make_pair(v,f));
		g[v].push_back(make_pair(u,f));
	}
	int ans = dfs(1,-1,1);
	cout << ans << endl;
	for(int u:vertices) {
		cout << u << " ";
	}
	cout << endl;
}