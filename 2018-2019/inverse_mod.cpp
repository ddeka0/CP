ll mypow(ll a, ll b, ll m) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        ll c = mypow(a, b/2, m);
        return (c*c)%m;
    }
    return (a * mypow(a, b-1, m)) % m;
}

ll revmod(ll a, ll m) {
    return mypow(a, m-2, m);
}