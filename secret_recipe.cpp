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
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	int x1,x2,x3,x4,v1,v2;
	cin >> T;
	for(int q = 1;q<=T;q++) {
		cin >> x1 >> x2 >> x3 >> v1 >> v2;
		double x1_time = abs(x3 - x1) / (v1*1.0);
		double x2_time = abs(x3 - x2) / (v2*1.0);
		//LOG(x1_time,x2_time);
		if(x1_time < x2_time) {
			cout << "Chef" << endl;
		}else if(x1_time > x2_time) {
			cout << "Kefa" << endl;
		}else if(fabs(x1_time - x2_time) <= EPS) {
			cout << "Draw" << endl;
		}
	}
	return 0;
}