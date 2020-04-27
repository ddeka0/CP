#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
template<typename T>
void LOG(T const& t) {
	std::cout << t;
}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
	std::cout << first<<" "; LOG(rest ...);
}
/*template code ends*/
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	string A,B;
	cin >> A;
	cin >> B;
	int n = A.length();
	int m = B.length();
	if( (n < (2*m)) || (n%m != 0) ) {
		cout <<"-1"<<endl;
		return 0;
	}else {
		int times = n/m;
		string s = ""
		for(int i = 0;i<times;i++) {
			s += B;
		}
		(s == A)?cout <<"1"<<endl:cout <<"-1"<<endl;
	}
	return 0;
}