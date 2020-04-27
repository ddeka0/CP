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

bool visited[10009];
int n,m,T;
int st[10009]; // 0 means not visited
int ft[10009]; // 0 means not visited
int dfs_timer = 0;
void dfs(int u,vector<int> g[]) {
	visited[u] = true;
	//LOG(u," visited");
	for(int v:g[u]) {
		if(!visited[v]) {
			dfs(v,g);
		}
	}
}
void transpose_graph(vector<int> g[],vector<int> gt[]) {
	for(int u = 0;u<n;u++) {
		for(int v:g[u]) {
			gt[v].push_back(u);
		}
	}
}
bool is_scc(vector<int> g[],vector<int> gt[]) {
	//LOG("dfs_1 started");
	dfs(0,g);
	for(int u = 0;u<n;u++) {
		if(!visited[u]) {

			return false;
		}
	}
	transpose_graph(g,gt);
	memset(visited,false,sizeof visited);
	//LOG("dfs_2 started");
	dfs(0,gt);
	for(int u = 0;u<n;u++) {
		if(!visited[u]) {
			return false;
		}
	}
	return true;
}
bool flag;
void check(int u,vector<int> g[]) {
	st[u] = true;
	for(int v:g[u]) {
		if(st[v] && ft[v]) {
			flag = true;
			return;
		}else if(!st[v]) {
			check(v,g);
		}
	}
	ft[u] = true;
}
void solve() {
	cin >> T;
	for(int q = 1;q<=T;q++) {
		cin >> n;
		cin >> m;
		int u,v;

		vector<int> g[n + 9];
		vector<int> gt[n + 9];

		memset(st,false,sizeof st);
		memset(ft,false,sizeof ft);
		memset(visited,false,sizeof visited);
		flag = false;

		for(int i = 1;i<=m;i++) {
			cin >> u >> v;
			g[u].push_back(v);
		}
		if(!is_scc(g,gt)) {
			cout <<"NO"<<endl;
		}else {
			check(0,g);
			flag?cout <<"NO"<<endl:cout <<"YES"<<endl;
		}
	}
}