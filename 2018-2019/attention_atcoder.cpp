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
int a[300009];
int b[300009];
int N;
string str;
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cin >> N;
	cin >> str;
	a[0] = (str[0] == 'E')?0:1;
	b[0] = a[0];
	for(int i = 1;i<str.length();i++) {
		a[i] = (str[i] == 'E')?0:1;
		b[i] = b[i-1] + a[i];
	}
	int ans = 1e9;
	for(int i = 0;i<N;i++) {
		int r = (i<N-1)? (N - i - 1) - (b[N-1] - b[i]) : 0;
		int l = (i>0)? b[i-1] : 0;
		//LOG("i = ",i," r = ",r," l = ",l);
		ans = min(ans,r+l);
	}
	cout << ans << endl;
	return 0;
}