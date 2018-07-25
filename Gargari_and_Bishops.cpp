#include <bits/stdc++.h>
using namespace std;
//typedef unsigned long long int ULL;
int a[2002][2002];
long long int l[4010];
long long int r[4010];
long long int ans[2] = {-1,-1};
pair<int,int> ans_loc[2];
//typedef unsigned long long int ULL;
int main() {
    cin.sync_with_stdio(false);
    int n;
    cin >> n;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> a[i][j];
            l[i+j] += a[i][j];
            r[i+n-j] += a[i][j];
        }
    }
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=n;j++) {
            long long int value = l[i+j] + r[i+n-j] - a[i][j];
            int idx = (i+j)%2;
            if(value > ans[idx]) {
                ans[idx] = value;
                ans_loc[idx].first = i;
                ans_loc[idx].second = j;
            }
        }
    }
    cout<<ans[0]+ans[1]<<"\n";
    cout<<ans_loc[0].first<<" "<<ans_loc[0].second<<" ";
    cout<<ans_loc[1].first<<" "<<ans_loc[1].second<<"\n";
    return 0;
}
