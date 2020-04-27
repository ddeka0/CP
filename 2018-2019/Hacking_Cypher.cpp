#include <bits/stdc++.h>
using namespace std;
int l[10000001];
int r[10000001];
int main() {
    string str;
    int a,b;
    int n;
    cin >> str;
    cin >> a >> b;
    n = str.length();
    int tenmod = 10%a;
    int prev = 0;
    for(int i = 0;i<n;i++) {
        prev = ( ((prev * tenmod )%a) +  ((str[i] - '0')%a)  )%a;
       // cout <<i<<" "<<prev << endl;
        if(prev == 0)
                l[i] = true;
    }
    //for(int i = 0;i<=n;i++) {
    //    cout << l[i] << " ";
    //}
    //cout << endl;
    tenmod = 10%b;
    int tenprev = 1;
    prev = 0;
    for(int i = n-1;i>=0;i--) {
        if(str[i] != '0') {
            prev = ((( (str[i] - '0')%b  ) * tenprev)%b  + prev )%b;
            if(prev == 0)
                r[i] = true;
            }
            tenprev = (tenprev * tenmod)%b;
    }
    //cout << endl;
    //for(int i=0;i<=n;i++) {
    //    cout << r[i] <<" ";
   // }
    //cout << endl;
    bool ok = false;
    for(int i = 0;i<n-1;i++) {
        if(l[i] && r[i+1]) {
            cout << "YES" <<endl;
            cout << str.substr(0,i+1) << endl;
            cout << str.substr(i+1) << endl;
            ok = true;
            break;
        }
    }
    if(!ok) cout <<"NO"<<endl;
}
