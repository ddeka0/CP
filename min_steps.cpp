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
int main() {
    int T;
	cin >> T;
	for(int q = 1,x;q<=T;q++) {
		map<int,int> dist;
		map<int,int> visited;
		cin >> x;
		queue<int> Q;
		Q.push(x);
		visited[x] = 1;
    	dist[x] = 0;
    	int ans = 0;
    	while(!Q.empty()) {
    		int u = Q.front();
    		int d = dist[u];
			Q.pop();
			if(u == 1) {
				ans = dist[u];
				break;
			}
			if((u%3 == 0) && (u > 0) && (!visited[u/3]) ) {
				dist[u/3] = dist[u] + 1;
				Q.push(u/3);
			}
			if(!visited[u + 1]) { 
				dist[u + 1] = dist[u] + 1; Q.push(u+1);
				visited[u+1] = 1;
			}
			if(!visited[u - 1]) {
				dist[u - 1] = dist[u] + 1; Q.push(u-1);
				visited[u - 1] = 1;
			}
    	}
    	cout << ans << endl;
    }
    return 0;
}