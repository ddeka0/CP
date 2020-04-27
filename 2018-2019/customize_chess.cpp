#include <bits/stdc++.h>
using namespace std;
bool yes = true;
int n;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool visited[110][110];
int a[110][110];
void dfs(int x,int y,int col) {
	for(int i = 0;i<4;i++) {
		int _x = x + dx[i];
		int _y = y + dy[i];
		if(_x >= 1 && _x <= n && _y >= 1 && _y <= n) {
			if(visited[_x][_y] == false) {
				if(a[_x][_y] == col) {
					yes = false;
					return;
				}else {
					visited[_x][_y] = true;
					dfs(_x,_y,1^col);
				}
			}		
		}
	}
}
int main () {
	int T;
	cin >> T;
	for(int q = 1;q<=T;q++) {
		cin >> n;
		for(int i = 1;i<=n;i++) {
			for(int j = 1;j<=n;j++) {
				cin >> a[i][j];
			}
		}
	}
	memset(visited,false,sizeof visited);
	dfs(1,1,a[1][1]);
	if(yes) {
		cout <<"Yes"<<endl;
	}else {
		cout << "No" <<endl;
	}
	return 0;
}