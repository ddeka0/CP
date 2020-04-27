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
int n,k;
int h[11];
int dp[509][5009];
int frequency[100009];
int fav_frequency[100009];
// for a particular card x : the card has n players who likes it
// and frequency of this card is m in the given cards
// recurse will try to distribute among these n player (not any others)
// and try to get an optimal ans for this card distribution
// recurse(n,m) means
// what is the optimal distribution of m cards among n players
int recurse(int pl_cnt,int card_cnt) {
	if(dp[pl_cnt][card_cnt] != -1) return dp[pl_cnt][card_cnt];
	int res = 0;
	for(int num_cards = 0;num_cards<=min(card_cnt,k);num_cards++) {
		// give num_cards to player and recurse on the remaing players
		// try all possible number of cards on this player
		res = max(res, recurse( pl_cnt - 1,card_cnt - num_cards) + h[num_cards] );
	}
	return dp[pl_cnt][card_cnt] = res;
}
void solve() {
	cin >> n >> k;
	for(int i = 1,x;i<=n*k;i++) {
		cin >> x;
		frequency[x]++;
	}
	for(int i = 1,x;i<=n;i++) {
		cin >> x;
		fav_frequency[x]++;
	}
	for(int i = 1;i<=k;i++) {
		cin >> h[i];
	}
	memset(dp,-1,sizeof dp);
	memset(dp[0],0,sizeof dp[0]);
	int ans = 0;
	for(int a_card = 1;a_card <=100001;a_card++) {
		// distribute this card to the player who likes this card
		// fav_frequency[a_card] = no of player who has this card as fav
		// frequency[a_card] = frequency of this card in the original n*k cards
		ans += recurse(fav_frequency[a_card],frequency[a_card]);
	}
	cout << ans << endl;
}

