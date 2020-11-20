#include <iostream>
using namespace std;
const long long Mod = 1000000007;
int main() {
    long long n,a,b;
    cin >> n;
    for(int i = 0;i<n;i++) {
        cin >> a >> b;
        long long res = 1;
        //a = a%Mod;
        while(b > 0) {
            if(b&1) {
                res = (res * a) % Mod;
            }
            a = (a * a) % Mod;
            b = b >> 1;
        }
        std::cout << res << std::endl;
    }
}