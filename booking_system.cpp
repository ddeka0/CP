// https://codeforces.com/problemset/problem/999/F
#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
template<typename T>
void LOG(T const& t) {
	std::cout <<t<<endl;
}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
	std::cout << first<<" "; LOG(rest ...);
}
#define get(i,x) get<(i)>(x) 
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
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
#define ff first
#define ss second
int n,k;
pair<int,int> r[1009];
#define SIZE 	0
#define PRICE 	1
#define USED	2
#define REQ_NUM	3
tuple<int,int,int> dp[1009];
bool used[1009];
vector<tuple<int,int,bool,int>> cp;
int recurse(int m) {
	if(get<1>(dp[m]) != -1) {
		return get<1>(dp[m]);
	}
	int res = 0;
	int indx = -1;
	for(auto e:cp) {
		if( get<SIZE>(e) <= r[m].ff && !used[get<REQ_NUM>(e)] ) {
			used[get<REQ_NUM>(e)] = true;
			int val = get<PRICE>(e) + recurse(m - 1);
			if(val > res) {
				res = val;
				indx = get<REQ_NUM>(e);
			}
			used[get<REQ_NUM>(e)] = false;
		}
	}
	if(indx > 0) {
		used[indx] = true;
	}
	dp[m] = make_tuple(indx,res,r[m].ss);
	return get<1>(dp[m]); 
}
void solve() {
	cin >> n;
	for(int i = 1,c,p;i<=n;i++) {
		cin >> c >> p;
		cp.push_back(make_tuple(c,p,false,i));
	}
	cin >> k;
	for(int i = 1,x;i<=k;i++) {
		cin >> x;
		r[i] = make_pair(x,i);
	}
	for(int i = 0;i<1009;i++) {
		get<0>(dp[i]) = -1;
		get<1>(dp[i]) = -1;
		get<2>(dp[i]) = 0;
	}
	get<1>(dp[0]) = 0;
	sort(cp.begin(), cp.end(),[](tuple<int,int,bool,int> const &t1, tuple<int,int,bool,int> const &t2) {
        return get<0>(t1) > get<0>(t2);
    });
	sort(r + 1,r + k + 1);
	int price = recurse(k);
	int cnt = 0;
	for(int i = 1;i<=k;i++) if(get<1>(dp[i]) > 0) cnt++;
	cout <<cnt<<" "<<price << endl;
	for(int i = k;i>=1;i--) {
		if(get<0>(dp[i]) != -1) {
			cout <<get<0>(dp[i])<<" "<<get<2>(dp[i])<<endl;
		}
	}	
}






