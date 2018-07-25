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

/*
please check:
1. type of answer : it may be long long
2. handle special case carefully. Avoid making the loop generic
3. 
*/

/* template code ends */


int pos[100009];
int app[100009];
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 0,x;i<n;i++) {
		cin >> x;
		pos[x] = i + 1;
		app[i+1] = x;
	}
	LL ans = 0;
	for(int i = 0,x;i<m;i++) {
		cin >> x;
		int p = pos[x];
		//cout <<"position of "<<x<<" app was at "<<p<<endl;
		int gestures = (p <= k)?1:(p%k == 0)?p/k:1+p/k;
		if(p > 1) {
			int this_app = x;
			int prev_app = app[p - 1];
			swap(pos[this_app],pos[prev_app]);
			swap(app[p],app[p-1]);
		}
		// cout <<"position of "<<x<<" app is now at "<<pos[x]<<endl;
		// cout <<"position of "<<app[p-1]<<" app is now at "<<pos[app[p - 1]]<<endl;
		ans += gestures;
		// cout <<" app "<<x<<" took "<<gestures<<" "<<endl<<endl<<endl;
	}
	cout << ans <<endl;
}