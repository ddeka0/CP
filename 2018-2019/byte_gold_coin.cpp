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

std::map<long long, long long> dp;
long long doller(long long n) {
    if(n == 0) return 0;
    if(dp[n] != 0) return dp[n];
    dp[n] = doller(n/2) + doller(n/3) + doller(n/4);
    if(dp[n] < n) dp[n] = n;
    
    return dp[n];

}
void solve() {
    long long n;
    while(cin >> n) {
        cout <<"answer for n "<<n<<" : "<<doller(n)<<endl;
        cout <<"map size = "<<dp.size() << endl;
    }

}