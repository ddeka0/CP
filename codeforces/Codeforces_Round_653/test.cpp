#include <bits/stdc++.h>
using namespace std;
int main() {
    map<int,int> Map;
    Map[1] = 1;
    auto x = Map.lower_bound(2);
    cout << x->first <<" " << x->second << endl;
}