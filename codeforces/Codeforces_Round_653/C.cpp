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
    int T,n;
    cin >> T;
    while(T--) {
        string s;
        cin >> n;
        cin >> s;
        // trace(T,n);
        stack<char> Stack;
        for(int i=0;i<n;i++) {
            if(s[i] == ')') {
                if(!Stack.empty()) {
                    if(Stack.top() == '(') {
                        Stack.pop();
                    }else {
                        Stack.push(s[i]);
                    }
                }else {
                    Stack.push(s[i]);
                }
            }else {
                Stack.push(s[i]);
            }
            //trace(T,s[i]);
        }
        cout << Stack.size()/2 << endl;
    }
}