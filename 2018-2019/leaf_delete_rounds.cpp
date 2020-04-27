#include <bits/stdc++.h>
using namespace std;
vector<int> g[100009];
int main() {
	vector<int> deg(10,0);

	g[1].push_back(2);
	g[2].push_back(1);
	deg[1]++;
	deg[2]++;


	g[2].push_back(4);
	g[4].push_back(2);
	deg[2]++;
	deg[4]++;

	g[4].push_back(5);
	g[5].push_back(4);
	deg[4]++;
	deg[5]++;


	g[6].push_back(4);
	g[4].push_back(6);
	deg[6]++;
	deg[4]++;


	g[6].push_back(7);
	g[7].push_back(6);
	deg[6]++;
	deg[7]++;


	g[2].push_back(3);
	g[3].push_back(2);
	deg[3]++;
	deg[2]++;

	vector<int> depth(10,0);
	set<pair<int,int>> Heap;
	Heap.insert(make_pair(deg[1],1));
	Heap.insert(make_pair(deg[2],2));
	Heap.insert(make_pair(deg[3],3));
	Heap.insert(make_pair(deg[4],4));
	Heap.insert(make_pair(deg[5],5));
	Heap.insert(make_pair(deg[6],6));
	Heap.insert(make_pair(deg[7],7));	
	int last_val = 0;
	std::vector<bool> deleted(10,false);
	while(true) {
		if(Heap.size() == 1) {
			break;
		}
		auto p = *Heap.begin();
		int u = p.second;
		cout << u<<" deleted"<< endl;
		deleted[u] = true;
		Heap.erase(p);
		for(int v:g[u]) {
			if(!deleted[v]) {
				Heap.erase(Heap.find(make_pair(deg[v],v)));
				if(v) {
					deg[v]--;
					Heap.insert(make_pair(deg[v],v));
				}
				depth[v] = depth[u] + 1;
				last_val = depth[v];
			}
		}
	}
	cout << last_val << endl; 
}


