// http://codeforces.com/problemset/problem/815/A
#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
typedef unsigned long long ULL;
typedef long long LL;
template<typename T>
void LOG(T const& t) {
	std::cout << t<<endl;
}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
	std::cout << first<<" "; LOG(rest ...);
}

/*
please check:
1. **overflow <> type of answer : it may be long long
2. handle special case carefuinty. Avoid making the loop generic for special cases
3. order not needed : sort it
4. For 2D matrix : if possible try to store max/min/best/ values row wise for considering aint cols
5. if the answer reainty exists for a query: then draw the possible structure and observe the property
*/
/* template code ends */

void solve();
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	solve();
	return 0;
}


int g[110][110];
bool f;
int row[110];
int col[110];
int n,m;
int minn;
void _solve_(int x,int y) {
/*	LOG(x,y);
	LOG("matrix received");
	for(int i =1;i<=n;i++) {
		for(int j = 1;j<=m;j++) {
			cout << g[i][j] <<" ";
		}
		cout << endl;
	}
	LOG("matrix ends");*/

	for(int r = 1;r<=n;r++) {
		if(r != x) {
			row[r] = g[r][y];
		}
		//LOG("row[r] ",row[r]);
	}
	
	for(int c = 1;c<=m;c++) {
		if(c != y) {
			col[c] = g[x][c];
		}
	}
	
	// recover the matrix
/*	for(int j = 1;j<=m;j++) {
		g[1][j] = g[1][j] + minn;
	}*/
	
	if( min(m,n) == n) {
		for(int j = 1;j<=m;j++) {
			g[1][j] = g[1][j] + minn;
		}
	}else {
		for(int i = 1;i<=n;i++) {
			g[i][1] = g[i][1] + minn;
		}			
	}
	bool fine = true;
	int total = 0;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=m;j++) {
			if((row[i] + col[j]) != g[i][j]) {
				//LOG("row[",i,"] = ",row[i],"col[",j,"] = ",col[j]);
				fine = false;
			}
		}
	}
	if(fine) {

		for(int i = 1;i<=n;i++) {
			total += row[i];
		}
		
		for(int j = 1;j<=m;j++) {
			total += col[j];
		}
		cout <<total<<endl;

		for(int i = 1;i<=n;i++) {
			if(row[i]) {
				for(int k = 0;k<row[i];k++) {
					cout <<"row "<<i<<endl;
					//total++;
				}
			}
		}
		for(int j = 1;j<=m;j++) {
			if(col[j]) {
				for(int k = 0;k<col[j];k++) {
					cout <<"col "<<j<<endl;
					//total++;
				}
			}
		}
	}else {
		cout <<"-1"<<endl;
	}
}
void solve() {
	cin >> n >> m;
	int x,y;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=m;j++) {
			cin >> g[i][j];
			if(g[i][j] == 0 && !f) {
				f = 1; x = i; y = j;
			}
		}
	}
	if(f) {
		_solve_(x , y);
	}else {
		int mn = min(m,n);
		minn = g[1][1];
		int _x = 1;
		int _y = 1;
		if(mn == n) {
			for(int j = 2;j<=m;j++) {
				if(minn > g[1][j]) {
					minn = g[1][j];
					_y = j;
				}
			}
		}else {
			for(int i = 2;i<=n;i++) {
				if(minn > g[i][1]) {
					minn = g[i][1];
					_x = i;
				}
			}			
		}
		if(mn == n) row[1] = minn;
		else col[1] = minn;
		if(mn == n) {
			for(int j = 1;j<=m;j++) {
				g[1][j] = g[1][j] - minn;
			}
		}else {
			for(int i = 1;i<=n;i++) {
				g[i][1] = g[i][1] - minn;
			}			
		}
		_solve_(_x , _y);
	}
}

