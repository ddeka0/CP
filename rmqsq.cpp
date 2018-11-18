#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
vector<int> Lazy;
vector<int> t;
vector<int> a;
int N,Q;
void lazy_update(int root, int ll, int rr) {
    if(Lazy[root] == -1) return;
    if(ll != rr) { 
        Lazy[root*2] = Lazy[root*2+1] = Lazy[root];
    }
    t[root] = Lazy[root]; 
    Lazy[root] = -1;
}
void build(int root,int l,int r) {
    if(l == r) {
        t[root] = a[l];
    }else {
        int m = (l+r)/2;
        build(2*root,l,m);
        build(2*root+1,m+1,r);
        t[root] = min(t[2*root],t[2*root + 1]);
    }
}
void assign_range(int u, int ll, int rr, int L, int R, int X) {
    lazy_update(u, ll, rr);
    if (ll>R || L>rr) return;
    if (L<=ll && rr<=R) { 
        Lazy[u] = X; 
        lazy_update(u, ll, rr); 
        return; 
    }
    assign_range(2*u, ll, (ll+rr)/2, L, R, X);
    assign_range(2*u+1, (ll+rr)/2+1, rr, L, R, X);
    t[u] = min(t[2*u], t[2*u+1]);
}
int query(int root, int ll, int rr, int L, int R) {
    lazy_update(root, ll, rr);
    if (ll>R || L>rr) return 1e9;
    if (L<=ll && rr<=R) {
        return t[root];
    }
    int min1 = query(2*root, ll, (ll+rr)/2, L, R);
    int min2 = query(2*root+1, (ll+rr)/2+1, rr, L, R);
    return min(min1,min2);
}
int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    Lazy.resize(4*(N+2),-1);
    t.resize(4*(N+2),0);
    a.resize(N+2);
    for(int i = 1;i<=N;i++) {
        cin >> a[i];
    }
    assign_range(1,1,N,N,N,0);
    for(int i = N - 1;i >= 1;i--) {
        if(a[i] == 0) {
            assign_range(1,1,N,i,i,INF);
            continue;
        }
        int x = i + 1;
        int y = min(N,i + a[i]);
        assign_range(1,1,N,i,i, query(1,1,N,x,y) + 1 );
    }
    cout << query(1,1,N,1,1) << endl;
}