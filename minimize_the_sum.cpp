#include <bits/stdc++.h>
using namespace std;
int n;
long long L[100009];
long long R[100009];
#define ff first
#define ss second
std::vector<pair<long long,long long>> v;
long long fix(long long v,long long lo,long long hi) {
    return v < lo ? lo : hi < v ? hi : v;
}
int main() {
	cin >> n;
	for(int i = 1;i<=n;i++) {
		cin >> L[i];
	}
	for(int i = 1;i<=n;i++) {
		cin >> R[i];
	}
	long long p_bottom = L[1];
	long long p_top = R[1];
	long long bottom;
	long long top;
	for(int i = 2;i<=n;i++) {
		bottom = max(p_bottom,L[i]);
		top = min(p_top,R[i]);
		if(top < p_bottom || bottom > p_top) {
			v.push_back(make_pair(p_top,p_bottom));
			p_bottom = L[i];
			p_top = R[i];			
		}else {
			p_bottom = bottom;
			p_top = top;
		}
	}
	v.push_back(make_pair(p_top,p_bottom));	
	long long ans = 0;
	long long hi = v[0].ff;
	long long lo = v[0].ss;
	for(int i = 1;i<v.size();i++) {
		ans += max(0LL,max(lo - v[i].ff,v[i].ss - hi));
		lo = fix(lo,v[i].ss,v[i].ff);
		hi = fix(hi,v[i].ss,v[i].ff);
	}
	cout << ans << endl;
}