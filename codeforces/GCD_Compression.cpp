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


int main(){
    int t, n,x;
    cin >> t;
    while(t--){
        cin>>n;
        vector<int>odd;
        vector<int>even;

        for(int i=0; i<2*n; i++){
            cin>>x;
            if(x%2){
                odd.push_back(i+1);
            }
            else{
                even.push_back(i+1);
            }
        }
        int on =  odd.size();
        // on = on/2;
        if(on%2) on--;
        
        n--;

        //trace(on,n);
        
        for(int i=0; (i<(on)) and n > 0 ;i+=2){
            cout<<odd[i] << " "<<odd[i+1]<<endl;
            n--;
        }

        int en =  even.size();
        // en = en/2;

        if(en%2) en--;

        for(int i=0; (i<(en)) and n > 0 ;i+=2){
            cout<<even[i] << " "<<even[i+1]<<endl;
            n--;
        }
    }
}