#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool seen[1001];
void dfs(int root) {
	seen[root] = true;
	for(int v:adj[root])
		if(!seen[v]) dfs(v);
}
int main() {
	adj[0].push_back(1);
	adj[0].push_back(2);
	adj[1].push_back(3);
	adj[4].push_back(1);
	adj[6].push_back(4);
	adj[5].push_back(6);
	adj[5].push_back(2);
	adj[6].push_back(0);
	int mother;
	for(int v = 0;v<7;v++) {
		if(!seen[v]) {
			dfs(v);
			mother = v;
		}
	}
	memset(seen,false,sizeof seen); 
	dfs(mother);
	for(int i = 0;i<7;i++) {
		if(seen[i] == false) {
			mother = -1;
			break;
		}
	}
	(mother != -1 )? cout << mother:cout<<"no mother vertex";
	cout << endl;
}