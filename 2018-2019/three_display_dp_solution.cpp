#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <locale.h>
#include <vector>
#include <iomanip>
#include <cassert>
#include <cstring>

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define pb push_back
#define mp make_pair
#define endl "\n"
#define rep(i,x,y) for(int i = x; i <= y; ++i)
#define repr(i,x,y) for(int i = x; i >= y; --i)
#define y1 wearsdfasdf
#define F first
#define onlycin ios_base :: sync_with_stdio(false); cin.tie(0);
#define S second

typedef long long ll;

const int N = (1e6) + 322;
const ll mod = (ll)(1e9) + 7;

using namespace std;

ll n, dp[N][4], c[N], s[N], mn = mod * mod;

int main () {
  onlycin
  cin >> n;
  rep(i, 1, n) {
    cin >> s[i];
  }
  rep(i, 1, n) {
    cin >> c[i];
  }
  rep(i, 0, n + 1) rep(j, 0, 3) dp[i][j] = mod * mod;
  rep(i, 1, n) {
    dp[i][1] = c[i];
    rep(j, 1, i - 1) {
      if (s[i] > s[j]) {
        dp[i][2] = min(dp[i][2], dp[j][1] + c[i]);
        dp[i][3] = min(dp[i][3], dp[j][2] + c[i]);
      }
    }
    mn = min(mn, dp[i][3]);
  }
  if (mn >= mod * mod) {
    cout << -1;
    return 0;
  }
  cout << mn;
  return 0;
}



