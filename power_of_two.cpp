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
int a[100009];
map<long long,int> Map;
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	int n;
	cin >> n;
	//cout <<"JI"<<endl;
	long long ans = 0;
	for(int i = 0,x;i<n;i++) {
		cin >> x;
		for(long long j = 1;j < (1LL<<35) ;j = j << 1) {
			ans += Map[j - x];
			//cout << "lk"<<endl;
		}
		Map[x]++;
	//	cout << "HI"<<endl;
	}
	cout << ans << endl;
	return 0;
}