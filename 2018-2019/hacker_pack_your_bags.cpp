// http://codeforces.com/problemset/problem/822/C
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
/*#define ff first
#define ss second
#define R 	0
#define L 	1

vector<tuple<int,int,bool,int>> v; // edge - duration - type - cost 
int Map[500000];
int _LL[210000];
int _RR[210000];
int CC[210000];*/

int N, X;
int L[210000], R[210000], cost[210000];

int dp[210000];

int ans = -1;
std::vector <std::tuple <int, int, int>> op;
void solve() {
/*	int n,x,l,r;
	LL c;
	cin >> n >> x;
	for(int i = 1;i<=n;i++) {
		cin >> _LL[i] >> _RR[i] >> CC[i];
		v.push_back(make_tuple(_LL[i],i,L,CC[i]));
		v.push_back(make_tuple(_RR[i],i,R,CC[i]));
	}
	sort(v.begin(), v.end());
	int ans = -1;
	for(auto e:v) {
		int duration = _RR[get<1>(e)] - _LL[get<1>(e)] + 1;
		if(get<2>(e) == L) {
			int rem_duration = x - duration;
			if( (rem_duration < 0 ) || Map[rem_duration] == 0 ) continue;
			if(ans == -1 || (ans > ( Map[rem_duration] + CC[get<1>(e)]) ) ) { 
				//cout << ans << endl;
				//cout <<"JJ "<<Map[rem_duration] <<endl;
				ans = Map[rem_duration] + CC[get<1>(e)];
			}
		}else {
			if(Map[duration] == 0 || Map[duration] > CC[get<1>(e)]) {
				Map[duration] = CC[get<1>(e)];
				//cout <<"KK "<<Map[duration] <<endl;
			}
		}
	}	
	cout <<ans<<endl;*/
	scanf ("%d%d", &N, &X);
	for (int i = 0; i < N; ++i) {
		scanf ("%d%d%d", &L[i], &R[i], &cost[i]);
		op.push_back (std::make_tuple (L[i], 0, i));
		op.push_back (std::make_tuple (R[i], 1, i));
	}
	std::sort (op.begin (), op.end ());
	for (int i = 0; i < op.size (); ++i) {
		int o = std::get <1> (op[i]), ind = std::get <2> (op[i]);
		if (o == 0) {
			int dur = R[ind] - L[ind] + 1, nec = X - dur;
			if (nec < 0 || dp[nec] == 0) continue;
			if (ans == -1 || ans > dp[nec] + cost[ind]) ans = dp[nec] + cost[ind];
		} else {
			int dur = R[ind] - L[ind] + 1;
			if (dp[dur] == 0 || dp[dur] > cost[ind]) dp[dur] = cost[ind];
		}
	}
	printf ("%d\n", ans);
}

