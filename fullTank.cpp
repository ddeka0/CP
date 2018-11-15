#include <bits/stdc++.h>
using namespace std;

#define NODE 		0
#define FUEL		1
#define DIST 		2

#define INF 		1e9
#define MAX_CITY	1009
#define MAX_FUEL	109

int N,M;
int price[MAX_CITY];
int dist[MAX_CITY][MAX_FUEL];

vector<pair<int,int>> g[1009];
set<tuple<int,int,int>> Heap;

bool compare(tuple<int,int,int> &a,tuple<int,int,int> &b) {
	return get<DIST>(a) <= get<DIST>(b);
}

int dijkstra(int source,int dest,int cap) {
	for(int node = 1;node<=N;node++) {
		for(int fuel = 0;fuel <=cap;fuel++) {
			dist[node][fuel] = INF;
		}
	}
	dist[source][0] = 0;
	Heap.insert(make_tuple(source,0,0));
	while(!Heap.empty()) {
		auto e = *(Heap.begin());
		Heap.erase(Heap.begin());
		int currNode = get<NODE>(e); 
		int currFuel = get<FUEL>(e); 
		int currDist = get<DIST>(e);
		if(currNode == dest) {
			return currDist;
		}
		// add one unit of fuel
		if(currFuel != cap) {
			if(dist[currNode][currFuel+1] > currDist + price[currNode]) {
				auto e = Heap.find(make_tuple(currNode,currFuel+1, dist[currNode][currFuel+1]));
				if(e != Heap.end()) Heap.erase(e);
				dist[currNode][currFuel+1] = currDist + price[currNode];
				Heap.insert(make_tuple(currNode, currFuel+1, dist[currNode][currFuel+1]));
			}
		}
		// go to next city
		for(auto e:g[currNode]) {
			int nextNode 	= e.second;
			int roadLen 	= e.first;
			if(currFuel >= roadLen) {
				int remainFuel = currFuel - roadLen;
				if(dist[nextNode][remainFuel] > currDist ) {
					auto e = Heap.find(make_tuple(nextNode,remainFuel, dist[nextNode][remainFuel]));
					if(e != Heap.end()) Heap.erase(e);
					dist[nextNode][remainFuel] = currDist;
					Heap.insert(make_tuple(nextNode, remainFuel, dist[nextNode][remainFuel]));
				}
			}
		}
	}
	int ret = INF;
	for(int fuel = 0;fuel<=cap;fuel++) {
		ret = min(ret,dist[dest][fuel]);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	
	for(int city = 1;city<=N;city++) {
		cin >> price[city];
	}
	
	int city1,city2,roadLen;
	for(int i = 1;i<=M;i++) {
		cin >> city1 >> city2 >> roadLen;
		g[city1+1].push_back(make_pair(roadLen,city2+1));
		g[city2+1].push_back(make_pair(roadLen,city1+1));
	}
	
	int Q,cap,source,dest;
	cin >> Q;
	for(int q = 1;q<=Q;q++) {
		cin >> cap >> source >> dest;
		int ret = dijkstra(source+1,dest+1,cap);
		if(ret == INF) {
			cout <<"impossible"<<endl;
		}else {
			cout << ret << endl;
		}
	}
}