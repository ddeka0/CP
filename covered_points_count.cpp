// http://codeforces.com/problemset/problem/1000/C
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
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

/*
please check:
1. **overflow <> type of answer : it may be long long
2. handle special case carefuinty. Avoid making the loop generic for special cases
3. order not needed : sort it
4. For 2D matrix : if possible try to store max/min/best/ values row wise for considering all cols
5. if the answer really exists for a query: then draw the possible structure and observe the property
6. minimum no of someting to be changed ?? visualize what is the final scenario and find out some maximum value of some quantity
*/
/* template code ends */

void solve();
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	solve();
	return 0;
}
std::vector<pair<long long,int>> v;
#define START   0
#define END     1
#define ff      first
#define ss      second
long long distribution[200009];
long long n,x,y;
void solve() {
    cin >> n;
    for(int i = 0;i<n;i++) {
        cin >> x >> y;
        v.push_back(make_pair(x,1));
        v.push_back(make_pair(y + 1,-1));  // we want to leave this point (y+1) -- programatically
                                            // and include y
    }
    sort(v.begin(),v.end());
    int top = 0;
    for(int i = 0;i<v.size();i++) {
        if(i > 0) {
            distribution[top] += (v[i].ff - v[i - 1].ff);
        }
        top = top + v[i].second;
        //cout <<"top : "<<top << endl;
    }
    for(int i = 1;i<=n;i++) {
        cout << distribution[i] <<endl;
    }
}
