#include <bits/stdc++.h>
using namespace std;
template<typename T>
void LOG(T const& t) {
	std::cout << t;
}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
	std::cout << first<<" "; LOG(rest ...);
}
vector<pair<int,int>> cats;
vector<pair<int,int>> dogs;
int cat_edge[2009];
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	int N,M;
	cin >> N >> M;
	for(int i = 0,x,y;i<N;i++) {
		cin >> x >> y;
		cats.push_back(make_pair(x,y));
	}
	for(int j = 0,x,y;j<M;j++) {
		cin >> x >> y;
		dogs.push_back(make_pair(x,y));
	}
	for(auto dog:dogs) {
		int cat_index = 1;
		int close_cat_idx;
		long long min_d;
		for(auto cat:cats) {
			long long d = (cat.first - dog.first ) * (cat.first - dog.first )
							+ (cat.second - dog.second)*(cat.second - dog.second);
			if(cat_index == 1) {
				min_d = d;
				close_cat_idx = cat_index;
			}else {
				if(d < min_d) {
					min_d = d;
					close_cat_idx = cat_index;
				}
			}
			cat_index++;
		}
		cat_edge[close_cat_idx]++;
	}
	int ans = 0;
	for(int i = 1;i<=N;i++) {
		if(cat_edge[i] == 1) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}