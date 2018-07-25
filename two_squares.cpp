// http://codeforces.com/contest/994/problem/C
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
#define ff 	first
#define ss 	second
pair<int,int> rec1[4];
pair<int,int> rec2[4];
#define EPS 0.0001
double area(int x1, int y1, int x2, int y2, int x3, int y3) {
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}
bool check(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x, int y) {
    double A = area(x1, y1, x2, y2, x3, y3) + area(x1, y1, x4, y4, x3, y3);
    double A1 = area(x, y, x1, y1, x2, y2); double A2 = area(x, y, x2, y2, x3, y3);
    double A3 = area(x, y, x3, y3, x4, y4); double A4 = area(x, y, x1, y1, x4, y4);
    return fabs(A - (A1 + A2 + A3 + A4)) <= EPS;
}
void solve() {
	int x,y;
	for(int i = 0;i<4;i++ ) {
		cin >> x >> y;
		rec1[i] = make_pair(x,y);
	}
	for(int i = 0;i<4;i++ ) {
		cin >> x >> y;
		rec2[i] = make_pair(x,y);
	}
	for(int i = -100;i<=100;i++) {
		for(int j = -100;j<=100;j++) {
			if(check(rec2[0].ff , rec2[0].ss , rec2[1].ff , rec2[1].ss , rec2[2].ff , rec2[2].ss , 
				rec2[3].ff , rec2[3].ss , i , j ) &&
				check(rec1[0].ff , rec1[0].ss , rec1[1].ff , rec1[1].ss , rec1[2].ff , rec1[2].ss , 
				rec1[3].ff , rec1[3].ss , i , j )) {
				cout <<"YES"<<endl;
				return;
			}
		}
	}
	cout << "NO" <<endl;
}