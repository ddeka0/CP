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

int uf[100009];
int _rank[100009];

int FIND(int x) {
	if( uf[x] != uf[uf[x]] ) uf[x] = FIND(uf[x]); return uf[x];
}
bool UNION(int x,int y) {
	int xx = FIND(x); int yy = FIND(y);
	if(xx == yy) return false;
	if(_rank[xx] > _rank[yy]) {int t=xx; xx = yy; yy = t;}
	if(_rank[xx] == _rank[yy]) _rank[yy]++;
	uf[xx] = yy;
	return true;
}
int n,q;
map<int,int> Map;
multiset<int> Set;
int main() {
	cin >> n >> q;
	for(int i = 1;i<= n+2;i++) {uf[i] = i;}
	for(int i = 1;i<= n;i++) {
		Map[i] = 1; // initial size of all the teams are one only
		Set.insert(1);
	}
	for(int i = 1,t,c,x,y;i<=q;i++) {
		cin >> t;
		LL ans = 0;
		if(t == 1) {
			cin >> x >> y;
			int xx = FIND(x);
			int yy = FIND(y);
			if(UNION(x,y)) {
				int combined_key = FIND(x);
				int del_key = (combined_key == xx)?yy:xx;
				int add = Map[del_key];
				Set.erase(Set.find(Map[xx]));
				Set.erase(Set.find(Map[yy]));
				Map.erase(del_key);
				Map[combined_key] += add;
				Set.insert(Map[combined_key]);
			}
		}else {
			cin >> c;
			std::vector<int> v;
			for(int e:Set) {
				v.push_back(e);
			}
			int m = Set.size();
			for(int j = 0;j<m;j++) {

/*				if((v[j] + c) <= v[m-1]) {
					int x = lower_bound(v.begin(), v.end(),v[j] + c) - (v.begin() + j);
					ans += (m - j) - x;	
				}*/

				for(int k = j+1;k<m;k++) {
					if( abs(v[k] - v[j]) >= c ) {
						ans += m - k;
					}
				}
			}			
			cout << ans << endl;
		}
	}
	return 0;
}




