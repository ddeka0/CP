// http://codeforces.com/contest/992/problem/B
#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
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
long long gcd(long long a, long long b) { return b ? gcd(b, a%b) : a; }
void solve() {

	int L,R,X,Y;
	cin >> L >> R >> X >> Y;
	
	if(Y%X!=0)
    {
        cout<<0<<endl;
        return;
    }

	int M = Y/X;
	long long ans = 0;
	
	for(int k = 1;k*k <=M;k++) {
		
		if(M%k == 0) {
			
			int k2 = M/k;
			long long g = gcd(k*X*1LL,k2*X*1LL);

			if( ( g == X*1LL  ) && 
				
				( (k*X*1LL >=L) && (k*X*1LL <=R)  ) && 

				( (k2*X*1LL >=L) && (k2*X*1LL <=R ) ) ) {
			
				if(k == k2) ans += 1;
			
				else ans += 2;
			}			
		}
	}
	
	cout << ans << endl;
}


