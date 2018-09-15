#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 200009;
LL bt[MAXN];
LL query(int idx) {
    LL sum = 0;
    while(idx > 0) {
        sum += bt[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
void update(int idx,LL val) {
    while(idx <= MAXN) {
        bt[idx] += val;
idx += (idx & -idx);
    }
}
int a[MAXN];
int b[MAXN];
int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int T,n,x;
    cin >> T;
    for(int q = 1;q<=T;q++) {
        cin >> n;
        for(int i = 1;i<=n;i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b + 1,b + n + 1);
        for(int i = 1;i<=n;i++) {
            int pos = lower_bound(b + 1 ,b + 1 + n,a[i]) - (b + 1);
            a[i] = pos + 1;
        }
        LL inv_count = 0;
        for(int i = n;i>=1;i--) {
            LL x = query(a[i]);
            inv_count += x;
            update(a[i],1);
        }
        cout <<inv_count<<endl;
        memset(bt,0,sizeof bt);
    }
}

