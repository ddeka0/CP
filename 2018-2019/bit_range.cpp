#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL B1[100005], B2[100005];
int N;
LL query(LL* ft, int b) {
    LL sum = 0;
    while(b > 0) {
        sum += ft[b];
        b = b - (b & (-b));
    }
    return sum;
}
LL query(int b) {
    return query(B1, b) * b - query(B2, b);
}
LL range_query(int i, int j)    {
    return query(j) - query(i - 1);
}
void update(LL* ft, int k, ll v) {
    while(k<=N) {
        ft[k] += v;
        k = k + k&(-k);
    }
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
