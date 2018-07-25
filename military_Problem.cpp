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
vector<int>order;
vector<int>adj[200005];
int dp[200005];
int a[200005];
int j=0;
int mp[200005];
int k,n,x,y;
int subtree_node_count(int node){
	int res=1;
	for(int v: adj[node]){
		res +=subtree_node_count(v);
	}
	return dp[node]=res;
}
void dfs(int node){
	order.push_back(node);
	mp[node]=j++;
	for(int v: adj[node]){
		dfs(v);
	}
}
void solve(){
	cin>>n>>k;
	for (int i = 1; i <n; ++i) {
		cin>>a[i];
		adj[a[i]].push_back(i+1);
	}
	subtree_node_count(1);
	dfs(1);
	while(k--){
		cin>>x>>y;
		if(dp[x]<y)
			cout<<-1<<endl;
		else
			cout<<order[mp[x]+y-1]<<endl;
	}
}