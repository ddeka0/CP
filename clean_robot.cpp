#include <bits/stdc++.h>
using namespace std;
#define BLOCK	'#'
int dist[110][110];
bool visited[110][110];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
void bfs(int source_x,int source_y) {
	queue<pair<int,int>> Q;
	visited[source_x][source_y] = true;
	Q.push(make_pair(source_x,source_y));
	dist[source_x][source_y] = 0;
	while(!Q.empty()) {
		auto u = Q.front();
		int x = u.ff;
		int y = u.ss;
		Q.pop();
		
		for(int i = 0;i<4;i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			if(inside(new_x,new_y) and a[new_x][new_y] != BLOCK) {
				if(!visited[new_x][new_y]) {
					if(dist[new_x][new_y] > dist[x][y] + 1) {
						dist[new_x][new_y] = dist[x][y] + 1;
						visited[new_x][new_y] = true;
					}
				}
			}
		}
	}
}

int main() {
	cin >> m >> n;
	vector<pair<int,pair<int,int>>> banana_locations;   // < node_num , < its x location , its y location > >
	int total_banana = 0;
	for(int row = 1;i<=n;row++) {
		for(int col = 1;col<=m;col++) {
			cin >> a[row][col];
			if(a[row][col] == '*') {
				banana_locations.push_back(make_pair(++total_banana,make_pair(row,col)));
			}else if(a[row][col] == 'o') {
				
			}
		}
	}
	int cost[30][30];
	for(auto x:banana_locations) {
		int node_number = x.ff;
		memset(visited,false,sizeof visited);
		memset(dist,inf,sizeof dist);
		bfs(x.ss.ff,x.ss.ss);
		for(auto y:banana_locations) {
			int next_node_number = y.ff;
			cost[node_number][next_node_number] = dist[y.ss.ff][y.ss.ss];
		}
	}
	int ans = recurse(int );

}