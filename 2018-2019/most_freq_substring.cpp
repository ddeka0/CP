#include <bits/stdc++.h>
using namespace std;
int f[100009][30];
long long h[100009];
int minLen,maxLen;
int maxUnique;
string str;

map<long long,int> Map;

long long prime_mod0 = 1e9 + 9/*2147483647*/;

int d = 31;

inline bool check(int i,int j) {
    int cnt = 0;
    for(int c = 'a';c<='z';c++) {
        if( (f[j][c] - f[i-1][c]) > 0) {
            cnt++;
        }
    }
    return (cnt<=maxUnique);
}
long long b_exp(long long a,long long b) {
    long long res = 1;
    while(b > 0) {
        if(b&1) {
            res = (res * a)%prime_mod0;
        }
        a = (a*a)%prime_mod0;
        b = b/2;
    }
    return res;
}


void compute_hash(string const& s) {
    long long hash_value = 0;
    long long p_pow = 1;
    int i = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % prime_mod0;
        p_pow = (p_pow * d) % prime_mod0;
        h[i++] = hash_value;
    }
}
int main() {
    cin >> str;
    compute_hash(str);
    cin >> minLen >> maxLen >> maxUnique;
    int n = (int)(str.length());
    for(int i = 1;i<=n;i++) {
        for(int c = 'a';c<='z';c++) {
            f[i][c] = f[i-1][c] + (str[i-1] == c);
        }
    }
    for(int i = 1;i<=n - minLen + 1;i++) {        
        if(check(i,i+minLen-1)) { 
            long long int hh = h[i + minLen-1] - h[i-1];
            long long pw = b_exp(d,(n - i + 1));
            hh = (hh*pw)%prime_mod0;
            Map[hh]++;
        }
    }
    int ans = 0;
    for(auto x:Map) {
        ans = max(ans,x.second);
    }
    cout <<ans<<endl;
}



