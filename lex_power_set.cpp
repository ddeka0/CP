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
void solve(string str,int idx,int h[],int n) {
	if(idx == n) return;
	for(int i = 0;i<n;i++) {
		if(h[i]) cout << str[i];
	}
	cout << endl;
	for(int i = idx + 1 ; i < n ;i++) {
		h[i] = 0;
		solve(str,i,h,n);
		h[i] = 1;
	}
	return;
}

int main() {
	int h[100];
	memset(h,1,sizeof h);
	string str = "15423";
	sort(str.begin(),str.end());
	int n = str.length();
	solve(str,-1,h,n);
	return 0;
}	