// http://acm.timus.ru/problem.aspx?space=1&num=1039
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
int N,M;
void solve() {
	cin >> N >> M;
	queue<pair<int,pair<int,int>>> Q;
	Q.push(make_pair(M,make_pair(N,0)));
	while(!Q.empty()) {
		auto p = Q.front();
		int n = p.second.first; int d = p.second.second;
		M = p.first;
		Q.pop();
		if(n == M) {
			cout << d << endl;
			return;
		}
		if(n > M) {
			Q.push(make_pair(M,make_pair(n - 1,d + 1)));
		}
		if(n < M) {
			if(1&M) {
				Q.push(make_pair(M+1,make_pair(n,d + 1)));
			}else {
				Q.push(make_pair(M>>1,make_pair(n,d + 1)));
			}
		}
	}
}