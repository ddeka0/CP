#include <bits/stdc++.h>
using namespace std;
int a[100009];
int b[100009];
int aa[100009];
int bb[100009];
vector<int> adj[100009];
vector<int> conn[100009];
bool seen[100009];
void bfs(int s,int cnt) {
	queue<int> Q;
	Q.push(s);
	conn[cnt].push_back(s);
	seen[s] = true;
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for(int v:adj[u]) {
			if(!seen[v]) {
				conn[cnt].push_back(v);
				seen[v] = true;
				Q.push(v);
			}
		}
	}
}
int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	int T,n,m,u,v;
	cin >> T;
	for(int q = 1;q<=T;q++) {
		cin >> n >> m;
		for(int i = 0;i<n;i++) cin >> a[i];
		for(int i = 0;i<n;i++) cin >> b[i];
		for(int i = 0;i<m;i++) {
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int cnt = 0;
		for(int i = 0;i<n;i++) {
			if(!seen[i]) {
				bfs(i,cnt);
				cnt++;
			}
		}
		cout <<" no fo connected component = "<< cnt << endl;
		for(int i = 0;i<cnt;i++) {
			for(int idx:conn[i]) {
				aa[a[idx]] = i;
				bb[b[idx]] = i;
			}
		}
		for(int i = 1;i<=n;i++) {
			cout <<i<<" "<<aa[i] << endl;
		}


		/*bool ok = true;
		for(int i = 1;i<=n;i++) {
			if(aa[i] != bb[i]) {
				ok = false;
				break;
			}
		}
		ok?cout << "YES":cout<<"NO";*/
		cout<<endl<<endl;
		memset(seen,false,sizeof seen);
	}	
	return 0;
}