// http://codeforces.com/problemset/problem/159/D
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
string T;
vector<int> P;
void pre_process(string S) {
	int n = S.length();
	if(n == 0) T = "^$";
	else {
		T += "^";
		for(int i = 0;i<n;i++) {
			T += "#" + S.substr(i,1);
		}
		T += "#$";
	}
	n = T.length();
	P.resize(n + 2,0);
	int C = 0,R = 0;
	for(int i = 1;i< n - 1;i++) {
		int mirror = C - (i - C);
		P[i] = (R > i)?min(R - i,P[mirror]):0;
		while(T[i + 1 + P[i]] == T[i - 1 - P[i]])
			P[i]++;
		if(i + P[i] > R) {
			C = i;
			R = i + P[i];
		}
	}
}
LL how_many_palin_till[2009];
void solve() {
	string str;
	cin >> str;
	int n = str.length();
	pre_process(str);
	LL ans = 0;
	how_many_palin_till[0] = 1;
	for(int i = 1;i<n;i++) {
		how_many_palin_till[i] = how_many_palin_till[i - 1];
		for(int j = 0;j<=i;j++) {
			ans += (j > 0) * ( P[i + j + 2] >= (i - j + 1) ) * how_many_palin_till[j - 1];
			//cout <<j<<" "<<i<<" ans = "<<ans << endl;
			how_many_palin_till[i] += ( P[i + j + 2] >= (i - j + 1) );
		}
		//cout <<"no of palindroms till index i :"<<i <<" "<<how_many_palin_till[i]<<endl;
	}
	cout << ans << endl;
}

