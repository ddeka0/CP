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




/*
(x - y)^2 + (y - z)^2 + (z - x)^2

= (x - y)^2 + (y - z)^2 + (x - z)^2

*/

#define red     0
#define green   1
#define blue    2


int main() {
    int T;
    cin >> T;
    for(int t = 1;t<=T;t++) {
        int nr,ng,nb;
        vector<long long> colors[3];
        cin >> nr >> ng >> nb;

        colors[red].resize(nr+1);
        colors[green].resize(ng+1);
        colors[blue].resize(nb+1);
        
        for(int i = 0;i<nr;i++) cin >> colors[red][i];
        for(int i = 0;i<ng;i++) cin >> colors[green][i];
        for(int i = 0;i<nb;i++) cin >> colors[blue][i];
        
        sort(colors[red].begin(),colors[red].end());
        sort(colors[green].begin(),colors[green].end());
        sort(colors[blue].begin(),colors[blue].end());

        long long optimalAns = ULLONG_MAX;
        vector<int> v = {red,green,blue};
        do {
            
            // assume current order is red -> green -> blue
            // we will consider red <= green <= blue
            // for example selected red gen weight = 3
            // selected green gem weight = 4
            // selected blue gem weight = 8
            // we will fix middle one -> i.e. green gem weight and binary search
            // on red and blue weight vectors ...
            for(long long &y: colors[v[1]]) {

                auto xPos = lower_bound(colors[v[0]].begin(),colors[v[0]].end(),y) - colors[v[0]].begin();
                
                auto zPos = lower_bound(colors[v[2]].begin(),colors[v[2]].end(),y) - colors[v[2]].begin();
                
                if(xPos >= 0 and xPos < colors[v[0]].size()
                  and zPos >= 0 and zPos < colors[v[2]].size()) {
                        
                        long long xVal = (colors[v[0]][xPos] == y)?y:((xPos >=1)?colors[v[0]][xPos - 1]:-1); // xVal <= y
                        long long zVal = colors[v[2]][zPos]; // zVal >= y
                        if(xVal != -1)
                            optimalAns = min(optimalAns, (xVal - y)*(xVal - y) + 
                                            (y - zVal)*(y - zVal) + (xVal - zVal)*(xVal - zVal));
                }
            }
        }while(next_permutation(v.begin(), v.end()));
        
        cout << optimalAns << endl;
    }

}