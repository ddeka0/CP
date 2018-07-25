#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
typedef unsigned long long ULL;
typedef long long LL;
template<typename T>
void LOG(T const& t) {
	std::cout << t<<endl;
}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
	std::cout << first<<" "; LOG(rest ...);
}
/* template code ends */
int m[1000009][10];
int g[1000009];
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	for(int i = 1;i<10;i++) {
		g[i] = i;
		for(int j = 1;j<10;j++) {
			m[i][j] = m[i-1][j] + (j == i);
			//if(j == 4) cout <<"num = "<<i<<" k = "<<j<<" cummulative_sum = "<<m[i][j] << endl;
		}
	}
	for(int i =10;i<=1000000;i++) {
		int prod = 1;
		int num = i;
		while( num > 0) {
			int j = num%10;
			if(j != 0) prod = prod * j;
			num = num/10;
		}
		g[i] = g[prod];
		for(int j = 1;j<10;j++) {
			m[i][j] = m[i - 1][j] + (j == g[prod]);
			//if(j == 4) cout <<"num = "<<i<<" k = "<<j<<" cummulative_sum = "<<m[i][j] << endl;
		}
	}
	int q,l,r,k;
	cin >> q;
	for(int i = 0;i<q;i++) {
		cin >> l >> r >> k;
		//cout <<"l = "<<l<<" r = "<<r<<" k = "<<k<<endl;
		//cout << m[r][k] <<" and "<<m[l-1][k]<<endl;
		cout << m[r][k] - m[l-1][k] << endl;
	}
	return 0;
}