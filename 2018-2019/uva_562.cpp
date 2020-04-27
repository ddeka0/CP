// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=503
#include<bits/stdc++.h>
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
/*bool dp[50009][109];*/
bool dp[500009];
int a[109];
int T,n;
void solve() {
	
	cin >> T;
	
	for(int q = 1;q<=T;q++) {
		cin >> n;
		
		int SUM = 0;
		for(int i = 1;i<=n;i++) {
			cin >> a[i];
			SUM += a[i];
		}

		memset(dp,false,sizeof dp);
		
/*		for(int item = 0;item<=n;item++) dp[item][0] = true;
		for(int s = 1;s<=SUM;s++) dp[0][s] = false;
		*/
		for(int s = 1;s<= SUM;s++) dp[s] = false;
		dp[0] = true;
		for(int item = 1;item <=n;item++) {
			for(int s = SUM/2;s >= 0;s--) { 

/*				for(int s = 0;s <= SUM/2;s++)
					will not work becase I dont have item state in my dp states
					dp[s - a[item]] will cause error and reuse the numbers*/									

				if( (a[item] <= s) && (dp[s - a[item]]) ) {
					
 					dp[s] = 1;
					

					// dp[item][s] = dp[item - 1][s] || dp[item - 1][s - a[item]];
					
					// dp[s] = dp[s] || dp[s - a[item]];
				}

				cout <<item<<" "<<"s = "<<s<<" "<<dp[s] << endl;

				/*else {
					//dp[item][s] = dp[item - 1][s];
					dp[s] = dp[s];		
					
				}*/
			}

		}
		
		int min_diff = 0;

		for(int s = SUM/2;s >= 1;s--) {
		
			if(dp[s]) {
				
				min_diff = s;
				break;
			}
		}
		cout << SUM - 2*min_diff << endl;
	}
}