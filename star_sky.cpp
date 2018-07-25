//http://codeforces.com/problemset/problem/777/C
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
2. handle special case carefully. Avoid making the loop generic for special cases
3. order not needed : sort it
4. For 2D matrix : if possible try to store max/min/best/ values row wise for considering all cols
5. if the answer really exists for a query: then draw the possible structure and observe the property
*/
/* template code ends */
void solve();
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	solve();
	return 0;
}

int a[110][110][12];
int cnt[110][110][12];
bool f[110][110][12];
int b[110][110][12];

void solve() {
	int n,q,c;
	cin >> n >> q >> c;
	for(int i = 0,x,y,s;i<n;i++) {
		cin >> x >> y >> s;
		//f[y][x][s] = 1;
		b[y][x][s]++;
	}
	for(int col = 1;col <= 100;col++) {
		for(int row = 1;row <=100;row++) {
			for(int k = 0;k<=c;k++) {
				a[row][col][k] = a[row - 1][col][k] + ( b[row][col][k] /*&& f[row][col][k]*/);
			}
		}
	}
	for(int col = 1;col<=100;col++) {
		for(int k = 0;k<=c;k++) {
			cnt[1][col][k] = cnt[1][col - 1][k] + ( b[1][col][k] /*&& f[1][col][k]*/);
		}
	}
	for(int row = 1;row<=100;row++) {
		for(int k = 0;k<=c;k++) {
			cnt[row][1][k] = cnt[row - 1][1][k] + ( b[row][1][k] /*&& f[row][1][k]*/);
		}
	}
	for(int row = 2;row <= 100;row++) {
		for(int col = 2;col <= 100;col++) {
			for(int k = 0;k<=c;k++) {
				cnt[row][col][k] += cnt[row][col - 1][k] + a[row][col][k]; 	
			}
		}
	}
	
/*	for(int col = 1;col <= 5;col++) {
		for(int row = 1;row <=5;row++) {
			for(int k = 0;k<=3;k++) {
				if(cnt[row][col][k])
				LOG("row = ",row," col = ",col," c_b for k = ",k," = ",cnt[row][col][k]);
			}
		}
	}
*/

	int t,x1,x2,y1,y2;
	for(int qq = 1;qq<=q;qq++) {
		cin >> t >> x1 >> y1 >> x2 >> y2;
		LL val[11];
		int row2 = y2;
		int col2 = x2;
		int row1 = y1;
		int col1 = x1;
		memset(val,0,sizeof val);
		for(int k = 0;k<=c;k++) {
			val[k] =  cnt[row2][col2][k]
					- cnt[row1 - 1][col2][k]
					- cnt[row2][col1 - 1][k]
					+ cnt[row1 - 1][col1 -1][k];
			//LOG("( ",row2,",",col2,")"," <> ","( ",row1,",",col1,")"," count having bright =",k," : ",val[k]);
		}	
		LL ans = 0;
		for(int k = 0;k<=c;k++) {
			if(val[k]) {
				ans += ((k+t)%(c+1))*1LL * val[k];
			}
		}
		cout << ans << endl;
	}
}










