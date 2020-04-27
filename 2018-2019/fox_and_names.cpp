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

int n;
int e[30][30];
string s[101];
bool visited[30];

inline int getID(char c) {
	return (c == ' ')?0:c - 'a' + 1;  
}

void solve() {
	memset(e, 0, sizeof(e));
	
	// (" ") --> (any char) directed edge
	for(int i = 1; i <= 26; i++)
		e[0][i] = true;
	

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] += " "; // add space to handle the empty character
	}
	for(int i = 1; i < n; i++) {
		int pos = 0;
		// all strings are different -- pos will stop 
		while(s[i][pos] == s[i+1][pos]) pos ++;
		e[getID(s[i][pos])][getID(s[i+1][pos])] = true;
	}
	//warshall
	for(int k = 0; k <= 26; k++)
		for(int i = 0; i <= 26; i++)
			for(int j = 0; j <= 26; j++)
				e[i][j] |= e[i][k] & e[k][j];
	

	// the xy < x case is handled here
	bool haveCycle = false;
	for(int i = 0; i <= 26; i++)
		haveCycle |= e[i][i];
	if(haveCycle)
		cout << "Impossible" << endl;
	else {

		memset(visited, 0, sizeof(visited));
		topo_sort();
		while(!Stack.empty()) {
			ans.push_back(Stack.top());
			Stack.pop();
		}



		


		for(int i = 0; i <= 26; i++) { // 27 times including " "
			int now = 0;

			for(int j = 0; j <= 26; j++) { // this order also satisfy the case where some charater may be ordered 
											// according the original order
				bool valid = (!visited[j]);

				// make sure that no incoming edge to vertex j and j is not considered yet
				
				for(int k = 0; k <= 26; k++)
					if(visited[k] == false && e[k][j])
						valid = false;
				
				if(valid) {
					now = j;
					break;
				}
			}
			if(i > 0)
				cout << char('a' + now - 1);
			visited[now] = true;
		}





		cout << endl;
	}
}
