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

int a[200000 + 10];

int main() {
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++) {
        cin >> a[i];
    }
    map<long long int,long long int> Map;
    Map[0] = 0;
    int leftPtr = 0;
    long long int cs = 0;
    long long int ans = 0;
    // rule
    // if leftPtr = 3
    // and i is 10
    // then please take subarry from 10 -> to 4 only. Dont include 3
    for(int i = 1;i<=n;i++) {
        cs += a[i];
        // found is taken for actually found but pos is zero
        // for example 1,2,-3
        bool found = (Map.find(cs) != Map.end());
        // calculate pos = last index of cs (summulative sum)
        int pos = found?Map[cs]:0;
        // therefore we must not touch pos
        // for example : Cummulative sum array = [1,2,3,4... : (index from 1)
        // Here  new Cummulative sum is 2 for example
        // we found pos = Map[2] = 1 and new Cummulative array = [1,2,3,4,2...]
        // Therefore from index 5, we can include only upto index 3.
        

        // update leftPtr also 
        // calculation is based on leftPtr only
        leftPtr = max(pos,leftPtr);
        
        
        if(found and (pos == leftPtr)) {
            // when we factually ind a prev same cummulative sum cs
            // and also found that pos == leftPtr
            // since pos must not be included 
            // we increment leftPtr 
            leftPtr++;
        }
        //trace(pos,leftPtr);
        if(a[i]) {
            // for example
            // leftPtr = 2 [=> Do not include 2]
            // i = 5
            // therefore [5],[4,5],[3,4,5] only
            // -> 5 - 2
            ans += 1LL*(i - leftPtr);
        }

        if(a[i] == 0) {
            // ith is zero
            // Do not include ith in future 
            leftPtr = i;
        }
        Map[cs] = i;
        //trace(i,Map[cs],leftPtr,ans);
    }
    cout << ans << endl;
}