#include <bits/stdc++.h>
using namespace std;

vector<int> g[400005];
int num[400005];
int lnum[400005];
int dfsCounter;
stack<int> Stack;
int mxSize = 0;
int snode;

void dfsBICC(int u,int paren = -1) {
    num[u] = lnum[u] = ++dfsCounter;
    for(auto &v:g[u]) {
        if(num[v] == 0) {
            dfsBICC(v,u);
            if(lnum[v] > num[u]) { // u <-> v is a bridge
                int sz = 0,node = 0;
                while(!Stack.empty() && lnum[Stack.top()] > lnum[u]) {
                    //cout << Stack.top().first << endl;
                    node = Stack.top();
                    sz++;
                    Stack.pop();
                }
                if(sz > mxSize) {
                    mxSize = sz;
                    snode = node;
                }
            }
            lnum[u] = min(lnum[u],lnum[v]);
        }else if(v != paren) {
            lnum[u] = min(lnum[u],num[v]);
        }
    }
    Stack.push(u);
}

bool completed[400005];
int U[400005];
int V[400005];
bool visited[400005];

std::map<pair<int,int>,int> Map;

void dfsFinal(int u,int paren = -1) {
	if(visited[u]) return;
	visited[u] = true;
	for(auto &v:g[u]) {
		if(v != paren) {
			int x = Map[{u,v}];
			if(!completed[x]) {
				U[x] = v;
				V[x] = u;
				completed[x] = true;
				dfsFinal(v,u);
			}
		}
	}
}

int main() {
    int n,m;
    cin >> n >> m;
    for(int i = 0;i<m;i++) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        Map[{u,v}] = Map[{v,u}] = i+1;
    }
    
    dfsBICC(1);
    

    if(Stack.size() > mxSize) {
        mxSize = Stack.size();
        snode = Stack.top();
    }
    
    // cout << snode << endl;
    
    dfsFinal(snode);

    cout << mxSize << endl;
    for(int i = 0;i<m;i++) 
    	cout << U[i+1]<<" "<<V[i+1]<< endl;
}