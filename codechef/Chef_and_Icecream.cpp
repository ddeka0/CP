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
        vector<int> v(N);
        for(int i = 0;i<N;i++) {
            cin >> v[i];
        }
        int n_five = 0;
        int n_ten = 0;
        int n_fifteen = 0;
        bool ans = true;
        bool done = false;
        for(int i = 0;i<N and !done;i++) {
            n_five += (v[i] == 5);
            n_ten += (v[i] == 10);
            n_fifteen += (v[i] == 15);
            // if(v[i] == 5) continue;
            if(v[i] == 10) {
                if(n_five == 0) {
                    ans = false;
                    done = 1;
                }else {
                    n_five--;
                }
            }else if(v[i] == 15) {
                if((n_five * 5 + n_ten * 10) < 10) {
                    ans = false;
                    done = 1;
                }else {
                    if(n_ten>0) {
                        n_ten--;
                    }else {
                        n_five = n_five - 2;                        
                    }
                }
            }
        }
        cout << ((ans)?"YES":"NO") << endl;
    }
}