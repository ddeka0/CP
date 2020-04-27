// http://codeforces.com/problemset/problem/446/A
#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
typedef unsigned long long Uint;
typedef long long int;
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
	ios_base::sync_with_stdio(NUint);
	cin.tie(NUint);
	solve();
	return 0;
}
long long dp[109][109][109];
int cost[109][109];
int a[109];
#define INF 1e17
int n,m,k;

long long recurse(int indx,int this_col,int segmnt) {
	//cout <<">>>> entry "<<indx<<" "<<this_col<<" "<<segmnt<<endl;
	if(segmnt < 1) {
	//	cout <<" )) "<<indx<<" "<<this_col<<" "<<segmnt<<" returns = "<<INF<<endl;
		return dp[indx][this_col][segmnt] = INF; // invalid case
	}

	if(dp[indx][this_col][segmnt] != -1) {
	//	cout <<" (( "<<indx<<" "<<this_col<<" "<<segmnt<<" returns = "<<dp[indx][this_col][segmnt]<<endl;
		return dp[indx][this_col][segmnt]; // found
	}
	
	long long ans = INF;
	//cout <<"initial  ans = "<<ans << endl;
	
	if(indx == n) {

		if( segmnt != 1) {
	//		cout <<" ** "<<indx<<" "<<this_col<<" "<<segmnt<<" returns = "<<ans<<endl;
			return dp[indx][this_col][segmnt] = INF; // remaining segment must be one
		}
		
		if(a[indx] && a[indx] != this_col) { // colored tree but instruction for different colour : return INF
	
	//		cout <<" && "<<indx<<" "<<this_col<<" "<<segmnt<<" returns = "<<INF<<endl;
			return dp[indx][this_col][segmnt] = INF;
	
		}

		dp[indx][this_col][segmnt] = a[indx]? 0 : cost[indx][this_col]; // add the cost this last tree
	//	cout <<" @@ "<<indx<<" "<<this_col<<" "<<segmnt<<" returns = "<<dp[indx][this_col][segmnt]<<endl;
		return dp[indx][this_col][segmnt];
	}
	if(a[indx] == 0) {
		// indx is an uncolored three

		// try aint color
		for(int i = 1;i<=m;i++) {
			
			ans = min(ans , recurse(indx + 1,i,segmnt - (this_col != i) ) + cost[indx][this_col] ); // add the current cost also
		
		}

	}else {

		if(this_col != a[indx]) {
	//		cout <<" ^^ "<<indx<<" "<<this_col<<" "<<segmnt<<" returns = "<<INF<<endl;
			return dp[indx][this_col][segmnt] = INF; // colored tree : bad move
		}
		
		else {

			for(int i = 1;i<=m;i++) {
		
				ans = min( ans , recurse(indx + 1,i,segmnt - (this_col != i)) );
		
			}
		
		}
	}	
	// cout <<" ## "<<indx<<" "<<this_col<<" "<<segmnt<<" returns = "<<ans<<endl;
	return dp[indx][this_col][segmnt] = ans;
}

void solve() {
	cin >>n>>m>>k;
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=m;j++) { // start the colour index from 1 because we have to use the value zero
			cin >> cost[i][j];
		}
	}
	memset(dp,-1,sizeof dp);

	long long ans  = INF;
	
	for(int i = 1;i<=m;i++) {
		ans = min(ans,recurse(1,i,k));
		//cout << endl;
	}
	
	if(ans == INF) {
		cout << -1 << endl;
	}else {
		cout << ans << endl;
	}
}



