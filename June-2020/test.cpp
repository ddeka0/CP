#include <bits/stdc++.h>
using namespace std;
#define A first
int main() {
    std::shared_ptr<vector<int>[]> adj = nullptr;
    adj = shared_ptr<vector<int>[]>(new vector<int>[10]);
    adj[0].push_back(1);
    adj[0].push_back(2);

    adj[5].push_back(1);
    adj[5].push_back(2);

    for(auto &x:adj[0]) {
        cout << x <<" ";
    }
    cout << endl;
    vector<vector<int>> v;
    v.push_back(vector<int>{0,1});
    v.push_back(vector<int>{0,2});
    v.push_back(vector<int>{2,3});
    v.push_back(vector<int>{2,4});
    v.push_back(vector<int>{2,5});

    for(auto &x:v) {
        for(auto &y:x) {
            cout << y <<" ";
        }
        cout << endl;
    }

    pair<int,int> p;
    p.A = 1;
    cout << p.A << endl;

}