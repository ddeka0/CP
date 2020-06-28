#include <bits/stdc++.h>
using namespace std;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#define debug(stuff) cout << #stuff << ": " << stuff <<endl
#define debugc(stuff) cout << #stuff << ": "; for(auto x: stuff) cout << x << " "; cout << endl;


int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for(int i = 0;i<N;i++) {
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	vector<bool> visible(N,true);
	int i = 0, j = N/2;
	// trace(i,j);
	int ans = N;
	while(i < N/2 and j < N and i < j) {

		// if(!visible[j]) {
		// 	j--;
		// 	if(i > j) i = j;
		// 	continue;
		// }
		// cout << a[j] << endl;
		// for(int k = 0;k<=j;k++) {
		// 	cout << a[k] <<" ";
		// }
		// cout << endl;

		while(j < N) {
			// trace(i);
			if(2 * a[i] <= a[j]) {
				ans--;
				j++;
				i++;
				break;
			}
			j++;
		}
		// if(i >=0 and a[i] <= (a[j]/2)) {
		// 	visible[i] = false;
		// 	if(j == i+1) j--;
		// 	i--;j--;
		// }
	}
	// int ans = 0;
	// for(auto x:visible) {
	// 	ans += x;
	// }
	cout << ans << endl;
}