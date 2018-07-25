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
/*unordered_map<int,int> Map;*/
int K;
string str;
int sum[1000009]; 	// stores the cummulative sum
int indx[1000009];	// stores the first occurance of a cummulative sum
void solve() {
	memset(indx,-1,sizeof indx);
	cin >> K;
	cin >> str;
	indx[0] = 0;
	
	// 1 based indexing for cummulative sum

	for(int i = 0;i<str.length();i++) {
		sum[i + 1] = sum[i] + (str[i] == '1');
		if(indx[sum[i + 1]] == -1) { // set the flag to the index
			indx[sum[i + 1]] = i + 1;
		}
	}

	LL ans = 0;
	for(int i = 1;i<=str.length();i++) {
		if(K == 0) { 						// if sum is 7 then we look for first occurance of 7
			if(str[i - 1] != '1') {
				ans += i - indx[sum[i]];	// and subtract it from 1 based index i
			}
		}else {
			int s = sum[i] - K;				// if K = 3 and cumm_sum = 7
			if(s >= 0) {
				int y = indx[s];			// look for first index of cumm_sum = 4
				int z = indx[s + 1];		// look for first index of cumm_sum = 4 + 1
				ans += z - y;				// subtract these
			}
		}
	}
	cout << ans <<endl;
}