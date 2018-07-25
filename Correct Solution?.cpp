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
int main() {
	string str,given;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> str;
	sort(str.begin(),str.end());
	cin >> given;
	if(str.length() == 1 && given.length() == 1) {
		(str[0] == given[0])?cout <<"OK"<<endl:cout << "WRONG_ANSWER" << endl;
		return 0;
	}
	string ans;
	if(str[0] != '0') {
		ans = (str == given)?"OK":"WRONG_ANSWER";
	}else {
		int idx = upper_bound(str.begin(), str.end(),'0') - str.begin();
		string x = str[idx] + str.substr(0,idx);
		if(idx + 1 < str.length()) {
			x += str.substr(idx + 1);
		}
		ans = (x == given)?"OK":"WRONG_ANSWER";
	}
	(given[0] == '0')?cout <<"WRONG_ANSWER"<<endl:cout << ans << endl;
	return 0;
}