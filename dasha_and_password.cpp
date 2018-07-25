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
string a[60];
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	for(int i = 0;i<n;i++) {
		cin >> a[i];
	}
	int ans = 100000;
	for(int i = 0; i<n;i++) {
		for(int j = 0; j<n;j++) {
			for(int k = 0; k<n;k++) {
				
				if(i == j || j == k || k == i) continue;
				
				bool digit_found = false,sp_found = false,ch_found = false;
				int mn_d = 1000,mn_sp = 1000,mn_ch = 1000;
				
				for(int ii = 0;ii <m;ii++) {
					if(a[i][ii] <= '9' && a[i][ii] >= '0') {
						mn_d = min(mn_d,min(ii,m-ii));
						digit_found = true;
					}
				}

				if(!digit_found) break;
				
				for(int ii = 0;ii <m;ii++) {
					if(a[j][ii] <= 'z' && a[j][ii] >= 'a') {
						mn_ch = min(mn_ch,min(ii,m-ii));
						ch_found = true;
					}
				}
				if(!ch_found) break;
				
				for(int ii = 0;ii <m;ii++) {
					if(a[k][ii] == '*' || a[k][ii] == '&' || a[k][ii] == '#' ) {
						mn_sp = min(mn_sp,min(ii,m-ii));
						sp_found = true;
					}
				}
				if(!sp_found) break;


				if(digit_found && sp_found && ch_found) {
					
					ans = min(ans,mn_d + mn_sp + mn_ch);
				}
			}
		}
	}

	cout << ans << endl;
	
	return 0;
}


