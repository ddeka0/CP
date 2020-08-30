#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<vector<int>> bridges;
	int num[100005];
	int lnum[100005];
	vector<int> adj[100005];
	int dfs_counter;

	void dfs(int u,int paren = -1 ) {
		num[u] = lnum[u] = ++dfs_counter;
		for(auto v:adj[u]) {
			if(num[v] == 0) { // not visited
				dfs(v,u);
				if(lnum[v] > num[u]) {
					bridges.push_back(std::vector<int>{u,v});
				}
				// v is just explored, try to minimize with v's lnum
				lnum[u] = min(lnum[u],lnum[v]);
			}else if(v != paren) { // visited & not direct cycle
				//back edge is found, try to minimize lnum with v's num
				lnum[u] = min(lnum[u],num[v]);
			}
		}
	}
	
	// output [[a,b],[c,d],...] set of edges: these edges are bridges
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
       	for(auto &edge:connections) {
       		int u = edge[0];
       		int v = edge[1];
       		adj[u].push_back(v);
       		adj[v].push_back(u);
       	}
       	for(int i = 0;i<100005;i++) {
       		num[i] = lnum[i] = 0;
       	}
       	dfs_counter = 0;
       	dfs(0);
       	return bridges;
    }
};


int main() {
	Solution s;
	vector<vector<int>> connections;

	connections.push_back(std::vector<int>{0,1});
	connections.push_back(std::vector<int>{1,2});
	connections.push_back(std::vector<int>{2,0});
	connections.push_back(std::vector<int>{1,3});

	for(auto &e:s.criticalConnections(4,connections)) {
		cout << e[0] <<" "<<e[1] << endl;
	}
}