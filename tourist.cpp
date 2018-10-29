#include <bits/stdc++.h>
using namespace std;
template<typename T>
void LOG(T const& t) {std::cout <<t<<endl;}
template<typename First, typename ... Rest>
void LOG(First const& first, Rest const& ... rest) { std::cout << first<<" "; LOG(rest ...);}
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
typedef long long LL;
typedef vector<vector<LL>> matrix;
long long modpow(long long a,long long x,long long M) {
	long long res = 1;
	while(x) {if(x&1) res = (res*a)%M; a = (a*a)%M; x/=2;}
	return res;
}

const int K = 4;

matrix mat_mul(matrix A, matrix B,LL M) {
	matrix C(K+1, vector<LL>(K+1));
    for(int i = 1;i<=K;i++) {
		for(int j = 1;j<=K;j++) {
			for(int k = 1;k<=K;k++) {
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
			}
		}
	}
	return C;
}
matrix mat_pow(matrix A, LL p,LL M) {
    if (p == 1)
        return A;
    if (p % 2)
        return mat_mul(A, mat_pow(A, p-1,M),M);
    matrix X = mat_pow(A, p/2,M);
    return mat_mul(X, X, M);
}
#define show(a) std::cout << #a << ": " << (a) << std::endl
const LL MOD = 1000000007;
long long f[100009];
long long rf[100009];
void inv_factorials(long long M) {
	f[0] = 1;
	long long m = 100000;
	for(int i = 1;i<=m;i++) {f[i] = (f[i - 1]*i)%M;}
	rf[m] = modpow(f[m],M-2,M);
	for(int i = m - 1;i>=0;i--) {rf[i] = (rf[i+1]*(i+1))%M;}
}
long long C(int _n,int _r,long long M) {return (_r <0 || _r > _n)?0 : f[_n]*rf[_r]%M*rf[_n - _r]%M; }
void solve();
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	solve();
	return 0;
}




char a[110][110];
int n,m;
int dp[110][110][110];
inline bool inside(int x1,int y1,int x2,int y2) {
    return (x1 <= n and x2 <= n and y1 <= m and y2 <=m );
}
inline bool samepos(int x1,int y1,int x2,int y2) {
    return (x1 == x2 and y1 == y2);
}
int recurse(int x1,int y1,int x2) {
    if(x1 == n and x2 == n and y1 == m) {
        return 0;
    }
    if(dp[x1][y1][x2] != -1) return dp[x1][y1][x2];

    int res = 0;
    int steps = x1 + y1 - 1;
    int y2 = steps - x2 + 1;

    //LOG(x1,y1,x2,y2);

    // one person at (x1,y1)
    // other person at (x2,y2)

    int x1f,y1f;
    int x2f,y2f;

    // case 1 - R-R
    y1f = y1 + 1;
    y2f = y2 + 1;
    x1f = x1;
    x2f = x2;
    if(inside(x1f,y1f,x2f,y2f)) {
        if(a[x1f][y1f] != '#' and a[x2f][y2f] != '#') {
            int v1 = (a[x1f][y1f] == '*');
            int v2 = (a[x2f][y2f] == '*');
            res = max(res,v1 + v2 + recurse(x1f,y1f,x2f));
        }
    }
    // case 1 - D-D
    x1f = x1 + 1;
    x2f = x2 + 1;
    y1f = y1;
    y2f = y2;
    if(inside(x1f,y1f,x2f,y2f)) {
        if(a[x1f][y1f] != '#' and a[x2f][y2f] != '#') {
            int v1 = (a[x1f][y1f] == '*');
            int v2 = (a[x2f][y2f] == '*');
            res = max(res,v1 + v2 + recurse(x1f,y1f,x2f));
        }
    }
    
    
    // case 1 - D-R
    x1f = x1 + 1;
    y2f = y2 + 1;
    x2f = x2;
    y1f = y1;
    if(inside(x1f,y1f,x2f,y2f)) {
        if(samepos(x1f,y1f,x2f,y2f)) {
            if(a[x1f][y1f] != '#') {
                LOG("same_pos");
                LOG(x1f,y1f,x2f,y2f);
                int v1 = (a[x1f][y1f] == '*');
                res = max(res,v1 + recurse(x1f,y1f,x2f));
            }
        }else {
            if(a[x1f][y1f] != '#' and a[x2f][y2f] != '#') {
                int v1 = (a[x1f][y1f] == '*');
                int v2 = (a[x2f][y2f] == '*');
                res = max(res,v1 + v2 + recurse(x1f,y1f,x2f));
            }
        }
    }
    
    // case 1 - D-R
    y1f = y1 + 1;
    x2f = x2 + 1;
    y2f = y2;
    x1f = x1;
    if(inside(x1f,y1f,x2f,y2f)) {
        if(samepos(x1f,y1f,x2f,y2f)) {
            if(a[x1f][y1f] != '#') {
                LOG("same_pos");
                LOG(x1f,y1f,x2f,y2f);
                int v1 = (a[x1f][y1f] == '*');
                res = max(res,v1 + recurse(x1f,y1f,x2f));
            }
        }else {
            if(a[x1f][y1f] != '#' and a[x2f][y2f] != '#') {
                int v1 = (a[x1f][y1f] == '*');
                int v2 = (a[x2f][y2f] == '*');
                res = max(res,v1 + v2 + recurse(x1f,y1f,x2f));
            }
        }
    }
    return dp[x1][y1][x2] = res;
}
void solve() {
    int T;
    cin >> T;
    for(int q = 1;q<=T;q++) {
        cin >> m >> n;
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=m;j++) {
                cin >> a[i][j];
            } 
        }
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=m;j++) {
                for(int k = 1;k<=n;k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        int ans = recurse(1,1,1);
        cout << ans << endl;
    }
}