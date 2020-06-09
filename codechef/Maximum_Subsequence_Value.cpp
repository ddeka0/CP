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
Assume Maximum subsequence size if 6
Numbers are A,B,C,D,E,F

Take any 3 element subset(X) from it -> B,C,D

Lets suppose ith bit is on in the optimal 6 element subsequence
=> ith bit will be on in the final Value of this optimal subsequence
=> Therefore minimum 4 elements must have ith bit on
=> if we try to select which 4 elemenets...we will end up selecting one element
from X. 
=> Therefore for each ith on bit in the final answer
=> that ith bit is also on in one of the number of X
=> Size of X is 3
=> Value(X) = A | B | C = Same optimal Value
*/
long long int a[501];
int main() {
    int n;
    cin >> n;
    for(int i = 0;i<n;i++) {
        cin >> a[i]; 
    }
    // take or of only 3 element sets
    // take max of them
    long long int ans = 0;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<i;j++) {
            for(int k = 0;k<j;k++) {
                ans = max(ans,(a[i] | a[j] | a[k]));
            }
        }
    }
    if(n<3) // take or of all the elements
        for(int i = 0;i<n;i++) {
            ans = ans | a[i];
        }
    cout << ans << endl;
}