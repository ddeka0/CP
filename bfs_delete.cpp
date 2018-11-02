#include <bits/stdc++.h>
using namespace std;
vector<int> g[100009];
int main() {
	vector<int> deg(10,0);

	g[1].push_back(2);
	g[2].push_back(1);
	deg[1]++;
	deg[2]++;

	g[2].push_back(3);
	g[3].push_back(2);
	deg[2]++;
	deg[3]++;

	g[3].push_back(4);
	g[4].push_back(3);
	deg[3]++;
	deg[4]++;

	g[4].push_back(5);
	g[5].push_back(4);
	deg[4]++;
	deg[5]++;

	vector<int> depth(10,0);

	int last_val = 0;
	std::vector<bool> deleted(10,false);
	
	queue<int> Q;
	Q.push(1);
	Q.push(5);
	
	int node_count = 5;
	while(true) {
		if(node_count == 1) {
			break;
		}
		int u = Q.front();
		Q.pop();
		deleted[u] = true;
		cout << "deleted "<<u<< endl;
		node_count--;
		for(int v:g[u]) {
			if(!deleted[v]) { // deg[v] >= 1
				deg[v]--;
				cout <<"new degree of "<<v<<" "<<deg[v]<<endl;
				if(deg[v] == 1) {
					cout << v << " pushed" <<endl;
					Q.push(v);
				}
				depth[v] = depth[u] + 1;
				cout <<"updated depth of "<<v<<" "<<depth[v]<<endl;
				last_val = depth[v];
			}
		}
	}
	cout << last_val + 1 << endl;
}


