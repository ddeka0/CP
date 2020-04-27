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
bool cycle;
int ans;
map<pair<string,string>,int> visited;
map<pair<string,string>,int> dist;
int d;
void go(string x,string y) {
	//show(x);
	//show(y);
	if(x.empty()) {
		ans = 2;
		d = dist[make_pair(x,y)];
		return;
	}else if(y.empty()) {
		ans = 1;
		d = dist[make_pair(x,y)];
		return;
	}
	int a = x[0] - '0';
	int b = y[0] - '0';
	if(a > b) {
		string xx = ((x.length() == 1)?"":x.substr(1)) + to_string(b) + to_string(a);
		string yy = (y.length() == 1)?"":y.substr(1);
		if(visited[make_pair(xx,yy)] == 1 or visited[make_pair(yy,xx)] == 1) {
			cycle = true;
			return;
		}
		visited[make_pair(xx,yy)] = 1;
		dist[make_pair(xx,yy)] = dist[make_pair(x,y)] + 1;
		go(xx,yy);
	}else {
		string yy = ((y.length() == 1)?"":y.substr(1)) + to_string(a) + to_string(b);
		string xx = (x.length() == 1)?"":x.substr(1);
		if(visited[make_pair(xx,yy)] == 1 or visited[make_pair(yy,xx)] == 1) {
			cycle = true;
			return;
		}		
		visited[make_pair(xx,yy)] = 1;
		dist[make_pair(xx,yy)] = dist[make_pair(x,y)] + 1;
		go(xx,yy);
	}
}
void solve() {
	int L;
	cin >> L;
	string s1,s2;
	int n,m;
	cin >> n;
	for(int i = 1,x;i<=n;i++) {
		cin >> x;
		x--;
		s1 += to_string(x);
	}
	cin >> m;
	for(int i = 1,x;i<=m;i++) {
		cin >> x;
		x--;
		s2 += to_string(x);
	}
	//show(s1);
	//show(s2);
	visited[make_pair(s1,s2)] = 1;
	dist[make_pair(s1,s2)] = 0;
	go(s1,s2);
	if(cycle) {
		cout <<"-1"<<endl;
	}else {
		cout << d<<" ";
		cout << ans << endl;
	}
}