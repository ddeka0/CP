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
int a[200009];
LL b[200009];
LL c[200009];
unordered_map<LL,LL> cnt;
int main() {
	int n,k;
	cin >> n >> k;
	for(int i = 0;i<n;i++) {
		cin >> a[i];
	}
	for(int i = 0;i<n;i++) {
		if(a[i]%k == 0) 
			b[i] = cnt[a[i]/k];
		cnt[a[i]]++;
	}
	cnt.clear();
/*	for(int i = 0;i<n;i++) {
		if(a[i]%k == 0) {
			cout <<"3_pair for "<<a[i]<<" is = "<<cnt[a[i]/k]<<endl;
			c[i] = cnt[a[i]/k];
		}
		cnt[a[i]] += b[i];
	}	
	cnt.clear();*/
	LL ans = 0;
	for(int i = 0;i<n;i++) {
		if(a[i]%k == 0) {
			//cout <<"4_pair for "<<a[i]<<" is = "<<cnt[a[i]/k]<<endl;
			ans += cnt[a[i]/k];
		}
		//cnt[a[i]] += c[i];
		cnt[a[i]] += b[i];
	}
	cout << ans << endl;
	return 0;
}