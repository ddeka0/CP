#include <bits/stdc++.h>
using namespace std;
bool cycle = false;
vector<int> g[20];
vector<bool> visited(20,false);
vector<bool> explored(20,false);
int parent[20];

int start_point;
int end_point;

void dfs(int u) {
	for(int v:g[u]) {
		if(!visited[v]) {
			visited[v] = 1;
			parent[v] = u;
			dfs(v);
		}else {
			if(!explored[v]) {
				start_point = v;
				end_point = u;
				cycle = true;
				return;
			}
		}
	}
	explored[u] = 1;
}

int main() {	
	g[1].push_back(2);
	g[2].push_back(3);
	g[3].push_back(4);
	g[4].push_back(1);

	visited[1] = true;
	dfs(1);

	cycle?cout << "YES"<<endl:cout<<"NO"<<endl;

	std::vector<int> path;
	path.push_back(end_point);
	bool done = false;
	int p = parent[end_point];
	while(!done) {
		if(p == start_point) {
			done = true;
		}
		path.push_back(p);
		p = parent[p];
	}
	reverse(path.begin(), path.end());
	for(int x:path) {
		cout << x <<" ";
	}
	cout << endl;
}


