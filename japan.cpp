#include <bits/stdc++.h>
using namespace std;
template<typename T>
void LOG(T const& t) { std::cout << t<<endl;}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
std::cout << first<<" "; LOG(rest ...);}
#define show(a) std::cout << #a << ": " << (a) << std::endl
typedef unsigned long long ULL;
typedef long long LL;
void solve();
int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    solve();
    return 0;
}
long long bt[1001];
int n,m,k;
long long query(int idx) {
	LL sum = 0;
	while(idx > 0) {
		sum += bt[idx];
		idx = idx - (idx & -idx);
	}
	return sum;
}
void update(int idx,LL x) {
	while(idx <= m) {
		bt[idx] += x;
		idx = idx + (idx & -idx);
	}
}
std::vector<int> v[1010];
void solve() {
	int T;
	cin >> T;
	for(int q = 1;q<=T;q++) {
		cin >> n >> m >> k;
		for(int i = 1,x,y;i<=k;i++) {
			cin >> x >> y;
			v[x].push_back(y);
		}
		long long ans = 0;
		for(int i = 1000;i>=1;i--) {	
		// traverse the cities in the east coast from larger to smaller
			sort(v[i].begin(), v[i].end(),greater<int>());
			for(int e:v[i]) {
				long long add = query(e - 1);	
				// ask how many cities in he east cost before ith after
				// connected to a city of west coast with number less than e 	
				ans += add;
				//LOG("i :",i," e :",e," add :",add," ans : ",ans);
				update(e,1);	
			}
		}
		printf("Test case %d: %lld\n",q,ans);
		memset(bt,0,sizeof(bt));
		for(int i = 0;i<1010;i++) { v[i].clear(); }
	}
}
	
I will work on 
1. amf::handleAuthenticationResponse()
2. amf::triggetSecurityModeCommand() 
functions by tuesday 