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


#define odd     0
#define even    1

int main() {
    int n,k;
    cin >> n >> k;

    map<int,int> Map;
    int x;
    
    for(int i = 0;i<n;i++) {
        cin >> x;
        Map.insert(make_pair(x,i));
    }
    

    int oddMax = -1;
    int evenMax = -1;
    int oddCnt = 0;
    int evenCnt = 0;
    int limit = k/2;

    vector<int> flags(n,-1);

    for(auto &e:Map) {
        int val = e.first;
        int pos = e.second;

        
        if(evenCnt >= oddCnt) {
            if(flags[pos - 1] != even and ( (pos+1) < n and (flags[pos + 1] != even))) {
                evenCnt++;
                evenMax = max(evenMax,val);
                flags[pos] = even;
            }else {
                oddCnt++;
                oddMax = max(oddMax,val);
                flags[pos] = odd;
            }
        }else {
            if(flags[pos - 1] != odd and ( (pos+1) < n and (flags[pos + 1] != odd))) {
                oddCnt++;
                oddMax = max(oddMax,val);
                flags[pos] = odd;
            }else {
                evenCnt++;
                evenMax = max(evenMax,val);
                flags[pos] = even;
            }                
        }
    

        if(evenCnt == limit) {
            cout << evenMax << endl;
            return 0;
        }
        if(oddCnt == limit) {
            cout << oddMax << endl;
            return 0;
        }
    }
}