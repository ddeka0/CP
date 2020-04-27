#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,p;
    cin >> n; cin >> p;
    a[p] = 1;
    bool decs = true;
    for(int i = 2,x;i<=n;i++) {
            cin >> x;
            a[x] = i;
            if(x > p) decs = false;
            p = x;
        }
    if(decs){ cout << -1 << endl; return 0;}
    int mn = a[1];
    int mx = -1;
    for(int i = 1;i<=n;i++) {
            mn = min(mn,a[i]);
            mx = max(mx,a[i] - mn);
        }
    cout << mx;
    return 0;
}
