/*  Author  : Debashish Deka
    Date    : April 28th 2020
	Compiler and Lang: gcc-10 & C++17 
    IP:
    4
    6 2
    abaaba
    6 3
    abaaba
    36 9
    hippopotomonstrosesquippedaliophobia
    21 7
    wudixiaoxingxingheclp
	OP:
	2
	0
	23
	16
*/
#include <bits/stdc++.h>
using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#define debug(stuff) cout << #stuff << ": " << stuff <<endl
#define debugc(stuff) cout << #stuff << ": "; for(auto x: stuff) cout << x << " "; cout << endl;

int freq[200001][26];
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T; cin >> T;
    for(int tc=1; tc<=T; tc++) {
		int n,k;
		string s;
		cin >> n >> k;
		cin >> s;
		for (int idx=0; idx<k; idx++){
			for (int j=0; j<26; j++){
				freq[idx][j]=0;
			}
		}
		for(int idx = 0;idx<n;idx++) {
			freq[idx%k][s[idx] - 'a']++; // all are lower case latter
		}
		auto ans_at_position = [k](int pos) {
			int mx_freq = -1;
			int total_chars = 0;
			for(char c = 'a'; c<='z'; c++) {
				int sm = freq[pos][c -'a'] + freq[k-1-pos][c - 'a'];
				mx_freq = max(mx_freq,sm);
				total_chars += sm;
				// trace(total_chars,mx_freq);
				// debug(total_chars);
			}
			return total_chars - mx_freq;
		};
		int ans = 0;
		for(int idx=0; idx<=k-1-idx; idx++) {
			auto v = ans_at_position(idx);
			if(idx == k - 1 - idx) {
				v = v/2;
			}
			ans += v;
		}
		cout << ans << endl;
    }
}