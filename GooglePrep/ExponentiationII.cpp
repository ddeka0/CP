#include <iostream>
using namespace std;
int m = 1000000007;
int Mod;
int phi(int n) {
    int res = n;
    for(int i = 2; i * i <= n;i++) {
        if(n % i == 0) {
            while(n%i == 0) {
                n = n/i;
            }
            res = res - res/i;
        }
    }
    if(n > 1)
        res = res - res/n;
    return res;
}

int main() {
    long long n,a,b,c;
    cin >> n;
    for(int i = 0;i<n;i++) {
        cin >> a >> b >> c;
        Mod = phi(m);
        // first calculate b^c
        long long res = 1;
        b = b%Mod;
        while(c > 0) {
            if(c&1) {
                res = (res * b) % Mod;
            }
            b = (b * b) % Mod;
            c = c >> 1;
        }
        long long newPower = Mod + res;
        
        res = 1;
        a = a%Mod;
        while(newPower > 0) {
            if(newPower&1) {
                res = (res * a) % m;
            }
            a = (a * a) % m;
            newPower = newPower >> 1;
        }
        std::cout << res << std::endl;
    }
}