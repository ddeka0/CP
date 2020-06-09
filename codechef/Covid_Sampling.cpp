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
        int N,P;
        cin >> N >> P;
        int Sum[N+1];
        memset(Sum,0,sizeof(Sum));
        vector<vector<int>> outPut(N+1,vector<int>(N+1));
        // ask N^2 queires
        bool done = false;
        for(int i = 1;i<=N and !done;i++) {
            int this_row_sum = 0;
            for(int j = 1;j<=N and !done;j++) {
                int X;
                cout <<"1 1 1 "<<i<<" "<<j<<endl;
                cin >> X;
                if(X!= -1) {
                    int cellVal = X - Sum[j] - this_row_sum;
                    this_row_sum += cellVal;
                    Sum[j] = X;
                    outPut[i][j] = cellVal;
                } else {
                    done = true;
                } 
            }   
        } // Queries are done!!
        cout << 2 << endl;
        for(int i = 1;i<=N;i++) {
            for(int j = 1;j<=N;j++) {
                cout << outPut[i][j]<<" ";
            }
            cout << endl;
        }
        // ask for answer
        int answer;
        cin >> answer;
        if(answer == -1) return 0;
    }
}