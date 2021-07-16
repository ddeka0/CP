#include <bits/stdc++.h>
using namespace std;

int main() {
    int n[3];
    
    cin >> n[0] >> n[1] >> n[2];

    vector<long long> v[3];
    vector<pair<long long,int>> sorted;

    for(int i = 0;i<3;i++) {
        v[i].assign(n[i],0);
        long long ss = 0;
        for(int j = 0;j<n[i];j++) {
            cin >> v[i][j];
            ss += v[i][j];
        }
        sorted.push_back({ss,i});
    }
    
    sort(sorted.begin(),sorted.end());

    int one = sorted[0].second;
    int two = sorted[1].second;
    int three = sorted[2].second;

    sort(v[one].begin(),v[one].end());
    sort(v[two].begin(),v[two].end());
    

    long long ans = 0;
    for(auto x : v[three]) {
        ans += x;
    }
    for(auto x : v[two]) {
        ans += x;
    }
    for(auto x : v[one]) {
        ans -= x;
    }

    long long temp = 0;
    for(auto x : v[three]) {
        temp += x;
    }
    for(auto x : v[two]) {
        temp += x;
    }
    for(auto x : v[one]) {
        temp += x;
    }


    temp -= 2*v[two][0];
    temp -= 2*v[one][0];

    ans = max(ans,temp);

    std::cout << ans << std::endl;
    
}