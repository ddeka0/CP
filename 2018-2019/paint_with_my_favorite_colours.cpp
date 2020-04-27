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
#define ff first
#define ss second
#define BLACK 	0
#define WHITE 	1
int black;
int white;
bool possible;
int color[100009];
bool visited[100009];

void dfs(int u,vector<int> g[],int col) {
	for(int v:g[u]) {
		if(visited[v]) {
			if(color[v] == col) {
				possible = false;
				return;
			}
		}
		if(!visited[v]) {
			color[v] = 1^col;
			if(color[v] == WHITE) {
				white++;
			}
			else {
				black++;
			}
			visited[v] = true;
			dfs(v,g,color[v]);
		}
	}
}
void solve() {
	int T;
	int n,m;
	cin >> T;
	for(int q = 1;q<=T;q++) {
		cin >> n >> m;
		vector<int> g[100009];
		memset(visited,false,sizeof visited);
		memset(color,-1,sizeof color);
		white = 0;
		black = 0;
		possible = true;
		int u,v;
		for(int i = 1;i<=m;i++) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u); 
		}
		int ans = 0;
		for(int u = 1;u<=n;u++) {
			if(visited[u] == false && possible) {
				white++;
				color[u] = WHITE;
				visited[u] = true;
				dfs(u,g,WHITE);
				ans += max(white,black);
				white = 0;
				black = 0;
			}
		}
		if(possible) {
			cout << ans <<endl;		
		}else {
			cout <<"NO"<<endl;
		}
	}
}



