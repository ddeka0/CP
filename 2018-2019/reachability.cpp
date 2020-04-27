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
string a[1100];
int dist[1100][1100];
int visited[1100][1100];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
void solve() {
	int n,m;
	cin >> n >> m;
	for(int i = 0;i<n;i++) {
		cin >> a[i];
	}
	int x;
	int y;
	cin >> x >> y;
	x--;
	y--;
	memset(dist,-1,sizeof dist);
	queue<pair<int,int>> Q;
	Q.push(make_pair(x,y));
	dist[x][y] = 0;
	int dest_x;
	int dest_y;
	cin >> dest_x >> dest_y;
	dest_x--;
	dest_y--;
	while(!Q.empty()) {
		pair<int,int> u = Q.front();
		Q.pop();
		x = u.ff;
		y = u.ss;
		if(x == dest_x && y == dest_y) {
			break;
		}
		for(int i = 0;i<4;i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx >= 0 && xx < n && yy >= 0 && yy < m) {
				if(!visited[xx][yy] && a[xx][yy] == '.' ) {
					visited[xx][yy] = true;
					dist[xx][yy] = dist[x][y] + 1;
					Q.push(make_pair(xx,yy));
				}
			}
		}
	}
	dist[dest_x][dest_y] == -1 ? cout <<"-1"<<endl:cout <<dist[dest_x][dest_y]<<endl;
}


