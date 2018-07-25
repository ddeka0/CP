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
int T;
double EPS = 1e-5;
int d[2009];
string a[2009];
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	for(int i = 0;i<n;i++) {
		cin >> a[i];
		for(int j = 0;j<m;j++) {
			if(a[i][j] == '1') {
				d[j]++;
			}
		}
	}
	bool yes = false;
	for(int i = 0;i<n;i++) {
		bool ok = true;
		for(int j = 0;j<m;j++) {
			if( (a[i][j] == '1') && (d[j] == 1) ) {
				ok = false;
				break;
			}
		}
		if(ok) {
			yes = true;
			break;
		}
	}
	yes?cout <<"YES"<<endl:cout<<"NO"<<endl;
	return 0;
}