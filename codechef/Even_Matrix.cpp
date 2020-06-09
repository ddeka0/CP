#include <bits/stdc++.h>
using namespace std;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#define debug(stuff) cout << #stuff << ": " << stuff <<endl
#define debugc(stuff) cout << #stuff << ": "; for(auto x: stuff) cout << x << " "; cout << endl;

int main() {
    int T;
    cin >> T;
    for(int t = 1;t<=T;t++) {
        int N;
        cin >> N;
        int num = 0;
        for(int i = 0;i<N;i++) {
            if(i%2 == 0)
                for(int j=0;j<N;j++) {
                    cout << ++num <<" ";
                }
            else {
                num = num + N;
                int t = num;
                for(int j=0;j<N;j++) {
                    cout << t-- <<" ";
                }
            }
            cout << endl;
        }
    }
}