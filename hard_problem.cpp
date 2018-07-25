// http://codeforces.com/problemset/problem/446/A
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


#define SAME 	1
#define REV		0

long long c[100009];
string a[100009];

long long dp[100009][2];
long long recurse(int indx,bool flag) {

	//cout << "("<<indx<<","<<flag<<") entry"<<endl;
	if(dp[indx][flag] != -1) {
		//cout << "$$ ("<<indx<<","<<flag<<") returns = "<<dp[indx][flag]<<endl;
		return dp[indx][flag];
	}

	//cout <<" hi "<<endl;
	string this_string = a[indx];
	string next_rev = a[indx + 1];
	reverse(next_rev.begin(),next_rev.end());
	
	string next = a[indx + 1];
	
	long long res = LLONG_MAX;
	
	long long add = 0;
	
	if(flag == 0) {
		reverse(this_string.begin(), this_string.end());
		add = c[indx];	
	}

	if(this_string <= next) {
		//cout <<"1 : "<<this_string<<" "<<next<<endl;
		res = recurse(indx + 1,SAME);
	}
	if(this_string <= next_rev) {
		//cout <<"2 : "<<this_string<<" "<<next_rev<<endl;
		res = min(res,recurse(indx + 1,REV));
	}
	
	if(res != LLONG_MAX) res += add;

	//cout << "## ("<<indx<<","<<flag<<") returns = "<<res<<endl;
	return dp[indx][flag] = res;
}
void solve() {
	int n;
	cin >> n;
	for(int i = 0;i<n;i++) {
		cin >> c[i];
	}
	
	for(int i = 0;i<n;i++) {
		cin >> a[i];
	}

	memset(dp,-1,sizeof dp);
	dp[n-1][REV] 	= c[n-1];
	dp[n-1][SAME]	= 0;
	
	long long ans = min( recurse(0,REV) , recurse(0,SAME) );
	
	if(ans == LLONG_MAX) {
		cout << -1 << endl;
	}else {
		cout << ans << endl;
	}
}





