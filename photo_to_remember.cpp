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
1. **overflow <> type of answer : it may be long long
2. handle special case carefully. Avoid making the loop generic for special cases
3. order not needed : sort it
4. For 2D matrix : if possible try to store max/min/best/ values row wise for considering all cols
*/
/* template code ends */
void solve();
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	solve();
	return 0;
}
int w[200009];
int h[200009];
int mxl[200009];
int mxr[200009];
LL sum;
void solve() {
	int n;
	cin >> n;
	for(int i = 0;i<n;i++) {
		cin >> w[i] >> h[i];
		sum += w[i];
	}
	mxl[1] = h[0];
	mxr[n - 2] = h[n - 1];
	for(int i = 1,j = n - 2;i<n - 1;i++,j--) {
		mxl[i + 1]  = (h[i] > mxl[i])?mxl[i+1] = h[i]:mxl[i+1] = mxl[i];
		mxr[j - 1]  = (h[j] > mxr[j])?h[j]:mxr[j];
	}
	for(int i = 0;i<n;i++) {
		//LOG("left size max = ",mxl[i]," and right side max = ",mxr[i]);

		int mx_h = max(mxl[i],mxr[i]);
		
		LL t_width  = sum - w[i];
		LL pixels = t_width * mx_h;
		cout << pixels << endl; 
	}

}