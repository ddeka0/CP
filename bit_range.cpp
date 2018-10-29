#include <bits/stdc++.h>
using namespace std;
#define LSOne(S) (S & (-S))
typedef long long ll;
ll B1[100005], B2[100005];
int N;
ll query(ll* ft, int b) {
    ll sum = 0;
    for (; b; b -= LSOne(b)) sum += ft[b];
    return sum;
}
ll query(int b) {
    return query(B1, b) * b - query(B2, b);
}
ll range_query(int i, int j)    {
    return query(j) - query(i - 1);
}
void update(ll* ft, int k, ll v) {
    for (; k <= N; k += LSOne(k)) ft[k] += v;
}
void range_update(int i, int j, ll v)   {
    update(B1, i, v);
    update(B1, j + 1, -v);
    update(B2, i, v * (i - 1));
    update(B2, j + 1, -v * j);
}

int main()  {

    N = 1000;

    range_update(5,5,10);
    range_update(3,3,5);

    cout << range_query(5,6) << endl;
    return 0;
}
