#include <bits/stdc++.h>
using namespace std;
#define INF 		1e9
#define MAX_CITY	1009
#define MAX_FUEL	109

int N,M;
int price[MAX_CITY];
int dist[MAX_CITY][MAX_FUEL];

vector<pair<int,int>> g[1009];

struct Node {
    int nd, f, mncost;
    bool operator < (const Node &A) const {
        return mncost > A.mncost;
    }
    Node(int a, int b, int c): nd(a), f(b), mncost(c) {}
};

void dijkstra(int source,int dest,int cap) {
    for(int node = 0;node<=N;node++) {
		for(int fuel = 0;fuel <=cap;fuel++) {
			dist[node][fuel] = INF;
		}
	}
    priority_queue<Node, vector<Node> > Heap;
	dist[source][0] = 0;
    Heap.push(Node(source,0,0));
    while(!Heap.empty()) {
    	auto e = Heap.top();
        Heap.pop();
        int currNode = e.nd; int currFuel = e.f; int currDist = e.mncost;
    	if(currNode == dest) {
            printf("%d\n", currDist);
            return;
        }
		// add one unit of fuel
        if(currFuel != cap) {
			if(dist[currNode][currFuel+1] > currDist + price[currNode]) {
			    dist[currNode][currFuel+1] = currDist + price[currNode];
			    Heap.push(Node(currNode, currFuel+1, dist[currNode][currFuel+1]));
			}
		}
		// go to next city
		for(auto e:g[currNode]) {
		    int nextNode 	= e.second;
			int roadLen 	= e.first;
			if(currFuel >= roadLen) {
				int remainFuel = currFuel - roadLen;
				if(dist[nextNode][remainFuel] > currDist ) {
					dist[nextNode][remainFuel] = currDist;
					Heap.push(Node(nextNode, remainFuel, dist[nextNode][remainFuel]));
				}
			}
		}
	}
    puts("impossible");
}
int main() {
	//ios_base::sync_with_stdio(false);
    while(scanf("%d %d", &N, &M) == 2) {
        for(int city = 1;city<=N;city++) {
            cin >> price[city];
            g[city].clear();
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
            dijkstra(source+1,dest+1,cap);
        }
    }	
}